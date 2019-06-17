#include "owis_controller.h"
#include "ui_owis_controller.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include "x86\ps90.h"
#include <QTimer>
#include <iostream>


void OWIS_controller::on_InitStageButton_X_clicked()
{
    if(!PS90_connected)
        return;
X_stage_init = true;
X_stage_on=true;
    long error = PS90_MotorInit(Index,Axisid_X);
    if (error != 0 ){ 
    	QMessageBox::critical(this, tr("Error"), tr("Error in PS90_MotorInit X Axis")); 
    } else {
ui->label_stage_state_X->setText("X Stage: On");
    }
}

void OWIS_controller::on_ShutOnStage_X_clicked()
{
    if(!PS90_connected)
        return;
X_stage_on=true;
    long error = PS90_MotorOn(Index,Axisid_X);
    if (error != 0 ){ 
    	QMessageBox::critical(this, tr("Error"), tr("Error in PS90_MotorOn X Axis ")); 
    } else {
ui->label_stage_state_X->setText("X Stage: On");
    }
}

void OWIS_controller::on_ShutOffStage_X_clicked()
{
    if(!PS90_connected)
        return;
X_stage_on=false;
    long error = PS90_MotorOff(Index,Axisid_X);
    if (error != 0 ){ 
    	QMessageBox::critical(this, tr("Error"), tr("Error in PS90_MotorOff X Axis ")); 
    } else {
ui->label_stage_state_X->setText("X Stage: Off");
    }
ui->label_minstp_x->setText("");
ui->label_mindec_x->setText("");
ui->label_maxdec_x->setText("");
ui->label_maxstp_x->setText("");

}




// Y STAGE INIT, ON AND OFF BUTTONS //

void OWIS_controller::on_InitStageButton_Y_clicked()
{
    if(!PS90_connected)
        return;
Y_stage_init = true;
Y_stage_on=true;
    long error = PS90_MotorInit(Index,Axisid_Y);
    if (error != 0 ){ 
    	QMessageBox::critical(this, tr("Error"), tr("Error in PS90_MotorInit Y Axis - need to add specification!!")); 
    }else {
    ui->label_stage_state_Y->setText("Y Stage: On");	
    }
}


void OWIS_controller::on_ShutOnStage_Y_clicked()
{
    if(!PS90_connected)
        return;
Y_stage_on=true;
    long error = PS90_MotorOn(Index,Axisid_Y);
    if (error != 0 ){ 
    	QMessageBox::critical(this, tr("Error"), tr("Error in PS90_MotorOn Y Axis ")); 
    } else {
ui->label_stage_state_Y->setText("Y Stage: On");
   }
}

void OWIS_controller::on_ShutOffStage_Y_clicked()
{
    if(!PS90_connected)
        return;
Y_stage_on=false;
    long error = PS90_MotorOff(Index,Axisid_Y);
    if (error != 0 ){ 
    	QMessageBox::critical(this, tr("Error"), tr("Error in PS90_MotorOff Y Axis ")); 
    } else {

ui->label_stage_state_Y->setText("Y Stage: Off");

    }

ui->label_minstp_y->setText("");
ui->label_mindec_y->setText("");
ui->label_maxdec_y->setText("");
ui->label_maxstp_y->setText("");
}


// Z STAGE INIT, ON AND OFF BUTTONS //


void OWIS_controller::on_InitStageButton_Z_clicked()
{
    if(!PS90_connected)
        return;

Z_stage_init = true;
Z_stage_on=true;
    long error = PS90_MotorInit(Index,Axisid_Z);
    if (error != 0 ){ 
    	QMessageBox::critical(this, tr("Error"), tr("Error in PS90_MotorInit Z Axis - need to add specification!!")); 
    }else {
    	ui->label_stage_state_Z->setText("Z Stage: On");
    }

}

void OWIS_controller::on_ShutOnStage_Z_clicked()
{
    if(!PS90_connected)
        return;

Z_stage_on=true;
    long error = PS90_MotorOn(Index,Axisid_Z);
    if (error != 0 ){ 
    	QMessageBox::critical(this, tr("Error"), tr("Error in PS90_MotorOn Z Axis ")); 
    } else {
ui->label_stage_state_Z->setText("Z Stage: On");
    }
}

void OWIS_controller::on_ShutOffStage_Z_clicked()
{
    if(!PS90_connected)
        return;
Z_stage_on=false;
    long error = PS90_MotorOff(Index,Axisid_Z);
    if (error != 0 ){ 
    	QMessageBox::critical(this, tr("Error"), tr("Error in PS90_MotorOff Z Axis ")); 
    } else {
ui->label_stage_state_Z->setText("Z Stage: Off");

    }

ui->label_minstp_z->setText("");
ui->label_mindec_z->setText("");
ui->label_maxdec_z->setText("");
ui->label_maxstp_z->setText("");
}
