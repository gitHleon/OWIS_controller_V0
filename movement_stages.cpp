#include "owis_controller.h"
#include "ui_owis_controller.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include "x86\ps90.h"
#include <QTimer>
#include <iostream>



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
   
    long error = PS90_GoRef(Index,Axisid_X,goRefMode[4]);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GoRef X Axis- need to add specification!!")); }
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
   
    long error = PS90_GoRef(Index,Axisid_Y,goRefMode[4]);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GoRef Y Axis- need to add specification!!")); }
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
   
    long error = PS90_GoRef(Index,Axisid_Y,goRefMode[4]);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GoRef Z Axis- need to add specification!!")); }
}



