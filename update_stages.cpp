#include "owis_controller.h"
#include "ui_owis_controller.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include "x86\ps90.h"
#include <QTimer>
#include <iostream>


void OWIS_controller::updatePositions_X()
{
    if(!X_stage_on)
        return;

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

    double value = PS90_GetPosition (Index,Axisid_X);
    error = PS90_GetReadError(Index);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetPositionEx X Axis - need to add specification!!")); }
    ui->lineEdit_axis_pos_X->setText(QString::number(value*pitch[0]/increments_per_rev[0]));

    long move_state = PS90_GetMoveState(Index,Axisid_X);
    error = PS90_GetReadError(Index);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetMoveState X Axis - need to add specification!!")); }

    if(move_state != 0)
        ui->label_axis_movement_X->setText(" X Axis is moving!!!");
    else
        ui->label_axis_movement_X->setText(" X Axis still");

}


// Update positions Y //

void OWIS_controller::updatePositions_Y()
{
    if(!Y_stage_on)
        return;

    long mode  = PS90_GetTargetMode(Index,Axisid_Y );
    long error = PS90_GetReadError(Index);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetTargetMode_Y_Axis  - need to add specification!!")); }
    if(mode  == 0)
        ui->label_axis_target_mode_Y->setText("Target mode "+ QString::number(mode) + " : Relative" );
    else
        ui->label_axis_target_mode_Y->setText("Target mode "+ QString::number(mode) + " : Absolute");

    double Tvalue = PS90_GetTargetEx(Index,Axisid_Y);
    error = PS90_GetReadError(Index);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetTargetEx Y Axis - need to add specification!!")); }
    ui->lineEdit_Target_value_Y->setText(QString::number(Tvalue));

    double value = PS90_GetPosition (Index,Axisid_Y);
    error = PS90_GetReadError(Index);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetPositionEx Y Axis - need to add specification!!")); }
    ui->lineEdit_axis_pos_Y->setText(QString::number(value*pitch[1]/increments_per_rev[1]));

    long move_state = PS90_GetMoveState(Index,Axisid_Y);
    error = PS90_GetReadError(Index);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetMoveState Y Axis - need to add specification!!")); }

    if(move_state != 0)
        ui->label_axis_movement_Y->setText(" Y Axis is moving!!!");
    else
        ui->label_axis_movement_Y->setText(" Y Axis still");

}



void OWIS_controller::updatePositions_Z()
{
    if(!Z_stage_on)
        return;

    long mode  = PS90_GetTargetMode(Index,Axisid_Z );
    long error = PS90_GetReadError(Index);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetTargetMode Z Axis  - need to add specification!!")); }
    if(mode  == 0)
        ui->label_axis_target_mode_Z->setText("Target mode "+ QString::number(mode) + " : Relative" );
    else
        ui->label_axis_target_mode_Z->setText("Target mode "+ QString::number(mode) + " : Absolute");

    double Tvalue = PS90_GetTargetEx(Index,Axisid_Z);
    error = PS90_GetReadError(Index);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetTargetEx Z Axis - need to add specification!!")); }
    ui->lineEdit_Target_value_Z->setText(QString::number(Tvalue));

    double value = PS90_GetPosition (Index,Axisid_Z);
    error = PS90_GetReadError(Index);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetPositionEx Z Axis - need to add specification!!")); }
    ui->lineEdit_axis_pos_Z->setText(QString::number(value*pitch[2]/increments_per_rev[2]));

    long move_state = PS90_GetMoveState(Index,Axisid_Z);
    error = PS90_GetReadError(Index);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetMoveState Z Axis - need to add specification!!")); }

    if(move_state != 0)
        ui->label_axis_movement_Z->setText(" Z Axis is moving!!!");
    else
        ui->label_axis_movement_Z->setText(" Z Axis still");

}
