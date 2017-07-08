/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *ConfigTab;
    QGridLayout *gridLayout_2;
    QLabel *label_19;
    QCheckBox *checkBoxCH3;
    QLineEdit *lineEditCH3Spec;
    QCheckBox *checkBoxAlarmEmail;
    QCheckBox *checkBoxCH2;
    QLabel *label_3;
    QPushButton *pushButtonStart;
    QLabel *label;
    QLabel *label_17;
    QCheckBox *checkBoxStatusMobile;
    QLabel *label_18;
    QLabel *label_4;
    QCheckBox *checkBoxStatusEmail;
    QLineEdit *lineEditWarehouseName;
    QCheckBox *checkBoxCH1;
    QLineEdit *lineEditFlipperPort;
    QLineEdit *lineEditFlipperIP;
    QLineEdit *lineEditCH2Spec;
    QLabel *label_2;
    QLineEdit *lineEditFlipperAddr;
    QCheckBox *checkBoxAlarmMobile;
    QLineEdit *lineEditCH1Spec;
    QLabel *labelLocalIP;
    QLabel *label_5;
    QFrame *line_10;
    QFrame *line_8;
    QFrame *line;
    QFrame *line_3;
    QFrame *line_5;
    QPushButton *pushButton;
    QPushButton *buttonResetDatabase;
    QLabel *labelPublicIP;
    QLabel *label_6;
    QLineEdit *lineEditDecimalpoint;
    QPushButton *pushButton_2;
    QWidget *CH1;
    QHBoxLayout *horizontalLayout_4;
    QCustomPlot *GraphCH1;
    QWidget *CH2;
    QWidget *CH3;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 420);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 400));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMinimumSize(QSize(0, 0));
        tabWidget->setMaximumSize(QSize(16777215, 16777215));
        ConfigTab = new QWidget();
        ConfigTab->setObjectName(QStringLiteral("ConfigTab"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ConfigTab->sizePolicy().hasHeightForWidth());
        ConfigTab->setSizePolicy(sizePolicy1);
        ConfigTab->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_2 = new QGridLayout(ConfigTab);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        label_19 = new QLabel(ConfigTab);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout_2->addWidget(label_19, 10, 2, 1, 1);

        checkBoxCH3 = new QCheckBox(ConfigTab);
        checkBoxCH3->setObjectName(QStringLiteral("checkBoxCH3"));

        gridLayout_2->addWidget(checkBoxCH3, 17, 2, 1, 1);

        lineEditCH3Spec = new QLineEdit(ConfigTab);
        lineEditCH3Spec->setObjectName(QStringLiteral("lineEditCH3Spec"));

        gridLayout_2->addWidget(lineEditCH3Spec, 10, 3, 1, 1);

        checkBoxAlarmEmail = new QCheckBox(ConfigTab);
        checkBoxAlarmEmail->setObjectName(QStringLiteral("checkBoxAlarmEmail"));

        gridLayout_2->addWidget(checkBoxAlarmEmail, 15, 2, 1, 1);

        checkBoxCH2 = new QCheckBox(ConfigTab);
        checkBoxCH2->setObjectName(QStringLiteral("checkBoxCH2"));
        checkBoxCH2->setEnabled(true);
        checkBoxCH2->setCheckable(true);

        gridLayout_2->addWidget(checkBoxCH2, 17, 1, 1, 1);

        label_3 = new QLabel(ConfigTab);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 5, 2, 1, 1);

        pushButtonStart = new QPushButton(ConfigTab);
        pushButtonStart->setObjectName(QStringLiteral("pushButtonStart"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButtonStart->sizePolicy().hasHeightForWidth());
        pushButtonStart->setSizePolicy(sizePolicy2);
        pushButtonStart->setMinimumSize(QSize(250, 40));
        pushButtonStart->setMaximumSize(QSize(16777215, 300));

        gridLayout_2->addWidget(pushButtonStart, 29, 0, 1, 2);

        label = new QLabel(ConfigTab);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 7, 0, 1, 1);

        label_17 = new QLabel(ConfigTab);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_2->addWidget(label_17, 10, 0, 1, 1);

        checkBoxStatusMobile = new QCheckBox(ConfigTab);
        checkBoxStatusMobile->setObjectName(QStringLiteral("checkBoxStatusMobile"));

        gridLayout_2->addWidget(checkBoxStatusMobile, 15, 1, 1, 1);

        label_18 = new QLabel(ConfigTab);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_2->addWidget(label_18, 11, 0, 1, 1);

        label_4 = new QLabel(ConfigTab);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 5, 0, 1, 1);

        checkBoxStatusEmail = new QCheckBox(ConfigTab);
        checkBoxStatusEmail->setObjectName(QStringLiteral("checkBoxStatusEmail"));

        gridLayout_2->addWidget(checkBoxStatusEmail, 15, 0, 1, 1);

        lineEditWarehouseName = new QLineEdit(ConfigTab);
        lineEditWarehouseName->setObjectName(QStringLiteral("lineEditWarehouseName"));

        gridLayout_2->addWidget(lineEditWarehouseName, 5, 1, 1, 1);

        checkBoxCH1 = new QCheckBox(ConfigTab);
        checkBoxCH1->setObjectName(QStringLiteral("checkBoxCH1"));

        gridLayout_2->addWidget(checkBoxCH1, 17, 0, 1, 1);

        lineEditFlipperPort = new QLineEdit(ConfigTab);
        lineEditFlipperPort->setObjectName(QStringLiteral("lineEditFlipperPort"));

        gridLayout_2->addWidget(lineEditFlipperPort, 7, 3, 1, 1);

        lineEditFlipperIP = new QLineEdit(ConfigTab);
        lineEditFlipperIP->setObjectName(QStringLiteral("lineEditFlipperIP"));

        gridLayout_2->addWidget(lineEditFlipperIP, 7, 1, 1, 1);

        lineEditCH2Spec = new QLineEdit(ConfigTab);
        lineEditCH2Spec->setObjectName(QStringLiteral("lineEditCH2Spec"));

        gridLayout_2->addWidget(lineEditCH2Spec, 11, 1, 1, 1);

        label_2 = new QLabel(ConfigTab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_2, 7, 2, 1, 1);

        lineEditFlipperAddr = new QLineEdit(ConfigTab);
        lineEditFlipperAddr->setObjectName(QStringLiteral("lineEditFlipperAddr"));

        gridLayout_2->addWidget(lineEditFlipperAddr, 5, 3, 1, 1);

        checkBoxAlarmMobile = new QCheckBox(ConfigTab);
        checkBoxAlarmMobile->setObjectName(QStringLiteral("checkBoxAlarmMobile"));

        gridLayout_2->addWidget(checkBoxAlarmMobile, 15, 3, 1, 1);

        lineEditCH1Spec = new QLineEdit(ConfigTab);
        lineEditCH1Spec->setObjectName(QStringLiteral("lineEditCH1Spec"));
        lineEditCH1Spec->setMaxLength(5);

        gridLayout_2->addWidget(lineEditCH1Spec, 10, 1, 1, 1);

        labelLocalIP = new QLabel(ConfigTab);
        labelLocalIP->setObjectName(QStringLiteral("labelLocalIP"));

        gridLayout_2->addWidget(labelLocalIP, 2, 1, 1, 1);

        label_5 = new QLabel(ConfigTab);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        line_10 = new QFrame(ConfigTab);
        line_10->setObjectName(QStringLiteral("line_10"));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_10, 4, 0, 1, 4);

        line_8 = new QFrame(ConfigTab);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_8, 6, 0, 1, 4);

        line = new QFrame(ConfigTab);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 14, 0, 1, 4);

        line_3 = new QFrame(ConfigTab);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_3, 16, 0, 1, 4);

        line_5 = new QFrame(ConfigTab);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_5, 19, 0, 1, 4);

        pushButton = new QPushButton(ConfigTab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(250, 40));
        pushButton->setMaximumSize(QSize(16777215, 300));

        gridLayout_2->addWidget(pushButton, 29, 2, 1, 1);

        buttonResetDatabase = new QPushButton(ConfigTab);
        buttonResetDatabase->setObjectName(QStringLiteral("buttonResetDatabase"));
        sizePolicy.setHeightForWidth(buttonResetDatabase->sizePolicy().hasHeightForWidth());
        buttonResetDatabase->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(buttonResetDatabase, 29, 3, 1, 1);

        labelPublicIP = new QLabel(ConfigTab);
        labelPublicIP->setObjectName(QStringLiteral("labelPublicIP"));
        labelPublicIP->setMaximumSize(QSize(410, 16));
        labelPublicIP->setWordWrap(true);

        gridLayout_2->addWidget(labelPublicIP, 2, 2, 1, 2);

        label_6 = new QLabel(ConfigTab);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 11, 2, 1, 1);

        lineEditDecimalpoint = new QLineEdit(ConfigTab);
        lineEditDecimalpoint->setObjectName(QStringLiteral("lineEditDecimalpoint"));

        gridLayout_2->addWidget(lineEditDecimalpoint, 11, 3, 1, 1);

        pushButton_2 = new QPushButton(ConfigTab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_2->addWidget(pushButton_2, 17, 3, 1, 1);

        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 1);
        gridLayout_2->setColumnStretch(2, 1);
        gridLayout_2->setColumnStretch(3, 1);
        tabWidget->addTab(ConfigTab, QString());
        CH1 = new QWidget();
        CH1->setObjectName(QStringLiteral("CH1"));
        horizontalLayout_4 = new QHBoxLayout(CH1);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        GraphCH1 = new QCustomPlot(CH1);
        GraphCH1->setObjectName(QStringLiteral("GraphCH1"));

        horizontalLayout_4->addWidget(GraphCH1);

        tabWidget->addTab(CH1, QString());
        CH2 = new QWidget();
        CH2->setObjectName(QStringLiteral("CH2"));
        tabWidget->addTab(CH2, QString());
        CH3 = new QWidget();
        CH3->setObjectName(QStringLiteral("CH3"));
        tabWidget->addTab(CH3, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "CH3 Spec (Celcius):", Q_NULLPTR));
        checkBoxCH3->setText(QApplication::translate("MainWindow", "CH3", Q_NULLPTR));
        lineEditCH3Spec->setText(QApplication::translate("MainWindow", "-50", Q_NULLPTR));
        checkBoxAlarmEmail->setText(QApplication::translate("MainWindow", "Alert Email", Q_NULLPTR));
        checkBoxCH2->setText(QApplication::translate("MainWindow", "CH2", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Flipper addr:", Q_NULLPTR));
        pushButtonStart->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Flipper IP:", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "CH1 Spec (Celcius):", Q_NULLPTR));
        checkBoxStatusMobile->setText(QApplication::translate("MainWindow", "Status Mobile", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "CH2 Spec (Celcius):", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Warehouse Name:", Q_NULLPTR));
        checkBoxStatusEmail->setText(QApplication::translate("MainWindow", "Status Email", Q_NULLPTR));
        checkBoxCH1->setText(QApplication::translate("MainWindow", "CH1", Q_NULLPTR));
        lineEditFlipperPort->setText(QApplication::translate("MainWindow", "502", Q_NULLPTR));
        lineEditCH2Spec->setText(QApplication::translate("MainWindow", "-50", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Port:", Q_NULLPTR));
        lineEditFlipperAddr->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        checkBoxAlarmMobile->setText(QApplication::translate("MainWindow", "Alert Mobile", Q_NULLPTR));
        lineEditCH1Spec->setText(QApplication::translate("MainWindow", "-50", Q_NULLPTR));
        labelLocalIP->setText(QApplication::translate("MainWindow", "Local IP:", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Raspberry Pi addresses:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Test", Q_NULLPTR));
        buttonResetDatabase->setText(QApplication::translate("MainWindow", "Reset Database", Q_NULLPTR));
        labelPublicIP->setText(QApplication::translate("MainWindow", "Public IP:", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Decimalpoint (10/100/1000): ", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Quit", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(ConfigTab), QApplication::translate("MainWindow", "Configuration", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(CH1), QApplication::translate("MainWindow", "CH1", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(CH2), QApplication::translate("MainWindow", "CH2", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(CH3), QApplication::translate("MainWindow", "CH3", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
