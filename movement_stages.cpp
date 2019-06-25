#include "owis_controller.h"
#include "ui_owis_controller.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include "x86\ps90.h"
#include <QTimer>
#include <iostream>
#include <windows.h>



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


///////////////////////// X STAGE /////////////////////

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


void OWIS_controller::on_moveAxisButton_X_clicked()
{
    if(!X_stage_on)
        return;
    double Tvalue = ui->doubleSpinBox_newTarget_value_X->value();
    long error = PS90_MoveEx(Index,Axisid_X,Tvalue,1);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_MoveEx X Axis- need to add specification!!")); }
}

void OWIS_controller::on_homeButton_X_clicked()
{
    if(!X_stage_on)
        return;
   
    long error =   PS90_SetSlowRefFEx(Index,Axisid_X,ref_vel_slow[0]);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetSlowRefFEx X Axis")); }

    error =   PS90_SetFastRefFEx(Index,Axisid_X,ref_vel_fast[0]);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetFastRefFEx X Axis")); }


   
    error = PS90_GoRef(Index,Axisid_X,goRefMode[1]);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GoRef X Axis- need to add specification!!")); }

    long move_state=1;

     while (move_state != 0){
         move_state = PS90_GetMoveState(Index,Axisid_X);
         error = PS90_GetReadError(Index);
         if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetMoveState X Axis ")); }
     }

     Sleep(100);

     error = PS90_ResetCounter(Index,Axisid_X);
     if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_ResetCounter X Axis- need to add specification!!")); }


}


void OWIS_controller::runX (double direction)
{
if (direction > 0)
    {long error =   PS90_SetSlowRefFEx(Index,Axisid_X,joy_vel_slow_neg[0]);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetSlowRefFEx X Axis")); }

    error =   PS90_SetFastRefFEx(Index,Axisid_X,joy_vel_fast_pos[0]);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetFastRefFEx X Axis")); }
    }
else
{  long error =   PS90_SetSlowRefFEx(Index,Axisid_X,joy_vel_slow_pos[0]);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetSlowRefFEx X Axis")); }

    error =   PS90_SetFastRefFEx(Index,Axisid_X,joy_vel_fast_neg[0]);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetFastRefFEx X Axis")); }
}

long error = PS90_GoRef(Index,Axisid_X,1);
if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GoRef X Axis")); }

}


void OWIS_controller::stopX()

{
long error = PS90_Stop (Index,Axisid_X);
if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_Stop X Axis"));
}
}

void OWIS_controller::virtualJoy_X()

{
if (sender() == ui->joyNegButton_X)
runX(-1);
//if (error !=0) {QMessageBox::critical(this, tr("Error"), tr("Error in RunX Axis")); }}
 else if (sender() == ui->joyPosButton_X)
runX(1);
//if (error !=0) {QMessageBox::critical(this, tr("Error"), tr("Error in RunX Axis")); }}
}




 //////////////////////// Y STAGE ///////////////////////


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

void OWIS_controller::on_moveAxisButton_Y_clicked()
{
    if(!Y_stage_on)
        return;
    double Tvalue = ui->doubleSpinBox_newTarget_value_Y->value();
    long error = PS90_MoveEx(Index,Axisid_Y,Tvalue,1);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_MoveEx Y Axis- need to add specification!!")); }
}

void OWIS_controller::on_homeButton_Y_clicked()
{
    if(!Y_stage_on)
        return;
   

long error =   PS90_SetSlowRefFEx(Index,Axisid_Y,ref_vel_slow[1]);
if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetSlowRefFEx Y Axis")); }

error =   PS90_SetFastRefFEx(Index,Axisid_Y,ref_vel_fast[1]);
if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetFastRefFEx Y Axis")); }

error = PS90_GoRef(Index,Axisid_Y,goRefMode[1]);
if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GoRef Y Axis- need to add specification!!")); }

   long move_state=1;

    while (move_state != 0){
        move_state = PS90_GetMoveState(Index,Axisid_Y);
        error = PS90_GetReadError(Index);
        if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetMoveState Y Axis ")); }
    }

    Sleep(100);

    error = PS90_ResetCounter(Index,Axisid_Y);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_ResetCounter Y Axis- need to add specification!!")); }


}



