#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* uncomment this module to check serial port info for Arduino
    qDebug()<<"Number of available ports:"<<QSerialPortInfo::availablePorts().length();
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
            qDebug() << "Has vendor ID: " << serialPortInfo.hasVendorIdentifier();
            if(serialPortInfo.hasVendorIdentifier()){
                qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier();
            }
            qDebug() << "Has Product ID: " << serialPortInfo.hasProductIdentifier();
            if(serialPortInfo.hasProductIdentifier()){
                qDebug() << "Product ID: " << serialPortInfo.productIdentifier();
            }
        }*/
//--------------------------------------------------------------------Arduino--------------------------------------------------------------------------------------------
    arduino->moveToThread(arduino_thread);
    connect(arduino_thread, SIGNAL(started()), arduino, SLOT(connect()));
    connect(arduino, SIGNAL(finished()), arduino_thread, SLOT(quit()));
    connect(arduino, SIGNAL(finished()), arduino, SLOT(deleteLater()));
    connect(arduino_thread, SIGNAL(finished()), arduino_thread, SLOT(deleteLater()));

    connect(ui->moveButton,SIGNAL(clicked()),SLOT(move_gantry()));
    connect(ui->centerButton,SIGNAL(clicked()),SLOT(center_gantry()));
    connect(ui->zeroButton,SIGNAL(clicked()),SLOT(zero_gantry()));

    connect(this,SIGNAL(serial_sent(const char*)),arduino,SLOT(pass_on_to_arduino(const char*)));
    connect(arduino,SIGNAL(serial_received(QStringList)),this,SLOT(update_position_UI(QStringList)));
    arduino_thread -> start();

    //connect(callbacktimer, SIGNAL(timeout()), this, SLOT(callbacks()));
    //callbacktimer->start(callbackRefreshPeriod);

//--------------------------------------------------------------------Load Cell--------------------------------------------------------------------------------------------
    daq_timer->setInterval(daq_refresh_period);
    connect(ui->ATI_connect_btn,SIGNAL(clicked()),SLOT(enableDAQ()));
    connect(ui->ATI_connect_btn,SIGNAL(clicked()),daq_timer,SLOT(start()));
    connect(daq_timer,SIGNAL(timeout()),this,SLOT(update_ATI_labels()));
    connect(ui->ATI_disconnect_btn,SIGNAL(clicked()),SLOT(disableDAQ()));

//--------------------------------------------------------------------Joystick--------------------------------------------------------------------------------------------
    connect(ui->enableJoystick,SIGNAL(clicked()),SLOT(enableJoystick()));


}

MainWindow::~MainWindow()
{
    // STOP DAQ from running

    qInfo() << "Exiting NI USB-DAQ.";
    DAQ.finishTask();

    delete ui;
}


//--------------------------------------------------------------------Arduino--------------------------------------------------------------------------------------------
void MainWindow::write_to_arduino( const char* commandLine ) {
    emit serial_sent( commandLine );
}

void MainWindow::move_gantry( void ) {

    if (ui->absoluteRadio->isChecked()) {
        write_to_arduino(("<1,0," + std::to_string(ui->xSpinBox->value()) + "," + std::to_string(ui->ySpinBox->value()) + "," + std::to_string(ui->zSpinBox->value()) + ">").c_str());
    }
    else if (ui->relativeRadio->isChecked()) {
        write_to_arduino(("<1,1," + std::to_string(ui->xSpinBox->value()) + "," + std::to_string(ui->ySpinBox->value()) + "," + std::to_string(ui->zSpinBox->value()) + ">").c_str());
    }
}

void MainWindow::zero_gantry( void ) {
    write_to_arduino("<2>");
}

void MainWindow::center_gantry( void ) {
    write_to_arduino("<3>");
}

void MainWindow::update_position_UI(QStringList gantry_positions_targets) {
    ui->currentX->setText(gantry_positions_targets[0]);
    ui->currentY->setText(gantry_positions_targets[1]);
    ui->currentZ->setText(gantry_positions_targets[2]);
    ui->targetX->setText(gantry_positions_targets[3]);
    ui->targetY->setText(gantry_positions_targets[4]);
    ui->targetZ->setText(gantry_positions_targets[5]);
}

//--------------------------------------------------------------------Load Cell--------------------------------------------------------------------------------------------
void MainWindow::enableDAQ()
{
    qInfo() << "DAQ Connected";
    DAQ.enable();
    DAQ.setupTask();
}

void MainWindow::disableDAQ()
{
    qInfo() << "DAQ Disconnected";
    DAQ.stopTask();
    DAQ.disable();
}

void MainWindow::update_ATI_labels() {
    if (DAQ.isEnabled())
    {
        double* ATINanoForceTorque = DAQ.collect_data();
        ui->force_x->setNum(ATINanoForceTorque[0]);
        ui->force_y->setNum(ATINanoForceTorque[1]);
        ui->force_z->setNum(ATINanoForceTorque[2]);
        ui->torque_x->setNum(ATINanoForceTorque[3]);
        ui->torque_y->setNum(ATINanoForceTorque[4]);
        ui->torque_z->setNum(ATINanoForceTorque[5]);
    }
}

//--------------------------------------------------------------------Joystick--------------------------------------------------------------------------------------------
void MainWindow::enableJoystick(void)
{
    // Enable the controller if the checkbox is checked
    joy->enableController();
}
