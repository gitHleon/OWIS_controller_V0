#ifndef OWIS_CONTROLLER_H
#define OWIS_CONTROLLER_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>


namespace Ui {
class OWIS_controller;
}

class OWIS_controller : public QMainWindow
{
    Q_OBJECT

public:
    explicit OWIS_controller(QWidget *parent = nullptr);
    ~OWIS_controller();

private slots:


void J_axes_translator(int index, int button, double value);
void enableRealJoyClicked(bool clicked);
void runRealJoy();
bool TalkSR232(const std::vector<std::string> &arguments);
void dispense_order();

/// initialization.cpp ///


    void on_InitPS90Button_clicked();
    void on_DisconnectButton_clicked();


/// master_stages.cpp ///

    void on_InitStageButton_X_clicked();
    void on_InitStageButton_Y_clicked();
    void on_InitStageButton_Z_clicked();
    void on_ShutOnStage_X_clicked();
    void on_ShutOnStage_Y_clicked();
    void on_ShutOnStage_Z_clicked();
    void on_ShutOffStage_X_clicked();
    void on_ShutOffStage_Y_clicked();
    void on_ShutOffStage_Z_clicked();

/// update stages ///

    void updatePositions_X();
    void updatePositions_Y();
    void updatePositions_Z();

/// movement_stages ///

    void on_stopButton_clicked();
    void on_switchModeButton_X_clicked();
    void on_switchModeButton_Y_clicked();
    void on_switchModeButton_Z_clicked();
    void on_moveAxisButton_X_clicked();
    void on_moveAxisButton_Y_clicked();
    void on_moveAxisButton_Z_clicked();
    void on_homeButton_X_clicked();
    void on_homeButton_Y_clicked();
    void on_homeButton_Z_clicked();
    void runX (double direction);
    void stopX ();
    void virtualJoy_X();
    void runY (double direction);
    void stopY ();
    void virtualJoy_Y();
    void runZ (double direction);
    void stopZ ();
    void virtualJoy_Z();
    void realJoy_X();
    void realJoy_Y();
    void realJoy_Z();


private:


    Ui::OWIS_controller *ui;
    QLineEdit *display;

    bool PS90_connected = false;
    bool X_stage_init = false;
    bool Y_stage_init = false;
    bool Z_stage_init = false;
    bool X_stage_on = false;
    bool Y_stage_on = false;
    bool Z_stage_on = false;
    long move_state_X=0;
    long move_state_Y=0;
    long move_state_Z=0;
    const long Index = 1.;      // PS-90 INDEX
    const long Axisid_X = 1.;
    const long Axisid_Y = 2.;
    const long Axisid_Z = 3.;
    const char* result_window = "Result window";

   const int relative=0;
   const int absolute=1;
   const long motor_type [3]={0,0,0};
   const long limit_switch [3]={15,15,7};
   const long limit_switch_mode [3]={15,15,15};
   const long ref_switch [3]={2,2,2};
   const long ref_switch_mode [3]={15,15,15};
   const long sample_time [3]={256,256,256};
   const long KP [3]={25,30,30};
   const long KI [3]={25,50,50};
   const long KD [3]={50,50,50};
   const long DTime [3]={0,0,0};
   const long ILimit [3]={5000000,5000000,5000000};
   const long target_window [3]={500,500,500};
   const long pos_mode [3]={0,0,0};
   const long current_level [3]={1,0,0};
   const double pitch [3]={5.0,2.0,1.0};
   const long increments_per_rev [3]={50000,20000,10000};
   const double res_motor[3]={0.0001,0.0001,0.0001}; //inc/pitch
   const double gear_reduction_ratio [3]={1.0,1.0,1.0};
   const double lin_res [3]={0.0001,0.0001,0.0001};
   const long ini_target_mode [3]={0,0,0};
   const long acc [3]={20,20,10};
   const long dacc [3]={20,20,10};
   const long jacc [3]={200000,200000,200000};
   const long ref_dacc [3]={80,80,80};
   const long vel [3]={0,0,0};
   const long pos_vel [3]={10,10,3};
   const long ref_vel_slow [3]={1,1,1};
   const long ref_vel_fast [3]={-10,-7,-3};
   const long joy_vel_slow_pos[3]={1,1,1};
   const long joy_vel_fast_neg[3]={-10,-7,-3};
   const long joy_vel_slow_neg[3]={-1,-1,-1};
   const long joy_vel_fast_pos[3]={10,7,3};
   const long free_vel [3]={29802,29802,47683};


   const long minstp=1;
   const long mindec=2;
   const long min=3;
   const long maxdec=4;
   const long maxstp=8;
   const long max=12;

   const long ref_switch_x=2;
   const long ref_switch_y=2;
   const long ref_switch_z=2;

   const long goRefMode [8]={0,1,2,3,4,5,6,7};

   int test_counter=1;
   int joy_state_X=0;
   int joy_state_Y=0;
   int joy_state_Z=0;
   int mov_state_X=0;
   int mov_state_Y=0;
   int mov_state_Z=0;

   int realJoyConnect=0;
};

#endif // OWIS_CONTROLLER_H
