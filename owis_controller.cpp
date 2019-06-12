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
    if (PS90_Connect(Index, 0, 3, 9600, 0, 0, 8, 0) != 0 ){
        QMessageBox::critical(this, tr("Error"), tr("Could not connect to PS90!!"));
        //        QCoreApplication::quit();
    } else {

        PS90_connected = true;
        // turning on Axes - following scheme of LabView function -
        // The tool example code is slightly different



        //X Axis : 1

        long error = PS90_SetMotorType(Index,Axisid_X,motor_type[0]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetMotorType X Axis")); }

        error = PS90_SetLimitSwitch(Index,Axisid_X,limit_switch[0]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetLimitSwitch X Axis")); }

        error = PS90_SetLimitSwitchMode(Index,Axisid_X,limit_switch_mode[0]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetLimitSwitchMode X Axis")); }

        error = PS90_SetRefSwitch(Index,Axisid_X,ref_switch[0]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetRefSwitch X Axis")); }

        error = PS90_SetRefSwitchMode(Index,Axisid_X,ref_switch_mode[0]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in SetRefSwitchMode X Axis")); }

        error = PS90_SetSampleTime(Index,Axisid_X,sample_time[0]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in SetSampleTime X Axis")); }

        error = PS90_SetKP(Index,Axisid_X,KP[0]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetKP X Axis")); }

        error =  PS90_SetKI(Index,Axisid_X,KI[0]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetKI X Axis")); }

        error =  PS90_SetKD(Index,Axisid_X,KD[0]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetKD X Axis")); }

        error =  PS90_SetDTime(Index,Axisid_X,DTime[0]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetDTime X Axis")); }

        error =  PS90_SetILimit(Index,Axisid_X,ILimit[0]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetILimit X Axis")); }

        error =  PS90_SetTargetWindow(Index,Axisid_X,target_window[0]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetTargetWindow X Axis")); }

        error =  PS90_SetInPosMode(Index,Axisid_X,pos_mode[0]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetInPosMode X Axis")); }

        error =  PS90_SetCurrentLevel(Index,Axisid_X,current_level[0]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in SetCurrentLevel X Axis")); }

        error =  PS90_SetStageAttributes(Index,Axisid_X,pitch[0],increments_per_rev[0],gear_reduction_ratio[0]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetStageAttributes X Axis")); }

        error =  PS90_SetMsysResol(Index,Axisid_X,lin_res[0]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetMsysResol X Axis")); }

        error = PS90_SetTargetMode(Index,Axisid_X,ini_target_mode[0]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetTargetMode X Axis")); }
        ui->label_axis_target_mode_X->setText("X Axis Target mode : Relative");

        error =  PS90_SetAccel(Index,Axisid_X,acc[0]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetAccel X Axis")); }

        error =  PS90_SetDecel(Index,Axisid_X,dacc[0]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetDecel X Axis")); }

        error =   PS90_SetJerk(Index,Axisid_X,jacc[0]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetJerk X Axis")); }

        error =   PS90_SetRefDecel(Index,Axisid_X,ref_dacc[0]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetRefDecel X Axis")); }

        error =   PS90_SetVel(Index,Axisid_X,vel[0]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetVel X Axis")); }

         error =   PS90_SetPosVel(Index,Axisid_X,pos_vel[0]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetPosVel X Axis")); }

         error =   PS90_SetSlowRefVel(Index,Axisid_X,ref_vel_slow[0]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetSlowRefVel X Axis")); }

        error =   PS90_SetFastRefVel(Index,Axisid_X,ref_vel_fast[0]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetFastRefVel X Axis")); }

        error =   PS90_SetFreeVel(Index,Axisid_X,free_vel[0]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetFreeVel X Axis")); }


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






        //Y Axis : 2




        error = PS90_SetMotorType(Index,Axisid_Y,motor_type[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetMotorType X Axis")); }

        error = PS90_SetLimitSwitch(Index,Axisid_Y,limit_switch[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetLimitSwitch X Axis")); }

        error = PS90_SetLimitSwitchMode(Index,Axisid_Y,limit_switch_mode[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetLimitSwitchMode X Axis")); }

        error = PS90_SetRefSwitch(Index,Axisid_Y,ref_switch[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetRefSwitch X Axis")); }

        error = PS90_SetRefSwitchMode(Index,Axisid_Y,ref_switch_mode[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in SetRefSwitchMode X Axis")); }

        error = PS90_SetSampleTime(Index,Axisid_Y,sample_time[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in SetSampleTime X Axis")); }

        error = PS90_SetKP(Index,Axisid_Y,KP[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetKP X Axis")); }

        error =  PS90_SetKI(Index,Axisid_Y,KI[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetKI X Axis")); }

        error =  PS90_SetKD(Index,Axisid_Y,KD[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetKD X Axis")); }

        error =  PS90_SetDTime(Index,Axisid_Y,DTime[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetDTime X Axis")); }

        error =  PS90_SetILimit(Index,Axisid_Y,ILimit[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetILimit X Axis")); }

        error =  PS90_SetTargetWindow(Index,Axisid_Y,target_window[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetTargetWindow X Axis")); }

        error =  PS90_SetInPosMode(Index,Axisid_Y,pos_mode[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetInPosMode X Axis")); }

        error =  PS90_SetCurrentLevel(Index,Axisid_Y,current_level[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in SetCurrentLevel X Axis")); }

        error =  PS90_SetStageAttributes(Index,Axisid_Y,pitch[1],increments_per_rev[1],gear_reduction_ratio[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetStageAttributes X Axis")); }

        error =  PS90_SetMsysResol(Index,Axisid_Y,lin_res[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetMsysResol X Axis")); }

        error = PS90_SetTargetMode(Index,Axisid_Y,ini_target_mode[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetTargetMode X Axis")); }
        ui->label_axis_target_mode_X->setText("X Axis Target mode : Relative");

        error =  PS90_SetAccel(Index,Axisid_Y,acc[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetAccel X Axis")); }

        error =  PS90_SetDecel(Index,Axisid_Y,dacc[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetDecel X Axis")); }

        error =   PS90_SetJerk(Index,Axisid_Y,jacc[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetJerk X Axis")); }

        error =   PS90_SetRefDecel(Index,Axisid_Y,ref_dacc[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetRefDecel X Axis")); }

        error =   PS90_SetVel(Index,Axisid_Y,vel[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetVel X Axis")); }

         error =   PS90_SetPosVel(Index,Axisid_Y,pos_vel[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetPosVel X Axis")); }

         error =   PS90_SetSlowRefVel(Index,Axisid_Y,ref_vel_slow[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetSlowRefVel X Axis")); }

        error =   PS90_SetFastRefVel(Index,Axisid_Y,ref_vel_fast[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetFastRefVel X Axis")); }

        error =   PS90_SetFreeVel(Index,Axisid_Y,free_vel[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetFreeVel X Axis")); }


        value = PS90_GetPositionEx(Index,Axisid_Y);
        error = PS90_GetReadError(Index);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetPositionEx X Axis")); }
        ui->lineEdit_axis_pos_Y->setText(QString::number(value));

        ui->lineEdit_Target_value_Y->setText(QString::number(0));

        error = PS90_MotorInit(Index,Axisid_Y);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_MotorInit X Axis - need to add specification!!")); }


 //       long mode  = PS90_GetTargetMode(Index,Axisid_Y);
 //       error = PS90_GetReadError(Index);
 //       if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetTargetMode Y Axis - need to add specification!!")); }
 //       if(mode  == 0)
 //           ui->label_axis_target_mode_Y->setText("Y Axis Target mode : Relative");
 //       else
 //           ui->label_axis_target_mode_Y->setText("Y Axis Target mode : Absolute");
 //       //it is possible to have the ps90 calculate the distance in the selected unit via the function GetTargetEx
 //       error = PS90_SetCalcResol(Index,Axisid_Y,0.0005);
 //       if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetCalcResol Y Axis - need to add specification!!")); }
//
//        value = PS90_GetTargetEx(Index,Axisid_Y);
//        error = PS90_GetReadError(Index);
//        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetTargetEx Y Axis - need to add specification!!")); }
//       ui->lineEdit_Target_value_Y->setText(QString::number(value));
//       error = PS90_MotorInit(Index,Axisid_Y);
 //       if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_MotorInit Y Axis - need to add specification!!")); }
//        error = PS90_GoRef (Index,Axisid_Y,4);
//        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GoRef Y Axis - need to add specification!!")); }


        //Z Axis : 3



        error = PS90_SetMotorType(Index,Axisid_Z,motor_type[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetMotorType X Axis")); }

        error = PS90_SetLimitSwitch(Index,Axisid_Z,limit_switch[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetLimitSwitch X Axis")); }

        error = PS90_SetLimitSwitchMode(Index,Axisid_Z,limit_switch_mode[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetLimitSwitchMode X Axis")); }

        error = PS90_SetRefSwitch(Index,Axisid_Z,ref_switch[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetRefSwitch X Axis")); }

        error = PS90_SetRefSwitchMode(Index,Axisid_Z,ref_switch_mode[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in SetRefSwitchMode X Axis")); }

        error = PS90_SetSampleTime(Index,Axisid_Z,sample_time[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in SetSampleTime X Axis")); }

        error = PS90_SetKP(Index,Axisid_Z,KP[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetKP X Axis")); }

        error =  PS90_SetKI(Index,Axisid_Z,KI[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetKI X Axis")); }

        error =  PS90_SetKD(Index,Axisid_Z,KD[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetKD X Axis")); }

        error =  PS90_SetDTime(Index,Axisid_Z,DTime[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetDTime X Axis")); }

        error =  PS90_SetILimit(Index,Axisid_Z,ILimit[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetILimit X Axis")); }

        error =  PS90_SetTargetWindow(Index,Axisid_Z,target_window[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetTargetWindow X Axis")); }

        error =  PS90_SetInPosMode(Index,Axisid_Z,pos_mode[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetInPosMode X Axis")); }

        error =  PS90_SetCurrentLevel(Index,Axisid_Z,current_level[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in SetCurrentLevel X Axis")); }

        error =  PS90_SetStageAttributes(Index,Axisid_Z,pitch[2],increments_per_rev[2],gear_reduction_ratio[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetStageAttributes X Axis")); }

        error =  PS90_SetMsysResol(Index,Axisid_Z,lin_res[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetMsysResol X Axis")); }

        error = PS90_SetTargetMode(Index,Axisid_Z,ini_target_mode[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetTargetMode X Axis")); }
        ui->label_axis_target_mode_X->setText("X Axis Target mode : Relative");

        error =  PS90_SetAccel(Index,Axisid_Z,acc[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetAccel X Axis")); }

        error =  PS90_SetDecel(Index,Axisid_Z,dacc[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetDecel X Axis")); }

        error =   PS90_SetJerk(Index,Axisid_Z,jacc[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetJerk X Axis")); }

        error =   PS90_SetRefDecel(Index,Axisid_Z,ref_dacc[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetRefDecel X Axis")); }

        error =   PS90_SetVel(Index,Axisid_Z,vel[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetVel X Axis")); }

         error =   PS90_SetPosVel(Index,Axisid_Z,pos_vel[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetPosVel X Axis")); }

         error =   PS90_SetSlowRefVel(Index,Axisid_Z,ref_vel_slow[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetSlowRefVel X Axis")); }

        error =   PS90_SetFastRefVel(Index,Axisid_Z,ref_vel_fast[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetFastRefVel X Axis")); }

        error =   PS90_SetFreeVel(Index,Axisid_Z,free_vel[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetFreeVel X Axis")); }


        value = PS90_GetPositionEx(Index,Axisid_Z);
        error = PS90_GetReadError(Index);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetPositionEx X Axis")); }
        ui->lineEdit_axis_pos_Z->setText(QString::number(value));

        ui->lineEdit_Target_value_Z->setText(QString::number(0));

        error = PS90_MotorInit(Index,Axisid_Z);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_MotorInit X Axis - need to add specification!!")); }



//        mode  = PS90_GetTargetMode(Index,Axisid_Z);
//        error = PS90_GetReadError(Index);
//        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetTargetMode Z Axis - need to add specification!!")); }
//        if(mode  == 0)
//            ui->label_axis_target_mode_Z->setText("Z Axis Target mode : Relative");
//        else
//            ui->label_axis_target_mode_Z->setText("Z Axis Target mode : Absolute");
//        //it is possible to have the ps90 calculate the distance in the selected unit via the function GetTargetEx
//        error = PS90_SetCalcResol(Index,Axisid_Z,0.0005);
//        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetCalcResol Z Axis - need to add specification!!")); }
//
//        value = PS90_GetTargetEx(Index,Axisid_Z);
//        error = PS90_GetReadError(Index);
//        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetTargetEx Z Axis - need to add specification!!")); }
//        ui->lineEdit_Target_value_Z->setText(QString::number(value));
//        error = PS90_MotorInit(Index,Axisid_Z);
//        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_MotorInit Z Axis - need to add specification!!")); }
//        error = PS90_GoRef (Index,Axisid_Z,4);
//        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GoRef Z Axis - need to add specification!!")); }




    }
    //setting values for doublespinbox
    ui->doubleSpinBox_newTarget_value_X->setDecimals(2);
    ui->doubleSpinBox_newTarget_value_X->setMaximum(5000);
    ui->doubleSpinBox_newTarget_value_X->setMinimum(-5000);
    ui->doubleSpinBox_newTarget_value_X->setSingleStep(0.01);
    ui->doubleSpinBox_newTarget_value_X->setValue(1.0);

    ui->doubleSpinBox_newTarget_value_Y->setDecimals(2);
    ui->doubleSpinBox_newTarget_value_Y->setMaximum(5000);
    ui->doubleSpinBox_newTarget_value_Y->setMinimum(-5000);
    ui->doubleSpinBox_newTarget_value_Y->setSingleStep(0.01);
    ui->doubleSpinBox_newTarget_value_Y->setValue(1.0);

    ui->doubleSpinBox_newTarget_value_Z->setDecimals(2);
    ui->doubleSpinBox_newTarget_value_Z->setMaximum(5000);
    ui->doubleSpinBox_newTarget_value_Z->setMinimum(-5000);
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




