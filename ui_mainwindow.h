/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *setX;
    QSpinBox *xSpinBox;
    QSpinBox *zSpinBox;
    QSpinBox *ySpinBox;
    QFrame *frame;
    QLabel *targetY;
    QLabel *targetZ;
    QLabel *currentZ;
    QLabel *currentY;
    QLabel *z;
    QLabel *y;
    QLabel *currentX;
    QLabel *targetX;
    QLabel *x;
    QLabel *targetLabel;
    QLabel *currentLabel;
    QLabel *setZ;
    QLabel *setY;
    QPushButton *moveButton;
    QRadioButton *relativeRadio;
    QPushButton *zeroButton;
    QPushButton *centerButton;
    QRadioButton *absoluteRadio;
    QWidget *tab_2;
    QSpinBox *positionSpinBox;
    QLabel *servoPositionLabel;
    QLabel *servoSpeedLabel;
    QSpinBox *speedSpinBox;
    QPushButton *moveServo;
    QLabel *currentServoPositionLabel;
    QLabel *currentServoPosition;
    QWidget *tab_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(739, 470);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 341, 281));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        setX = new QLabel(tab);
        setX->setObjectName(QString::fromUtf8("setX"));
        setX->setGeometry(QRect(10, 130, 31, 20));
        xSpinBox = new QSpinBox(tab);
        xSpinBox->setObjectName(QString::fromUtf8("xSpinBox"));
        xSpinBox->setGeometry(QRect(60, 130, 91, 20));
        xSpinBox->setMinimum(-1000000);
        xSpinBox->setMaximum(1000000);
        xSpinBox->setSingleStep(1000);
        zSpinBox = new QSpinBox(tab);
        zSpinBox->setObjectName(QString::fromUtf8("zSpinBox"));
        zSpinBox->setGeometry(QRect(60, 210, 91, 22));
        zSpinBox->setMinimum(-1000000);
        zSpinBox->setMaximum(1000000);
        zSpinBox->setSingleStep(1000);
        ySpinBox = new QSpinBox(tab);
        ySpinBox->setObjectName(QString::fromUtf8("ySpinBox"));
        ySpinBox->setGeometry(QRect(60, 170, 91, 22));
        ySpinBox->setMinimum(-1000000);
        ySpinBox->setMaximum(1000000);
        ySpinBox->setSingleStep(1000);
        frame = new QFrame(tab);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 300, 80));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        targetY = new QLabel(frame);
        targetY->setObjectName(QString::fromUtf8("targetY"));
        targetY->setGeometry(QRect(160, 60, 47, 13));
        targetZ = new QLabel(frame);
        targetZ->setObjectName(QString::fromUtf8("targetZ"));
        targetZ->setGeometry(QRect(230, 60, 47, 13));
        currentZ = new QLabel(frame);
        currentZ->setObjectName(QString::fromUtf8("currentZ"));
        currentZ->setGeometry(QRect(230, 30, 47, 13));
        currentY = new QLabel(frame);
        currentY->setObjectName(QString::fromUtf8("currentY"));
        currentY->setGeometry(QRect(160, 30, 47, 13));
        z = new QLabel(frame);
        z->setObjectName(QString::fromUtf8("z"));
        z->setGeometry(QRect(230, 10, 47, 13));
        z->setAlignment(Qt::AlignCenter);
        y = new QLabel(frame);
        y->setObjectName(QString::fromUtf8("y"));
        y->setGeometry(QRect(160, 10, 47, 13));
        y->setAlignment(Qt::AlignCenter);
        currentX = new QLabel(frame);
        currentX->setObjectName(QString::fromUtf8("currentX"));
        currentX->setGeometry(QRect(90, 30, 47, 13));
        targetX = new QLabel(frame);
        targetX->setObjectName(QString::fromUtf8("targetX"));
        targetX->setGeometry(QRect(90, 60, 47, 13));
        x = new QLabel(frame);
        x->setObjectName(QString::fromUtf8("x"));
        x->setGeometry(QRect(90, 10, 47, 13));
        x->setLayoutDirection(Qt::LeftToRight);
        x->setAlignment(Qt::AlignCenter);
        targetLabel = new QLabel(frame);
        targetLabel->setObjectName(QString::fromUtf8("targetLabel"));
        targetLabel->setGeometry(QRect(20, 60, 47, 13));
        currentLabel = new QLabel(frame);
        currentLabel->setObjectName(QString::fromUtf8("currentLabel"));
        currentLabel->setGeometry(QRect(20, 30, 47, 13));
        setZ = new QLabel(tab);
        setZ->setObjectName(QString::fromUtf8("setZ"));
        setZ->setGeometry(QRect(10, 210, 31, 16));
        setY = new QLabel(tab);
        setY->setObjectName(QString::fromUtf8("setY"));
        setY->setGeometry(QRect(10, 170, 31, 20));
        moveButton = new QPushButton(tab);
        moveButton->setObjectName(QString::fromUtf8("moveButton"));
        moveButton->setGeometry(QRect(200, 210, 80, 21));
        relativeRadio = new QRadioButton(tab);
        relativeRadio->setObjectName(QString::fromUtf8("relativeRadio"));
        relativeRadio->setGeometry(QRect(90, 100, 84, 19));
        zeroButton = new QPushButton(tab);
        zeroButton->setObjectName(QString::fromUtf8("zeroButton"));
        zeroButton->setGeometry(QRect(200, 110, 80, 21));
        centerButton = new QPushButton(tab);
        centerButton->setObjectName(QString::fromUtf8("centerButton"));
        centerButton->setGeometry(QRect(200, 160, 80, 21));
        absoluteRadio = new QRadioButton(tab);
        absoluteRadio->setObjectName(QString::fromUtf8("absoluteRadio"));
        absoluteRadio->setGeometry(QRect(10, 100, 84, 19));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        positionSpinBox = new QSpinBox(tab_2);
        positionSpinBox->setObjectName(QString::fromUtf8("positionSpinBox"));
        positionSpinBox->setGeometry(QRect(90, 20, 81, 25));
        positionSpinBox->setMaximum(1023);
        servoPositionLabel = new QLabel(tab_2);
        servoPositionLabel->setObjectName(QString::fromUtf8("servoPositionLabel"));
        servoPositionLabel->setGeometry(QRect(10, 25, 55, 16));
        servoSpeedLabel = new QLabel(tab_2);
        servoSpeedLabel->setObjectName(QString::fromUtf8("servoSpeedLabel"));
        servoSpeedLabel->setGeometry(QRect(10, 75, 55, 16));
        speedSpinBox = new QSpinBox(tab_2);
        speedSpinBox->setObjectName(QString::fromUtf8("speedSpinBox"));
        speedSpinBox->setGeometry(QRect(90, 70, 81, 25));
        moveServo = new QPushButton(tab_2);
        moveServo->setObjectName(QString::fromUtf8("moveServo"));
        moveServo->setGeometry(QRect(50, 140, 80, 25));
        currentServoPositionLabel = new QLabel(tab_2);
        currentServoPositionLabel->setObjectName(QString::fromUtf8("currentServoPositionLabel"));
        currentServoPositionLabel->setGeometry(QRect(20, 180, 101, 21));
        currentServoPosition = new QLabel(tab_2);
        currentServoPosition->setObjectName(QString::fromUtf8("currentServoPosition"));
        currentServoPosition->setGeometry(QRect(270, 60, 101, 21));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        label = new QLabel(tab_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 70, 47, 13));
        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 110, 47, 13));
        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 160, 47, 13));
        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(80, 70, 47, 13));
        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(80, 110, 47, 13));
        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(80, 160, 47, 13));
        tabWidget->addTab(tab_3, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 739, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        setX->setText(QCoreApplication::translate("MainWindow", "Set x", nullptr));
        targetY->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        targetZ->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        currentZ->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        currentY->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        z->setText(QCoreApplication::translate("MainWindow", "z", nullptr));
        y->setText(QCoreApplication::translate("MainWindow", "y", nullptr));
        currentX->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        targetX->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        x->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        targetLabel->setText(QCoreApplication::translate("MainWindow", "Target", nullptr));
        currentLabel->setText(QCoreApplication::translate("MainWindow", "Current", nullptr));
        setZ->setText(QCoreApplication::translate("MainWindow", "Set z", nullptr));
        setY->setText(QCoreApplication::translate("MainWindow", "Set y", nullptr));
        moveButton->setText(QCoreApplication::translate("MainWindow", "Move", nullptr));
        relativeRadio->setText(QCoreApplication::translate("MainWindow", "Relative", nullptr));
        zeroButton->setText(QCoreApplication::translate("MainWindow", "Zero", nullptr));
        centerButton->setText(QCoreApplication::translate("MainWindow", "Center", nullptr));
        absoluteRadio->setText(QCoreApplication::translate("MainWindow", "Absolute", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Gantry", nullptr));
        servoPositionLabel->setText(QCoreApplication::translate("MainWindow", "Position", nullptr));
        servoSpeedLabel->setText(QCoreApplication::translate("MainWindow", "Speed", nullptr));
        moveServo->setText(QCoreApplication::translate("MainWindow", "Move", nullptr));
        currentServoPositionLabel->setText(QCoreApplication::translate("MainWindow", "Current Position", nullptr));
        currentServoPosition->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Servo", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Fx", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Fy", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Fz", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Load", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
