#include "owis_controller.h"
#include "ui_owis_controller.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include "x86\ps90.h"
#include <QTimer>
#include <iostream>


void OWIS_controller::on_InitPS90Button_clicked()
{
    //See example code and LabView functions
    if (PS90_Connect(Index, 0, 3, 9600, 0, 0, 8, 0) != 0 ){
        QMessageBox::critical(this, tr("Error"), tr("Could not connect to PS90!!"));
        //        QCoreApplication::quit();
    } else {

        PS90_connected = true;

    ui->label_PS90_general_status->setText("PS90 Status: Connected");

        // turning on Axes - following scheme of LabView function -
        // The tool example code is slightly different



        //X Axis : 1//

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

     //   ui->lineEdit_Target_value_X->setText(QString::number(0));



        //Y Axis : 2//





        error = PS90_SetMotorType(Index,Axisid_Y,motor_type[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetMotorType Y Axis")); }

        error = PS90_SetLimitSwitch(Index,Axisid_Y,limit_switch[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetLimitSwitch Y Axis")); }

        error = PS90_SetLimitSwitchMode(Index,Axisid_Y,limit_switch_mode[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetLimitSwitchMode Y Axis")); }

        error = PS90_SetRefSwitch(Index,Axisid_Y,ref_switch[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetRefSwitch Y Axis")); }

        error = PS90_SetRefSwitchMode(Index,Axisid_Y,ref_switch_mode[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in SetRefSwitchMode Y Axis")); }

        error = PS90_SetSampleTime(Index,Axisid_Y,sample_time[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in SetSampleTime Y Axis")); }

        error = PS90_SetKP(Index,Axisid_Y,KP[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetKP Y Axis")); }

        error =  PS90_SetKI(Index,Axisid_Y,KI[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetKI Y Axis")); }

        error =  PS90_SetKD(Index,Axisid_Y,KD[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetKD Y Axis")); }

        error =  PS90_SetDTime(Index,Axisid_Y,DTime[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetDTime Y Axis")); }

        error =  PS90_SetILimit(Index,Axisid_Y,ILimit[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetILimit Y Axis")); }

        error =  PS90_SetTargetWindow(Index,Axisid_Y,target_window[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetTargetWindow Y Axis")); }

        error =  PS90_SetInPosMode(Index,Axisid_Y,pos_mode[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetInPosMode Y Axis")); }

        error =  PS90_SetCurrentLevel(Index,Axisid_Y,current_level[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in SetCurrentLevel Y Axis")); }

        error =  PS90_SetStageAttributes(Index,Axisid_Y,pitch[1],increments_per_rev[1],gear_reduction_ratio[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetStageAttributes Y Axis")); }

        error =  PS90_SetMsysResol(Index,Axisid_Y,lin_res[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetMsysResol Y Axis")); }

        error = PS90_SetTargetMode(Index,Axisid_Y,ini_target_mode[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetTargetMode Y Axis")); }
        ui->label_axis_target_mode_X->setText("Y Axis Target mode : Relative");

        error =  PS90_SetAccel(Index,Axisid_Y,acc[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetAccel Y Axis")); }

        error =  PS90_SetDecel(Index,Axisid_Y,dacc[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetDecel Y Axis")); }

        error =   PS90_SetJerk(Index,Axisid_Y,jacc[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetJerk Y Axis")); }

        error =   PS90_SetRefDecel(Index,Axisid_Y,ref_dacc[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetRefDecel Y Axis")); }

        error =   PS90_SetVel(Index,Axisid_Y,vel[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetVel Y Axis")); }

         error =   PS90_SetPosVel(Index,Axisid_Y,pos_vel[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetPosVel Y Axis")); }

         error =   PS90_SetSlowRefVel(Index,Axisid_Y,ref_vel_slow[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetSlowRefVel Y Axis")); }

        error =   PS90_SetFastRefVel(Index,Axisid_Y,ref_vel_fast[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetFastRefVel Y Axis")); }

        error =   PS90_SetFreeVel(Index,Axisid_Y,free_vel[1]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetFreeVel Y Axis")); }


        value = PS90_GetPositionEx(Index,Axisid_Y);
        error = PS90_GetReadError(Index);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetPositionEx Y Axis")); }
        ui->lineEdit_axis_pos_Y->setText(QString::number(value));

       // ui->lineEdit_Target_value_Y->setText(QString::number(0));



        //Z Axis : 3//




        error = PS90_SetMotorType(Index,Axisid_Z,motor_type[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetMotorType Z Axis")); }

        error = PS90_SetLimitSwitch(Index,Axisid_Z,limit_switch[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetLimitSwitch Z Axis")); }

        error = PS90_SetLimitSwitchMode(Index,Axisid_Z,limit_switch_mode[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetLimitSwitchMode Z Axis")); }

        error = PS90_SetRefSwitch(Index,Axisid_Z,ref_switch[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetRefSwitch Z Axis")); }

        error = PS90_SetRefSwitchMode(Index,Axisid_Z,ref_switch_mode[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in SetRefSwitchMode Z Axis")); }

        error = PS90_SetSampleTime(Index,Axisid_Z,sample_time[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in SetSampleTime Z Axis")); }

        error = PS90_SetKP(Index,Axisid_Z,KP[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetKP Z Axis")); }

        error =  PS90_SetKI(Index,Axisid_Z,KI[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetKI Z Axis")); }

        error =  PS90_SetKD(Index,Axisid_Z,KD[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetKD Z Axis")); }

        error =  PS90_SetDTime(Index,Axisid_Z,DTime[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetDTime Z Axis")); }

        error =  PS90_SetILimit(Index,Axisid_Z,ILimit[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetILimit Z Axis")); }

        error =  PS90_SetTargetWindow(Index,Axisid_Z,target_window[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetTargetWindow Z Axis")); }

        error =  PS90_SetInPosMode(Index,Axisid_Z,pos_mode[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetInPosMode Z Axis")); }

        error =  PS90_SetCurrentLevel(Index,Axisid_Z,current_level[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in SetCurrentLevel Z Axis")); }

        error =  PS90_SetStageAttributes(Index,Axisid_Z,pitch[2],increments_per_rev[2],gear_reduction_ratio[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetStageAttributes Z Axis")); }

        error =  PS90_SetMsysResol(Index,Axisid_Z,lin_res[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetMsysResol Z Axis")); }

        error = PS90_SetTargetMode(Index,Axisid_Z,ini_target_mode[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetTargetMode Z Axis")); }
        ui->label_axis_target_mode_X->setText("Z Axis Target mode : Relative");

        error =  PS90_SetAccel(Index,Axisid_Z,acc[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetAccel Z Axis")); }

        error =  PS90_SetDecel(Index,Axisid_Z,dacc[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetDecel Z Axis")); }

        error =   PS90_SetJerk(Index,Axisid_Z,jacc[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetJerk Z Axis")); }

        error =   PS90_SetRefDecel(Index,Axisid_Z,ref_dacc[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetRefDecel Z Axis")); }

        error =   PS90_SetVel(Index,Axisid_Z,vel[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetVel Z Axis")); }

         error =   PS90_SetPosVel(Index,Axisid_Z,pos_vel[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetPosVel Z Axis")); }

         error =   PS90_SetSlowRefVel(Index,Axisid_Z,ref_vel_slow[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetSlowRefVel Z Axis")); }

        error =   PS90_SetFastRefVel(Index,Axisid_Z,ref_vel_fast[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetFastRefVel Z Axis")); }

        error =   PS90_SetFreeVel(Index,Axisid_Z,free_vel[2]);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetFreeVel Z Axis")); }


        value = PS90_GetPositionEx(Index,Axisid_Z);
        error = PS90_GetReadError(Index);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetPositionEx Z Axis")); }
        ui->lineEdit_axis_pos_Z->setText(QString::number(value));

       // ui->lineEdit_Target_value_Z->setText(QString::number(0));


    }

        //setting values for doublespinbox
    ui->doubleSpinBox_newTarget_value_X->setDecimals(2);
    ui->doubleSpinBox_newTarget_value_X->setMaximum(5000);
    ui->doubleSpinBox_newTarget_value_X->setMinimum(-5000);
    ui->doubleSpinBox_newTarget_value_X->setSingleStep(1);
    ui->doubleSpinBox_newTarget_value_X->setValue(1.0);

    ui->doubleSpinBox_newTarget_value_Y->setDecimals(2);
    ui->doubleSpinBox_newTarget_value_Y->setMaximum(5000);
    ui->doubleSpinBox_newTarget_value_Y->setMinimum(-5000);
    ui->doubleSpinBox_newTarget_value_Y->setSingleStep(1);
    ui->doubleSpinBox_newTarget_value_Y->setValue(1.0);

    ui->doubleSpinBox_newTarget_value_Z->setDecimals(2);
    ui->doubleSpinBox_newTarget_value_Z->setMaximum(5000);
    ui->doubleSpinBox_newTarget_value_Z->setMinimum(-5000);
    ui->doubleSpinBox_newTarget_value_Z->setSingleStep(1);
    ui->doubleSpinBox_newTarget_value_Z->setValue(1.0);

}


void OWIS_controller::on_DisconnectButton_clicked()
{
    if(!PS90_connected)
        return;

    long error = PS90_Disconnect(1);
    if (error != 0 )
    { QMessageBox::critical(this, tr("Error"), tr("Error in PS90_Disconnect"));
    }else{
          ui->label_PS90_general_status->setText("PS90 Status: Disconnected");
          ui->label_stage_state_X->setText("X Stage: Off");
          ui->label_stage_state_Y->setText("Y Stage: Off");
          ui->label_stage_state_Z->setText("Z Stage: Off");

    }
}