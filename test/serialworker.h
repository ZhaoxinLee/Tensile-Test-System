#ifndef SERIALWORKER_H
#define SERIALWORKER_H

#include <QObject>
#include <QDebug>

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

class serialworker : public QObject
{
    Q_OBJECT

public:
    serialworker();
    ~serialworker() override;

    QStringList positionData;

private:
    QSerialPort *arduino = nullptr;
    static const quint16 arduino_vendor_id = 9025;
    static const quint16 arduino_product_id = 66;

    bool arduino_is_available = false;
    QString arduino_port_name;

    QByteArray rolling_arduino_serial_store;
    QByteArray raw_arduino_serial_read;
    QString arduino_serial;
    QStringList gantry_positions_targets;

    char startMarker = '<';
    char endMarker = '>';
    int start_marker_ndx, end_marker_ndx;

    bool potential_full_command;

public slots:
    void connect( void );
    void pass_on_to_arduino( const char *commandLine );
    void parse_arduino_serial( void );

signals:
    void finished();
    void error(QString err);
    void serial_received(QStringList);
};

#endif // SERIALWORKER_H
