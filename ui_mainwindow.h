/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QCustomPlot *plotWidget;
    QCustomPlot *resWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelScale;
    QSlider *sliderScale;
    QLabel *labelSensitivity;
    QSlider *sliderSensitivity;
    QSpacerItem *horizontalSpacer;
    QCheckBox *deletionBox;
    QPushButton *typeButton;
    QPushButton *planeButton;
    QPushButton *clearButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(978, 496);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        plotWidget = new QCustomPlot(centralwidget);
        plotWidget->setObjectName("plotWidget");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plotWidget->sizePolicy().hasHeightForWidth());
        plotWidget->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(plotWidget);

        resWidget = new QCustomPlot(centralwidget);
        resWidget->setObjectName("resWidget");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(resWidget->sizePolicy().hasHeightForWidth());
        resWidget->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(resWidget);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        labelScale = new QLabel(centralwidget);
        labelScale->setObjectName("labelScale");

        horizontalLayout_2->addWidget(labelScale);

        sliderScale = new QSlider(centralwidget);
        sliderScale->setObjectName("sliderScale");
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(sliderScale->sizePolicy().hasHeightForWidth());
        sliderScale->setSizePolicy(sizePolicy2);
        sliderScale->setMinimum(1);
        sliderScale->setMaximum(10);
        sliderScale->setSingleStep(1);
        sliderScale->setPageStep(1);
        sliderScale->setValue(5);
        sliderScale->setTracking(true);
        sliderScale->setOrientation(Qt::Horizontal);
        sliderScale->setInvertedAppearance(false);
        sliderScale->setInvertedControls(false);
        sliderScale->setTickPosition(QSlider::NoTicks);
        sliderScale->setTickInterval(0);

        horizontalLayout_2->addWidget(sliderScale);

        labelSensitivity = new QLabel(centralwidget);
        labelSensitivity->setObjectName("labelSensitivity");

        horizontalLayout_2->addWidget(labelSensitivity);

        sliderSensitivity = new QSlider(centralwidget);
        sliderSensitivity->setObjectName("sliderSensitivity");
        sizePolicy2.setHeightForWidth(sliderSensitivity->sizePolicy().hasHeightForWidth());
        sliderSensitivity->setSizePolicy(sizePolicy2);
        sliderSensitivity->setMinimum(1);
        sliderSensitivity->setMaximum(100);
        sliderSensitivity->setPageStep(5);
        sliderSensitivity->setValue(50);
        sliderSensitivity->setOrientation(Qt::Horizontal);
        sliderSensitivity->setTickPosition(QSlider::NoTicks);
        sliderSensitivity->setTickInterval(0);

        horizontalLayout_2->addWidget(sliderSensitivity);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        deletionBox = new QCheckBox(centralwidget);
        deletionBox->setObjectName("deletionBox");
        sizePolicy2.setHeightForWidth(deletionBox->sizePolicy().hasHeightForWidth());
        deletionBox->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(deletionBox);

        typeButton = new QPushButton(centralwidget);
        typeButton->setObjectName("typeButton");

        horizontalLayout_2->addWidget(typeButton);

        planeButton = new QPushButton(centralwidget);
        planeButton->setObjectName("planeButton");
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(planeButton->sizePolicy().hasHeightForWidth());
        planeButton->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(planeButton);

        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName("clearButton");
        sizePolicy2.setHeightForWidth(clearButton->sizePolicy().hasHeightForWidth());
        clearButton->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(clearButton);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 978, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Pole Zero Respnse Plotter", nullptr));
        labelScale->setText(QCoreApplication::translate("MainWindow", "Scale: 50%", nullptr));
        labelSensitivity->setText(QCoreApplication::translate("MainWindow", "Sensitivity: 50%", nullptr));
        deletionBox->setText(QCoreApplication::translate("MainWindow", "Delete by click", nullptr));
        typeButton->setText(QCoreApplication::translate("MainWindow", "Magnitude", nullptr));
        planeButton->setText(QCoreApplication::translate("MainWindow", "s-plane", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
