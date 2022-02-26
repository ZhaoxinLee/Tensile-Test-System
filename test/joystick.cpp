#include "Joystick.h"

Joystick::Joystick(QObject *parent) : QObject(parent) , m_gamepad(nullptr)
{

}

Joystick::~Joystick()
{
    qInfo() << "Disconnecting game controller...";
    delete m_gamepad;
}

void Joystick::enableController(void)
{
    // Unused buttons are commented out here and in disableController

    connect(m_gamepad, &QGamepad::axisLeftXChanged,  this, &Joystick::leftXchanged);
    connect(m_gamepad, &QGamepad::axisLeftYChanged,  this, &Joystick::leftYchanged);
    connect(m_gamepad, &QGamepad::axisRightXChanged, this, &Joystick::rightXchanged);
    connect(m_gamepad, &QGamepad::axisRightYChanged, this, &Joystick::rightYchanged);
    connect(m_gamepad, &QGamepad::buttonAChanged,  this, &Joystick::buttonAchanged);
    connect(m_gamepad, &QGamepad::buttonBChanged,  this, &Joystick::buttonBchanged);
    connect(m_gamepad, &QGamepad::buttonXChanged,  this, &Joystick::buttonXchanged);
    connect(m_gamepad, &QGamepad::buttonYChanged,  this, &Joystick::buttonYchanged);
    connect(m_gamepad, &QGamepad::buttonL1Changed, this, &Joystick::buttonL1changed);
    connect(m_gamepad, &QGamepad::buttonR1Changed, this, &Joystick::buttonR1changed);
    connect(m_gamepad, &QGamepad::buttonL2Changed, this, &Joystick::buttonL2changed);
    connect(m_gamepad, &QGamepad::buttonR2Changed, this, &Joystick::buttonR2changed);
//    connect(m_gamepad, &QGamepad::buttonSelectChanged, this, &Joystick::buttonSelectchanged);
//    connect(m_gamepad, &QGamepad::buttonStartChanged,  this, &Joystick::buttonStartchanged);
//    connect(m_gamepad, &QGamepad::buttonGuideChanged,  this, &Joystick::buttonGuidechanged);

    joystickEnabled = true;
}
void Joystick::disableController(void)
{
    disconnect(m_gamepad, &QGamepad::axisLeftXChanged,  this, &Joystick::leftXchanged);
    disconnect(m_gamepad, &QGamepad::axisLeftYChanged,  this, &Joystick::leftYchanged);
    disconnect(m_gamepad, &QGamepad::axisRightXChanged, this, &Joystick::rightXchanged);
    disconnect(m_gamepad, &QGamepad::axisRightYChanged, this, &Joystick::rightYchanged);
    disconnect(m_gamepad, &QGamepad::buttonAChanged,  this, &Joystick::buttonAchanged);
    disconnect(m_gamepad, &QGamepad::buttonBChanged,  this, &Joystick::buttonBchanged);
    disconnect(m_gamepad, &QGamepad::buttonXChanged,  this, &Joystick::buttonXchanged);
    //disconnect(m_gamepad, &QGamepad::buttonYChanged,  this, &Joystick::buttonYchanged);
    disconnect(m_gamepad, &QGamepad::buttonL1Changed, this, &Joystick::buttonL1changed);
    disconnect(m_gamepad, &QGamepad::buttonR1Changed, this, &Joystick::buttonR1changed);
    disconnect(m_gamepad, &QGamepad::buttonL2Changed, this, &Joystick::buttonL2changed);
    disconnect(m_gamepad, &QGamepad::buttonR2Changed, this, &Joystick::buttonR2changed);
    //disconnect(m_gamepad, &QGamepad::buttonSelectChanged, this, &Joystick::buttonSelectchanged);
    //disconnect(m_gamepad, &QGamepad::buttonStartChanged,  this, &Joystick::buttonStartchanged);
    //disconnect(m_gamepad, &QGamepad::buttonGuideChanged,  this, &Joystick::buttonGuidechanged);

    joystickEnabled = false;
    // For a disabled controller, all joystick values are defaulted to zero.
    for (int i=0; i<numAxes; i++)
    {
        joystickValues[i] = 0.0;
    }
}

