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
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetTargetMode X Axis")); }
    if(mode  == 0)
        ui->label_axis_target_mode_X->setText("Target mode "+ QString::number(mode) + " : Relative" );
    else
        ui->label_axis_target_mode_X->setText("Target mode "+ QString::number(mode) + " : Absolute");

    double value = PS90_GetPosition (Index,Axisid_X);
    error = PS90_GetReadError(Index);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetPositionEx X Axis")); }
    ui->lineEdit_axis_pos_X->setText(QString::number(value*pitch[0]/increments_per_rev[0]));

    move_state_X = PS90_GetMoveState(Index,Axisid_X);
    error = PS90_GetReadError(Index);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetMoveState X Axis ")); }

    if(move_state_X != 0)
        ui->label_axis_movement_X->setText(" X Axis is moving!!!");
    else
        ui->label_axis_movement_X->setText(" X Axis still");

long lim_swit = {PS90_GetSwitchState(Index,Axisid_X)};
    error = PS90_GetReadError(Index);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetSwitchState X Axis ")); }

//    ui->lineEdit_GetSwitchInput->setText(QString::number(lim_swit));

//if (lim_swit==minstp || lim_swit == min)
//    ui->label_minstp_x->setText("Active");
//else
//    ui->label_minstp_x->setText("Released");

//if (lim_swit==mindec || lim_swit == min)
//    ui->label_mindec_x->setText("Active");
//else
//    ui->label_mindec_x->setText("Released");

//if (lim_swit==maxdec || lim_swit==max)
//    ui->label_maxdec_x->setText("Active");
//else
//    ui->label_maxdec_x->setText("Released");

//if (lim_swit==maxstp || lim_swit==max)
//    ui->label_maxstp_x->setText("Active");
//else
//    ui->label_maxstp_x->setText("Released");

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

    double value = PS90_GetPosition (Index,Axisid_Y);
    error = PS90_GetReadError(Index);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetPositionEx Y Axis - need to add specification!!")); }
    ui->lineEdit_axis_pos_Y->setText(QString::number(value*pitch[1]/increments_per_rev[1]));

    move_state_Y = PS90_GetMoveState(Index,Axisid_Y);
    error = PS90_GetReadError(Index);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetMoveState Y Axis - need to add specification!!")); }

    if(move_state_Y != 0)
        ui->label_axis_movement_Y->setText(" Y Axis is moving!!!");
    else
        ui->label_axis_movement_Y->setText(" Y Axis still");

long lim_swit= {PS90_GetSwitchState(Index,Axisid_Y)};
    error = PS90_GetReadError(Index);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetSwitchState X Axis ")); }

//    ui->lineEdit_GetSwitchInput->setText(QString::number(lim_swit));

//if (lim_swit==minstp || lim_swit == min)
//    ui->label_minstp_y->setText("Active");
//else
//    ui->label_minstp_y->setText("Released");

//if (lim_swit==mindec || lim_swit == min)
//    ui->label_mindec_y->setText("Active");
//else
//    ui->label_mindec_y->setText("Released");

//if (lim_swit==maxdec || lim_swit==max)
//    ui->label_maxdec_y->setText("Active");
//else
//    ui->label_maxdec_y->setText("Released");

//if (lim_swit==maxstp || lim_swit==max)
//    ui->label_maxstp_y->setText("Active");
//else
//    ui->label_maxstp_y->setText("Released");

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

    double value = PS90_GetPosition (Index,Axisid_Z);
    error = PS90_GetReadError(Index);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetPositionEx Z Axis - need to add specification!!")); }
    ui->lineEdit_axis_pos_Z->setText(QString::number(value*pitch[2]/increments_per_rev[2]));

    move_state_Z = PS90_GetMoveState(Index,Axisid_Z);
    error = PS90_GetReadError(Index);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetMoveState Z Axis - need to add specification!!")); }

    if(move_state_Z != 0)
        ui->label_axis_movement_Z->setText(" Z Axis is moving!!!");
    else
        ui->label_axis_movement_Z->setText(" Z Axis still");


long lim_swit= {PS90_GetSwitchState(Index,Axisid_Z)};
    error = PS90_GetReadError(Index);
    if (error != 0 ){ QMessageBox::critical(this, tr("Error"), tr("Error in PS90_GetSwitchState X Axis "));}

//    ui->lineEdit_GetSwitchInput->setText(QString::number(lim_swit));


//if (lim_swit==minstp || lim_swit == min)
//    ui->label_minstp_z->setText("Active");
//else
//    ui->label_minstp_z->setText("Released");

//if (lim_swit==mindec || lim_swit == min)
//    ui->label_mindec_z->setText("Active");
//else
//    ui->label_mindec_z->setText("Released");

//if (lim_swit==maxdec || lim_swit==max)
//    ui->label_maxdec_z->setText("Active");
//else
//    ui->label_maxdec_z->setText("Released");

//if (lim_swit==maxstp || lim_swit==max)
//    ui->label_maxstp_z->setText("Active");
//else
//    ui->label_maxstp_z->setText("Released");

}
