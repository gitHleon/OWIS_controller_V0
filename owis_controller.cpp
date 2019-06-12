#include "owis_controller.h"
#include "ui_owis_controller.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include "x86\ps90.h"
#include <QTimer>
#include <iostream>

OWIS_controller::OWIS_controller(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OWIS_controller)
{
    std::cout<<"ok!! "<<std::endl;
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePositions()));
    timer->start(100);
}

OWIS_controller::~OWIS_controller()
{
    delete ui;
}


void OWIS_controller::on_InitPS90Button_clicked()
{
    //See example code and LabView functions
    if (PS90_Connect(Index, 0, 1, 9600, 0, 0, 8, 0) != 0 ){
        QMessageBox::critical(this, tr("Error"), tr("Could not connect to PS90!!"));
        //        QCoreApplication::quit();
    } else {

        PS90_connected = true;
        // turning on Axes - following scheme of LabView function -
        // The tool example code is slightly different



        //X Axis : 1

        long error = PS90_SetMotorType(1,1,0);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetMotorType X Axis")); }

        error = PS90_SetLimitSwitch(1,1,15);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetLimitSwitch X Axis")); }

        error = PS90_SetLimitSwitchMode(1,1,15);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetLimitSwitchMode X Axis")); }

        error = PS90_SetRefSwitch(1,1,2);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetRefSwitch X Axis")); }

        error = PS90_SetRefSwitchMode(1,1,15);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in SetRefSwitchMode X Axis")); }

        error = PS90_SetSampleTime(1,1,256);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in SetSampleTime X Axis")); }

        error = PS90_SetKP(1,1,25);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetKP X Axis")); }

        error =  PS90_SetKI(1,1,25);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetKI X Axis")); }

        error =  PS90_SetKD(1,1,50);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetKD X Axis")); }

        error =  PS90_SetDTime(1,1,0);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetDTime X Axis")); }

        error =  PS90_SetILimit(1,1,5000000);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetILimit X Axis")); }

        error =  PS90_SetTargetWindow(1,1,500);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetTargetWindow X Axis")); }

        error =  PS90_SetInPosMode(1,1,0);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetInPosMode X Axis")); }

        error =  PS90_SetCurrentLevel(1,1,1);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in SetCurrentLevel X Axis")); }

        error =  PS90_SetStageAttributes(1,1,1.0,50000,1);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetStageAttributes X Axis")); }

        error =  PS90_SetMsysResol(1,1,0.0001);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetMsysResol X Axis")); }

        error = PS90_SetTargetMode(1,1,0);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetTargetMode X Axis")); }
        ui->label_axis_target_mode_X->setText("X Axis Target mode : Relative");

        double value = PS90_GetPositionEx(Index,Axisid_X);
        error = PS90_GetReadError(Index);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetPositionEx X Axis")); }
        ui->lineEdit_axis_pos_X->setText(QString::number(value));

        ui->lineEdit_Target_value_X->setText(QString::number(0));

        error = PS90_MotorInit(Index,Axisid_X);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_MotorInit X Axis - need to add specification!!")); }


//        long mode  = PS90_GetTargetMode(Index,Axisid_X);
//         error = PS90_GetReadError(Index);


//        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetTargetMode X Axis - need to add specification!!")); }
//        if(mode  == 0)
//            ui->label_axis_target_mode_X->setText("X Axis Target mode : Relative");
//        else
//            ui->label_axis_target_mode_X->setText("X Axis Target mode : Absolute");
        //it is possible to have the ps90 calculate the distance in the selected unit via the function GetTargetEx
//        error = PS90_SetCalcResol(Index,Axisid_X,0.0005);
//        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetCalcResol X Axis - need to add specification!!")); }

//        double value = PS90_GetTargetEx(Index,Axisid_X);
//        error = PS90_GetReadError(Index);
//        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetTargetEx X Axis - need to add specification!!")); }
//        ui->lineEdit_Target_value_X->setText(QString::number(value));
//        error = PS90_MotorInit(Index,Axisid_X);
//        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_MotorInit X Axis - need to add specification!!")); }

//        error = PS90_GoRef (Index,Axisid_X,4);
//        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GoRef X Axis - need to add specification!!")); }






        //Y Axis : 3
        long mode  = PS90_GetTargetMode(Index,Axisid_Y);
        error = PS90_GetReadError(Index);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetTargetMode Y Axis - need to add specification!!")); }
        if(mode  == 0)
            ui->label_axis_target_mode_Y->setText("Y Axis Target mode : Relative");
        else
            ui->label_axis_target_mode_Y->setText("Y Axis Target mode : Absolute");
        //it is possible to have the ps90 calculate the distance in the selected unit via the function GetTargetEx
        error = PS90_SetCalcResol(Index,Axisid_Y,0.0005);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetCalcResol Y Axis - need to add specification!!")); }

        value = PS90_GetTargetEx(Index,Axisid_Y);
        error = PS90_GetReadError(Index);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetTargetEx Y Axis - need to add specification!!")); }
        ui->lineEdit_Target_value_Y->setText(QString::number(value));
        error = PS90_MotorInit(Index,Axisid_Y);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_MotorInit Y Axis - need to add specification!!")); }
        error = PS90_GoRef (Index,Axisid_Y,4);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GoRef Y Axis - need to add specification!!")); }





        //Z Axis : 2
        mode  = PS90_GetTargetMode(Index,Axisid_Z);
        error = PS90_GetReadError(Index);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetTargetMode Z Axis - need to add specification!!")); }
        if(mode  == 0)
            ui->label_axis_target_mode_Z->setText("Z Axis Target mode : Relative");
        else
            ui->label_axis_target_mode_Z->setText("Z Axis Target mode : Absolute");
        //it is possible to have the ps90 calculate the distance in the selected unit via the function GetTargetEx
        error = PS90_SetCalcResol(Index,Axisid_Z,0.0005);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetCalcResol Z Axis - need to add specification!!")); }

        value = PS90_GetTargetEx(Index,Axisid_Z);
        error = PS90_GetReadError(Index);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetTargetEx Z Axis - need to add specification!!")); }
        ui->lineEdit_Target_value_Z->setText(QString::number(value));
        error = PS90_MotorInit(Index,Axisid_Z);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_MotorInit Z Axis - need to add specification!!")); }
        error = PS90_GoRef (Index,Axisid_Z,4);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GoRef Z Axis - need to add specification!!")); }




    }
    //setting values for doublespinbox
    ui->doubleSpinBox_newTarget_value_X->setDecimals(2);
    ui->doubleSpinBox_newTarget_value_X->setMaximum(5000);
    ui->doubleSpinBox_newTarget_value_X->setMinimum(0.01);
    ui->doubleSpinBox_newTarget_value_X->setSingleStep(0.01);
    ui->doubleSpinBox_newTarget_value_X->setValue(1.0);

    ui->doubleSpinBox_newTarget_value_Y->setDecimals(2);
    ui->doubleSpinBox_newTarget_value_Y->setMaximum(5000);
    ui->doubleSpinBox_newTarget_value_Y->setMinimum(0.01);
    ui->doubleSpinBox_newTarget_value_Y->setSingleStep(0.01);
    ui->doubleSpinBox_newTarget_value_Y->setValue(1.0);

    ui->doubleSpinBox_newTarget_value_Z->setDecimals(2);
    ui->doubleSpinBox_newTarget_value_Z->setMaximum(5000);
    ui->doubleSpinBox_newTarget_value_Z->setMinimum(0.01);
    ui->doubleSpinBox_newTarget_value_Z->setSingleStep(0.01);
    ui->doubleSpinBox_newTarget_value_Z->setValue(1.0);

}


