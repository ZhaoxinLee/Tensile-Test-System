#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QThread>
#include <QTimer>
#include <cmath>

#include "serialworker.h"
#include "daq.h"
#include "joystick.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    serialworker *arduino = new serialworker();

    daq DAQ;
    QTimer *daq_timer = new QTimer();
    const int daq_refresh_period = 100; // ms

    const double ATINanoVoltageOffsets[6] = {-1.3171104,	3.8164696,	2.2166968,	1.9402872,	-0.44156372,	-1.0281404};
    const double ATINanoCalibrationMatrix[6][6] =  {{  0.00749,	 0.02250,	 0.01747,	-0.80775,	-0.02452,	 0.81951},
                                                   { -0.03933,	 0.97698,	 0.01759,	-0.43942,	 0.00040,	-0.49738},
                                                   {  0.92086,	 0.03400,	 0.93714,	-0.00522,	 0.97298,	 0.01115},
                                                   { -0.55209,	 5.99193,	 5.23393,	-2.69998,	-5.44013,	-3.14306},
                                                   { -5.88807,	-0.35924,	 2.76672,	 4.91801,	 3.46558,	-4.95869},
                                                   { -0.17835,	 3.57785,	-0.02007,	 3.30164,	-0.08660,	 3.66835}};
    double ATINanoForceTorque[6] = {0.0};

    Joystick *joy = new Joystick();

private:
    Ui::MainWindow *ui;

    QThread* arduino_thread = new QThread();


public slots:
    void enableDAQ(void);
    void disableDAQ(void);

    void enableJoystick(void);

private slots:

    void write_to_arduino( const char* );
    void update_position_UI( QStringList );
    void move_gantry( void );
    void zero_gantry( void );
    void center_gantry( void );

    void update_ATI_labels();

signals:
    void serial_sent( const char* );
};
#endif // MAINWINDOW_H
