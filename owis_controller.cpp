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

OWIS_controller::OWIS_controller(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OWIS_controller)
{
    std::cout<<"ok!! "<<std::endl;
    ui->setupUi(this);

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

}

OWIS_controller::~OWIS_controller()
{
    delete ui;
}