void OWIS_controller::runY (double direction)
{
if (direction > 0)
    {long error =   PS90_SetSlowRefFEx(Index,Axisid_Y,joy_vel_slow_neg[1]);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetSlowRefFEx Y Axis")); }

    error =   PS90_SetFastRefFEx(Index,Axisid_Y,joy_vel_fast_pos[1]);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetFastRefFEx Y Axis")); }
    }
else
{  long error =   PS90_SetSlowRefFEx(Index,Axisid_Y,joy_vel_slow_pos[1]);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetSlowRefFEx Y Axis")); }

    error =   PS90_SetFastRefFEx(Index,Axisid_Y,joy_vel_fast_neg[1]);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetFastRefFEx Y Axis")); }
}

long error = PS90_GoRef(Index,Axisid_Y,1);
if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GoRef Y Axis")); }

}


void OWIS_controller::stopY()

{
long error = PS90_Stop (Index,Axisid_Y);
if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_Stop Y Axis"));
}
}

void OWIS_controller::virtualJoy_Y()

{
if (sender() == ui->joyNegButton_Y)
runY(-1);
//if (error !=0) {QMessageBox::critical(this, tr("Error"), tr("Error in RunY Axis")); }}
 else if (sender() == ui->joyPosButton_Y)
runY(1);
//if (error !=0) {QMessageBox::critical(this, tr("Error"), tr("Error in RunY Axis")); }}
}



///////////////////// Z STAGE ///////////////////////////


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


void OWIS_controller::on_moveAxisButton_Z_clicked()
{
    if(!Z_stage_on)
        return;
    double Tvalue = ui->doubleSpinBox_newTarget_value_Z->value();
    long error = PS90_MoveEx(Index,Axisid_Z,Tvalue,1);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_MoveEx Z Axis- need to add specification!!")); }
}

void OWIS_controller::on_homeButton_Z_clicked()
{
    if(!Z_stage_on)
        return;
   

long error =   PS90_SetSlowRefFEx(Index,Axisid_Z,ref_vel_slow[2]);
if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetSlowRefFEx Z Axis")); }

error =   PS90_SetFastRefFEx(Index,Axisid_Z,ref_vel_fast[2]);
if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetFastRefFEx Z Axis")); }

error = PS90_GoRef(Index,Axisid_Z,goRefMode[1]);
if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GoRef Z Axis- need to add specification!!")); }

    long move_state=1;

     while (move_state != 0){
         move_state = PS90_GetMoveState(Index,Axisid_Z);
         error = PS90_GetReadError(Index);
         if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetMoveState Z Axis ")); }
     }

     Sleep(100);
     error = PS90_ResetCounter(Index,Axisid_Z);
     if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_ResetCounter Z Axis- need to add specification!!")); }
}


void OWIS_controller::runZ (double direction)
{
if (direction > 0)
    {long error =   PS90_SetSlowRefFEx(Index,Axisid_Z,joy_vel_slow_neg[2]);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetSlowRefFEx Z Axis")); }

    error =   PS90_SetFastRefFEx(Index,Axisid_Z,joy_vel_fast_pos[2]);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetFastRefFEx Z Axis")); }
    }
else
{  long error =   PS90_SetSlowRefFEx(Index,Axisid_Z,joy_vel_slow_pos[2]);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetSlowRefFEx Z Axis")); }

    error =   PS90_SetFastRefFEx(Index,Axisid_Z,joy_vel_fast_neg[2]);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_SetFastRefFEx Z Axis")); }
}

long error = PS90_GoRef(Index,Axisid_Z,1);
if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GoRef Z Axis")); }

}


void OWIS_controller::stopZ()

{
long error = PS90_Stop (Index,Axisid_Z);
if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_Stop Z Axis"));
}
}

void OWIS_controller::virtualJoy_Z()

{
if (sender() == ui->joyNegButton_Z)
runY(-1);
//if (error !=0) {QMessageBox::critical(this, tr("Error"), tr("Error in RunZ Axis")); }}
 else if (sender() == ui->joyPosButton_Z)
runY(1);
//if (error !=0) {QMessageBox::critical(this, tr("Error"), tr("Error in RunZ Axis")); }}
}



