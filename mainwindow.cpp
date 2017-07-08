#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug() << "TimeZoneOffSetToUTC: " << timeZoneOffsetToUTC() << endl;

    connect(&Flipper, SIGNAL(SIG_Measurevalue(const int&,const double&)),this,SLOT(SLOT_plotGraph(const int&, const double&)));
    connect(&Flipper,SIGNAL(SIG_Measurevalue(const int&,const double&)),this,SLOT(insertNewDataToDatabase(const int&,const double&)));
    connect(&Flipper,SIGNAL(SIG_Measurevalue(int,double)),this,SLOT(sendNewDataToOnlineDatabase(int,double)));
    connect(&Flipper, SIGNAL(SIG_sendEmailNotification(QString,double)),this,SLOT(SLOT_sendEmailTemperature(QString,double)));
    connect(&Flipper,SIGNAL(SIG_sendPushNotification(int,double)),this,SLOT(SLOT_sendPushNotification(int,double)));
    connect(&TimerForStatusNotification,SIGNAL(timeout()),this,SLOT(getStatustoSendNotification()));

    // setup TimerForStatusNotification Precision
    TimerForStatusNotification.setTimerType(Qt::CoarseTimer);
    // initialize database
    db = QSqlDatabase::addDatabase("QMYSQL");

    // get publicIp
    getPublicIP();
    // get localIP;
    getLocalIP();


    // set defaultWHname if the config don't have any
    WHname.append("GDC");
    // set default Decimal point if the config don't have any
    //ui->lineEditDecimalpoint->setValidator(new QIntValidator(0, 10000, this));

    QRegExp rx("^1{1,1}0{1,5}$");
    QValidator *validator = new QRegExpValidator(rx,this);
    ui->lineEditDecimalpoint->setValidator(validator);

    ui->lineEditDecimalpoint->setText("10");
    // set Default Decimalpoint for the FlipperInterface
    Flipper.DecimalPoint = 10;

    // check config setting file for the first time.
    checkSetting();
    //after checking the config for the first time. Initilize a timer to check for setting every minute.
    connect(&checkSettingTimer, SIGNAL(timeout()), this, SLOT(checkSetting()));
    checkSettingTimer.start(60000);


    // get address then start.
    Flipper.setFlipperaddress(ui->lineEditFlipperAddr->text().toInt());
    Flipper.start();

    initGraph();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonStart_clicked()
{
    // parse the IP and port field on the main Gui
    if( ui->lineEditFlipperIP->text() == "" || ui->lineEditFlipperPort->text() == "" || ui->lineEditFlipperAddr->text() == "")
    {
        // do something here

    }
    else
    {
        if(ui->lineEditWarehouseName->text() !="")
        {
            WHname = ui->lineEditWarehouseName->text();
        }
        // get the spec for CH1
        if(ui->lineEditCH1Spec->text() != "")
        {
            Flipper.CH1spec = ui->lineEditCH1Spec->text().toDouble();
        }
        // get the spec for CH2
        if(ui->lineEditCH2Spec->text() != "")
        {
            Flipper.CH2spec = ui->lineEditCH2Spec->text().toDouble();
        }
        // get the spec for CH3
        if(ui->lineEditCH3Spec->text() != "")
        {
            Flipper.CH3spec = ui->lineEditCH3Spec->text().toDouble();
        }


        Flipper.setFlipperaddress(ui->lineEditFlipperAddr->text().toInt());
        Flipper.setSeveraddress(ui->lineEditFlipperIP->text() , (const quint16) ui->lineEditFlipperPort->text().toInt());
        Flipper.start();
    }
}

void MainWindow::on_checkBoxCH1_clicked(bool checked)
{
    if(checked)
    {
        Flipper.CH1ON = true;
    }
    else
    {
        Flipper.CH1ON = false;
    }
}

void MainWindow::on_checkBoxCH2_clicked(bool checked)
{
    if(checked)
    {
        Flipper.CH2ON = true;
    }
    else
    {
        Flipper.CH2ON = false;
    }
}

void MainWindow::on_checkBoxCH3_clicked(bool checked)
{
    if(checked)
    {
        Flipper.CH3ON = true;
    }
    else
    {
        Flipper.CH3ON = false;
    }
}


void MainWindow::on_checkBoxStatusEmail_clicked(bool checked)
{
    Flipper.statusEmail = checked;
    // toggleStatusNotification(checked);
}

void MainWindow::on_checkBoxAlarmEmail_clicked(bool checked)
{
    Flipper.alarmEmail = checked;
}

void MainWindow::on_checkBoxStatusMobile_clicked(bool checked)
{
    Flipper.statusMobile = checked;
}

void MainWindow::on_pushButton_clicked()
{
    //    insertNewDataToDatabase(1, -20);
    //    sendPushNotification("test");
    SLOT_sendEmailTemperature("Test", -20);
}


void MainWindow::on_checkBoxAlarmMobile_clicked(bool checked)
{
    Flipper.alarmMobile = checked;
}

void MainWindow::on_checkBoxStatusEmail_clicked()
{

}

void MainWindow::on_checkBoxStatusMobile_clicked()
{

}

void MainWindow::on_buttonResetDatabase_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Warning!");
    msgBox.setInformativeText("Database CH1 will be reset.");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Cancel);
    msgBox.setIcon(QMessageBox::Critical);
    int ret = msgBox.exec();

    if(ret == QMessageBox::Ok)
    {
        // emit signal to reset here.
        qDebug() << "OK is chose" << endl;
        if(resetDatabase())
        {
            QMessageBox msgBox1;
            msgBox1.setText("Database CH1 is reset");
            msgBox1.setIcon(QMessageBox::Information);
            msgBox1.exec();

            // clear the graph
            ui->GraphCH1->clearGraphs();
            initGraph();
        }
        else
        {   QMessageBox msgBox1;
            msgBox1.setText("Database CH1 is not reset, check database connection!");
            msgBox1.setIcon(QMessageBox::Warning);
            msgBox1.exec();
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}