void Joystick::reconnectController(void)
{
    qInfo() << " ";
    qInfo() << "Attempting to establish game controller connection:";

    // Gamepad Configuration coded by Sumanth Kandala to work on Windows OS
    QGamepadManager* gamepad_manager = QGamepadManager::instance();
    QList<int> gamepads;
    int i = 0;
    qInfo() << "Checking connected ports for connected game controllers (Max. " << connectionAttempts << " trials)";
    while (i < connectionAttempts)
    {
        QApplication::processEvents();
        qInfo() << "Searching for connected gamepads iteration number : " << i+1;
        gamepads = gamepad_manager->connectedGamepads();
        if(!gamepads.isEmpty())
        {
            // If found a controller then exit out early
            i = connectionAttempts;
        } else
        {
            qWarning() << "No Controller connection detected ...";
        }
        i++;
    }
    qInfo() << "Number of connected gamepads : " << gamepads.size();
    if (gamepads.isEmpty())
    {
        qWarning() << "No Controller connection detected. Plug in controller before attempting to reconnect.";
        qInfo() << "Check that the controller is responding by going to Control Panel/Hardware and Sound/Devices and Printers/Game Controller Settings.";
        return;
    }
    m_gamepad = new QGamepad(*gamepads.begin(), this);
}

// ------------------------------------- SLOTS -------------------------------------//

void Joystick::leftXchanged( double value )
{
    qDebug() << "Left X" << value;
    joystickValues[0] = value;
}

void Joystick::leftYchanged( double value )
{
    qDebug() << "Left Y" << value;
    joystickValues[1] = value;
}

void Joystick::rightXchanged( double value )
{
    qDebug() << "Right X" << value;
    joystickValues[2] = value;
}

void Joystick::rightYchanged( double value )
{
    qDebug() << "Right Y" << value;
    joystickValues[3] = value;
}

void Joystick::buttonAchanged( bool pressed )
{
    qDebug() << "Button A" << pressed;
    if (pressed)
    {
//        connectedWindow->ToolOUT_press_Slot();
    }
    else
    {
//        connectedWindow->ToolINOUT_rel_Slot();
    }

}

void Joystick::buttonBchanged( bool pressed )
{
    qDebug() << "Button B" << pressed;
}

void Joystick::buttonXchanged( bool pressed )
{
    // Tool in fast
    qDebug() << "Button X" << pressed;
    if (pressed)
    {
//        connectedWindow->ToolIN_press_Slot();
    }
    else
    {
//        connectedWindow->ToolINOUT_rel_Slot();
    }
}

void Joystick::buttonYchanged( bool pressed )
{
    qDebug() << "Button Y" << pressed;
    // Show the current controller state in terminal
//    qDebug() << connectedWindow->currentControllerMode;
}

void Joystick::buttonL1changed( bool pressed )
{
    qDebug() << "Button L1" << pressed;
    if ( pressed )
    {
//        connectedWindow->roll_dir = -1;
//        emit changeRollSignal(-1);
    }
    else
    {
//        connectedWindow->roll_dir = 0;
//        emit changeRollSignal(0);
    }

}

void Joystick::buttonR1changed( bool pressed )
{
    qDebug() << "Button R1" << pressed;
    if ( pressed )
    {
//        connectedWindow->roll_dir = 1;
//        emit changeRollSignal(1);
    }
    else
    {
//        connectedWindow->roll_dir = 0;
//        emit changeRollSignal(0);
    }

}

void Joystick::buttonL2changed( double value )
{
//    qDebug() << "Button L2: " << value;
    joystickValues[4] = value;
}

void Joystick::buttonR2changed( double value )
{
//    qDebug() << "Button R2: " << value;
    joystickValues[5] = value;
}
