#include <serialworker.h>

serialworker::serialworker() {
    arduino = new QSerialPort(this);
}

serialworker::~serialworker() {
    if (arduino->isOpen()) {
        arduino->close();
    }
}

void serialworker::connect( void ) {
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        //  check if the serialport has both a product identifier and a vendor identifier
        if (serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier()) {
            //  check if the product ID and the vendor ID match those of the arduino uno
            if((serialPortInfo.productIdentifier() == arduino_product_id)
                    && (serialPortInfo.vendorIdentifier() == arduino_vendor_id)) {
                arduino_is_available = true; //    arduino uno is available on this port
                arduino_port_name = serialPortInfo.portName();
            }
        }
    }

    if (arduino_is_available){
        qDebug() << "Found the arduino port...\n";
        arduino->setPortName(arduino_port_name);
        arduino->open(QSerialPort::ReadWrite);
        arduino->setBaudRate(QSerialPort::Baud115200);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        QObject::connect(arduino, SIGNAL(readyRead()), this, SLOT(parse_arduino_serial()));
    } else {
        qDebug() << "Couldn't find the correct port for the arduino.\n";
        emit finished();
    }
}

void serialworker::parse_arduino_serial( void ) {

    raw_arduino_serial_read = arduino->readAll();
//    qDebug() << raw_arduino_serial_read;

    rolling_arduino_serial_store.append(raw_arduino_serial_read);

    if (rolling_arduino_serial_store.contains(startMarker) && rolling_arduino_serial_store.contains(endMarker)) {
        for (int i = rolling_arduino_serial_store.size() - 1; i >= 0; --i) {
            if (rolling_arduino_serial_store.at(i) == endMarker) {
                end_marker_ndx = i;
                potential_full_command = true;
            } else if (rolling_arduino_serial_store.at(i) == startMarker) {
                if (potential_full_command) {
                    start_marker_ndx = i;
                }
                break;
            } else {
                continue;
            }
        }
    }

    if (potential_full_command) {
        arduino_serial = QString(rolling_arduino_serial_store.mid(start_marker_ndx + 1,end_marker_ndx - start_marker_ndx - 1));
        gantry_positions_targets = arduino_serial.split(',');
        potential_full_command = false;
        emit serial_received(gantry_positions_targets);
    }
//    if (rollingserial.contains(startMarker) && rollingserial.contains(endMarker)) {
//        int startMarkerIndex = rollingserial.indexOf(startMarker);
//        int endMarkerIndex = rollingserial.indexOf(endMarker);

//        QString newPosition = QString(rollingserial.mid(startMarkerIndex+1,endMarkerIndex-startMarkerIndex));
//        positionData = newPosition.split(',');
//    }
}

void serialworker::pass_on_to_arduino( const char *commandLine ) {
    arduino->write(commandLine);
}