void OWIS_controller::updatePositions()
{
    if(!PS90_connected)
        return;


    //X Axis : 1
    long mode  = PS90_GetTargetMode(Index,Axisid_X );
    long error = PS90_GetReadError(Index);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetTargetMode X Axis  - need to add specification!!")); }
    if(mode  == 0)
        ui->label_axis_target_mode_X->setText("Target mode "+ QString::number(mode) + " : Relative" );
    else
        ui->label_axis_target_mode_X->setText("Target mode "+ QString::number(mode) + " : Absolute");

    double Tvalue = PS90_GetTargetEx(Index,Axisid_X);
    error = PS90_GetReadError(Index);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetTargetEx X Axis - need to add specification!!")); }
    ui->lineEdit_Target_value_X->setText(QString::number(Tvalue));

    double value = PS90_GetPositionEx (Index,Axisid_X);
    error = PS90_GetReadError(Index);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetPositionEx X Axis - need to add specification!!")); }
    ui->lineEdit_axis_pos_X->setText(QString::number(value));

    long move_state = PS90_GetMoveState(Index,Axisid_X);
    error = PS90_GetReadError(Index);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetMoveState X Axis - need to add specification!!")); }

    if(move_state != 0)
        ui->label_axis_movement_X->setText(" X Axis is moving!!!");
    else
        ui->label_axis_movement_X->setText(" X Axis still");





    //Y Axis : 3
    mode  = PS90_GetTargetMode(Index,Axisid_Y );
    error = PS90_GetReadError(Index);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetTargetMode_Y_Axis  - need to add specification!!")); }
    if(mode  == 0)
        ui->label_axis_target_mode_Y->setText("Target mode "+ QString::number(mode) + " : Relative" );
    else
        ui->label_axis_target_mode_Y->setText("Target mode "+ QString::number(mode) + " : Absolute");

    Tvalue = PS90_GetTargetEx(Index,Axisid_Y);
    error = PS90_GetReadError(Index);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetTargetEx Y Axis - need to add specification!!")); }
    ui->lineEdit_Target_value_Y->setText(QString::number(Tvalue));

    value = PS90_GetPositionEx (Index,Axisid_Y);
    error = PS90_GetReadError(Index);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetPositionEx Y Axis - need to add specification!!")); }
    ui->lineEdit_axis_pos_Y->setText(QString::number(value));

    move_state = PS90_GetMoveState(Index,Axisid_Y);
    error = PS90_GetReadError(Index);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetMoveState Y Axis - need to add specification!!")); }

    if(move_state != 0)
        ui->label_axis_movement_Y->setText(" Y Axis is moving!!!");
    else
        ui->label_axis_movement_Y->setText(" Y Axis still");






    //Z Axis : 2
    mode  = PS90_GetTargetMode(Index,Axisid_Z );
    error = PS90_GetReadError(Index);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetTargetMode Z Axis  - need to add specification!!")); }
    if(mode  == 0)
        ui->label_axis_target_mode_Z->setText("Target mode "+ QString::number(mode) + " : Relative" );
    else
        ui->label_axis_target_mode_Z->setText("Target mode "+ QString::number(mode) + " : Absolute");

    Tvalue = PS90_GetTargetEx(Index,Axisid_Z);
    error = PS90_GetReadError(Index);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetTargetEx Z Axis - need to add specification!!")); }
    ui->lineEdit_Target_value_Z->setText(QString::number(Tvalue));

    value = PS90_GetPositionEx (Index,Axisid_Z);
    error = PS90_GetReadError(Index);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetPositionEx Z Axis - need to add specification!!")); }
    ui->lineEdit_axis_pos_Z->setText(QString::number(value));

    move_state = PS90_GetMoveState(Index,Axisid_Z);
    error = PS90_GetReadError(Index);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetMoveState Z Axis - need to add specification!!")); }

    if(move_state != 0)
        ui->label_axis_movement_Z->setText(" Z Axis is moving!!!");
    else
        ui->label_axis_movement_Z->setText(" Z Axis still");

}


