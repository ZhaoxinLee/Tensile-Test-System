#ifndef JOYSTICK_H
#define JOYSTICK_H
#include <QtGamepad/QGamepad>
#include <QKeyEvent>
#include <QDebug>
#include <iostream>
#include <QtCore/QObject>
#include <QtCore/QTimer>
#include <QApplication>
#include <QErrorMessage>


QT_BEGIN_NAMESPACE
class QGamepad;
QT_END_NAMESPACE

class Joystick : public QObject
{
    Q_OBJECT
public:
    // joystickValues are as follows:
    // 0. Left X axis
    // 1. Left Y axis
    // 2. Right X axis
    // 3. Right Y axis
    // 4. L2 Left Trigger (Z axis)
    // 5. R2 Right Trigger (Z axis)
    const static int numAxes = 6;
    double joystickValues[numAxes] = {0.0};
    const int connectionAttempts = 12;

    bool joystickEnabled = false;

    explicit Joystick(QObject *parent = 0);
    ~Joystick();
    void enableController(void);
    void disableController(void);
    void reconnectController(void);

private:
    QGamepad *m_gamepad;

private slots:
    void leftXchanged( double value );
    void leftYchanged( double value );
    void rightXchanged( double value );
    void rightYchanged( double value );
    void buttonAchanged( bool pressed );
    void buttonBchanged( bool pressed );
    void buttonXchanged( bool pressed );
    void buttonYchanged( bool pressed );
    void buttonL1changed( bool pressed );
    void buttonR1changed( bool pressed );
    void buttonL2changed( double value );
    void buttonR2changed( double value );

signals:
    void computeFieldSignal(void);
    void changeMagnetsSignal(void); // tells the program to write to arduino -> most computationally intense
    void changeRollSignal(int);
};
#endif // JOYSTICK_H
