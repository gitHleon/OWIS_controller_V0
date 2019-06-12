#ifndef OWIS_CONTROLLER_H
#define OWIS_CONTROLLER_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>

#include <QMainWindow>

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
    void on_quitButton_clicked();
    void on_refreshButton_clicked();
    void on_initButton_clicked();
    void on_saveButton_clicked();

    void on_InitPS90Button_clicked();
    void on_stopButton_clicked();

    void on_switchModeButton_X_clicked();
    void on_switchModeButton_Y_clicked();
    void on_switchModeButton_Z_clicked();
    void on_moveAxisButton_X_clicked();
    void on_moveAxisButton_Y_clicked();
    void on_moveAxisButton_Z_clicked();

    void updatePicture();
    void updatePositions();
    void on_MatchButton_clicked();

private:
    Ui::OWIS_controller *ui;
    QLineEdit *display;
    bool PS90_connected = false;
    const long Index = 1.;      // PS-90 INDEX
    const long Axisid_X = 1.;
    const long Axisid_Y = 2.;
    const long Axisid_Z = 3.;
    const char* result_window = "Result window";
};

#endif // OWIS_CONTROLLER_H
