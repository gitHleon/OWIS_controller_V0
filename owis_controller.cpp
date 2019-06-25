#include "owis_controller.h"
#include "ui_owis_controller.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include "x86\ps90.h"
#include <QTimer>
#include <iostream>
#include <QPushButton>
#include <QJoysticks.h>

OWIS_controller::OWIS_controller(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OWIS_controller)
{
    std::cout<<"ok!! "<<std::endl;
    ui->setupUi(this);

 QJoysticks* J_instance = QJoysticks::getInstance();

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePositions_X()));
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePositions_Y()));
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePositions_Z()));
    timer->start(100);

ui->label_PS90_general_status->setText("PS90 Status: Disconnected");


ui->label_stage_state_X->setText("X Stage: Off");
ui->label_stage_state_Y->setText("Y Stage: Off");
ui->label_stage_state_Z->setText("Z Stage: Off");

 connect(ui->joyNegButton_X, SIGNAL(pressed()), this, SLOT(virtualJoy_X()));
 connect(ui->joyPosButton_X, SIGNAL(pressed()), this, SLOT(virtualJoy_X()));
 connect(ui->joyNegButton_X, &QPushButton::released, this, &OWIS_controller::stopX);
 connect(ui->joyPosButton_X, &QPushButton::released, this, &OWIS_controller::stopX);
 connect(ui->joyNegButton_Y, SIGNAL(pressed()), this, SLOT(virtualJoy_Y()));
 connect(ui->joyPosButton_Y, SIGNAL(pressed()), this, SLOT(virtualJoy_Y()));
 connect(ui->joyNegButton_Y, &QPushButton::released, this, &OWIS_controller::stopY);
 connect(ui->joyPosButton_Y, &QPushButton::released, this, &OWIS_controller::stopY);
 connect(ui->joyNegButton_Z, SIGNAL(pressed()), this, SLOT(virtualJoy_Z()));
 connect(ui->joyPosButton_Z, SIGNAL(pressed()), this, SLOT(virtualJoy_Z()));
 connect(ui->joyNegButton_Z, &QPushButton::released, this, &OWIS_controller::stopZ);
 connect(ui->joyPosButton_Z, &QPushButton::released, this, &OWIS_controller::stopZ);

// conexión con el Joystick //

    int J_number = J_instance->count();
    std::cout<<" J_numebr :"<<J_number<<std::endl;
    QStringList J_list = J_instance->deviceNames();
    J_number = J_list.size();
    std::cout<<" J_size :"<<J_number<<std::endl;
    int J_buttons = J_instance->getNumButtons(0);
    std::cout<<" J_buttons :"<<J_buttons<<std::endl;
    //connect(J_instance,SIGNAL(buttonChanged(int,int,bool)), this, SLOT(J_translator(int,int,bool)));
    connect(J_instance,SIGNAL(axisChanged(int,int,double)), this, SLOT(J_axes_translator(int,int,double)));
    //connect(this,SIGNAL(Run_focus_signal()), this, SLOT(createTemplate_F()));


}

OWIS_controller::~OWIS_controller()
{
    delete ui;
}


void OWIS_controller::J_axes_translator(int index, int axis, double value)
{
    const double threshold = 0.15;
    if(index != 0 )
        return; //I want only the main joystick to work
    if(axis == 0 && (value > threshold))
        runX(+1);
    else if(axis == 0 && (value < -threshold))
        runX(-1);
    else if(axis == 0 && ((value < threshold) || (value > -threshold)))
        stopX();
    else if(axis == 1 && (value > threshold))
        runY(+1);
    else if(axis == 1 && (value < -threshold))
        runY(-1);
    else if(axis == 1 && ((value < threshold) || (value > -threshold)))
        stopY();
    else if(axis == 2 && (value > threshold))
        runZ(+1);
    else if(axis == 2 && (value < -threshold))
        runZ(-1);
    else if(axis == 2 && ((value < threshold) || (value > -threshold)))
        stopZ();


}