void OWIS_controller::on_stopButton_clicked()
{
    if(!PS90_connected)
        return;
    long error [3] = {0,0,0};
    error[0] = PS90_Stop(Index,Axisid_X);
    error[1] = PS90_Stop(Index,Axisid_Y);
    error[2] = PS90_Stop(Index,Axisid_Z);
    if (error[0] != 0 || error[1] != 0 ||error[2] != 0){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_Stop Z Axis- need to add specification!!")); }
}


void OWIS_controller::on_switchModeButton_X_clicked()
{
    if(!PS90_connected)
        return;
    long mode  = PS90_GetTargetMode(Index,Axisid_X);
    long error = PS90_GetReadError(Index);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetTargetMode X Axis - need to add specification!!")); }
    if(mode  == 0)
        error = PS90_SetTargetMode(Index,Axisid_X,1);
    else
        error = PS90_SetTargetMode(Index,Axisid_X,0);
}



void OWIS_controller::on_switchModeButton_Y_clicked()
{
    if(!PS90_connected)
        return;
    long mode  = PS90_GetTargetMode(Index,Axisid_Y);
    long error = PS90_GetReadError(Index);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetTargetMode Y Axis - need to add specification!!")); }
    if(mode  == 0)
        error = PS90_SetTargetMode(Index,Axisid_Y,1);
    else
        error = PS90_SetTargetMode(Index,Axisid_Y,0);
}



void OWIS_controller::on_switchModeButton_Z_clicked()
{
    if(!PS90_connected)
        return;
    long mode  = PS90_GetTargetMode(Index,Axisid_Z);
    long error = PS90_GetReadError(Index);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetTargetMode Z Axis - need to add specification!!")); }
    if(mode  == 0)
        error = PS90_SetTargetMode(Index,Axisid_Z,1);
    else
        error = PS90_SetTargetMode(Index,Axisid_Z,0);
}


void OWIS_controller::on_moveAxisButton_X_clicked()
{
    if(!PS90_connected)
        return;
    double Tvalue = ui->doubleSpinBox_newTarget_value_X->value();
    long error = PS90_MoveEx(Index,Axisid_X,Tvalue,1);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_MoveEx X Axis- need to add specification!!")); }
}



void OWIS_controller::on_moveAxisButton_Y_clicked()
{
    if(!PS90_connected)
        return;
    double Tvalue = ui->doubleSpinBox_newTarget_value_Y->value();
    long error = PS90_MoveEx(Index,Axisid_Y,Tvalue,1);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_MoveEx Y Axis- need to add specification!!")); }
}



void OWIS_controller::on_moveAxisButton_Z_clicked()
{
    if(!PS90_connected)
        return;
    double Tvalue = ui->doubleSpinBox_newTarget_value_Z->value();
    long error = PS90_MoveEx(Index,Axisid_Z,Tvalue,1);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_MoveEx Z Axis- need to add specification!!")); }
}




