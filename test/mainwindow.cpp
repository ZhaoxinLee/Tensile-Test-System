#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* check serial port info for Arduino
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

    arduino->moveToThread(thread);
//    connect(arduino,SIGNAL(error(QString)),this,SLOT(errorString(QString)));
    connect(thread, SIGNAL(started()), arduino, SLOT(connect()));
    connect(arduino, SIGNAL(finished()), thread, SLOT(quit()));
    connect(arduino, SIGNAL(finished()), arduino, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    connect(ui->moveButton,SIGNAL(clicked()),SLOT(move_gantry()));
    connect(ui->centerButton,SIGNAL(clicked()),SLOT(center_gantry()));
    connect(ui->zeroButton,SIGNAL(clicked()),SLOT(zero_gantry()));
//    connect(ui->moveServo,SIGNAL(clicked()),SLOT(servoMove()));

    connect(this,SIGNAL(serial_sent(const char*)),arduino,SLOT(pass_on_to_arduino(const char*)));
    connect(arduino,SIGNAL(serial_received(QStringList)),this,SLOT(update_position_UI(QStringList)));
    thread -> start();

    connect(callbacktimer, SIGNAL(timeout()), this, SLOT(callbacks()));
    callbacktimer->start(callbackRefreshPeriod);
}

MainWindow::~MainWindow()
{
    // STOP DAQ from running
    if ( DAQ.isEnabled() )
    {
        qInfo() << "Disconnecting NI USB-DAQ.";
        DAQ.finishTask();
    }

    delete ui;
}

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

//    qDebug() << commandLine[0];

    ui->currentX->setText(gantry_positions_targets[0]);
    ui->currentY->setText(gantry_positions_targets[1]);
    ui->currentZ->setText(gantry_positions_targets[2]);
    ui->targetX->setText(gantry_positions_targets[3]);
    ui->targetY->setText(gantry_positions_targets[4]);
    ui->targetZ->setText(gantry_positions_targets[5]);
//    ui->currentServoPosition->setText(tr("%1").arg(commandLine[6]));
}
