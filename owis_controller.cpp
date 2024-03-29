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
#include <windows.h>

OWIS_controller::OWIS_controller(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OWIS_controller)
{
    std::cout<<"ok!! "<<std::endl;
    ui->setupUi(this);

 QJoysticks* J_instance = QJoysticks::getInstance();

    QTimer *timer = new QTimer(this);
    QTimer *timerJoy = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(updatePositions_X()));
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePositions_Y()));
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePositions_Z()));
    connect(timerJoy, SIGNAL(timeout()), this, SLOT(runRealJoy()));
    timer->start(100);
    timerJoy->start(10);


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

 connect(ui->enableRealJoy, SIGNAL(toggled(bool)), this, SLOT(enableRealJoyClicked(bool)));

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

if (realJoyConnect != 1)
    return;
   
  const double threshold = 0.05;
    if(index != 0 )
        return; //I want only the main joystick to work

    ui->joyAxis->setText(QString::number(axis));
    ui->joyValue->setText(QString::number(value));


if (X_stage_on ==true)
{
 if(axis == 0 && (value > threshold) && joy_state_X == 0 )
    {  
        joy_state_X=1;
    }
    else if(axis == 0 && (value < -threshold) && joy_state_X == 0 )
    {
        joy_state_X=-1;
    }
    else if(axis == 0 && (value < threshold) && (value > -threshold)  && ((joy_state_X == 1) || (joy_state_X == -1)))
    {   
        joy_state_X=0;
    }
}

if (Y_stage_on == true)
{
    ui->label_neg_Y->setText("off");
    ui->label_pos_Y->setText("off");

if(axis == 1 && (value > threshold)  && joy_state_Y == 0)
    {
joy_state_Y=1;
    }
    else if(axis == 1 && (value < -threshold) && joy_state_Y == 0)
    {
joy_state_Y=-1;
    }
    else if((axis == 1 ) && (value < threshold) && (value > -threshold) && ((joy_state_Y == 1) || (joy_state_Y == -1)))
    { 
joy_state_Y=0;
    }
}

if (Z_stage_on == true)
{
   if(axis == 2 && (value > threshold)  && joy_state_Z == 0)
    {
joy_state_Z=1;
    }
    else if(axis == 2 && (value < -threshold) && joy_state_Z == 0)
    {
joy_state_Z=-1;
    }
    else if((axis == 2 ) && (value < threshold) && (value > -threshold) && ((joy_state_Z == 1) || (joy_state_Z == -1)))
    { 
joy_state_Z=0;
    }
}
}

//if(axis == 0 && (value > threshold) )
//    {
    
//        ui->label_pos_X->setText("on");
//    }
//    else if(axis == 0 && (value < -threshold) )
//    {
    
//        ui->label_neg_X->setText("on");
//    }
//    else if(axis == 0 && ((value < threshold) || (value > -threshold)) )
//    {
    
//        ui->label_neg_X->setText("off");
//        ui->label_pos_X->setText("off");
//    }


//if(axis == 1 && (value > threshold))
//    {
    
//        ui->label_pos_Y->setText("on");
//    }
//    else if(axis == 1 && (value < -threshold))
//    {

//        ui->label_neg_Y->setText("on");
//    }
//    else if(((value < threshold) || (value > -threshold)))
//    {
    
//        ui->label_neg_Y->setText("off");
//        ui->label_pos_Y->setText("off");
//    }



//   if(axis == 2 && (value > threshold) && move_state_Z == 0)
//        {

//        ui->label_pos_Z->setText("on");
//    }
//    else if(axis == 2 && (value < -threshold) && move_state_Z == 0)
//        {
//        ui->label_neg_Z->setText("on");
//    }
//    else if(axis == 2 && ((value < threshold) || (value > -threshold)))
//     {
//        ui->label_neg_Z->setText("off");
//        ui->label_pos_Z->setText("off");
//    }



void OWIS_controller::enableRealJoyClicked(bool clicked)

{
if ((clicked) && (PS90_connected)) realJoyConnect=1;
else realJoyConnect=0;
}

void 

OWIS_controller::runRealJoy()

{
if (realJoyConnect != 1)
    return;

realJoy_X();
realJoy_Y();
realJoy_Z();

}





