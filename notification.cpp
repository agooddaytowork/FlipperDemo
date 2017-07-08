#include "mainwindow.h"
#include "ui_mainwindow.h"


#define EMAIL_SENDER_ADDRESS "alertgdc@gmail.com"
#define EMAIL_SENDER_PASSWORD "159753T@M"
#define EMAIL_CONNECTION_TIMEOUT 20000
#define EMAIL_REPONSE_TIMEOUT 10000
#define EMAIL_SENDMESSAGE_TIMEOUT 60000

#define SANJOSE_TIMEZONE -8
void MainWindow::sendPushNotification(const QString &myMSG)
{
    QStringList argo,list;
    QProcess * exec;
    exec =new QProcess(this);

    argo <<"/home/pi/SendPN/app.js";
    argo<<"--msg";
    argo<< myMSG;

    list <<"PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:";

    exec->setEnvironment(list);
    exec->setProcessChannelMode(QProcess::ForwardedChannels );
    exec->start("/usr/bin/node", argo);
    exec->waitForFinished();
}


void MainWindow::toggleStatusNotification(const bool &status)
{
    //    if(status)
    //    {
    //        connect(&TimerForStatusNotification,SIGNAL(timeout()),this,SLOT(getStatustoSendNotification()));
    //        TimerForStatusNotification.start( 14400*1000); // should be able to config this
    //    }
    //    else
    //    {
    //        TimerForStatusNotification.stop();
    //    }


}


void MainWindow::toggleAlarmNotification(const bool &status)
{

}

void MainWindow::getStatustoSendNotification()
{
    if(Flipper.statusEmail)
    {
        SLOT_sendEmailTemperature("[Update]-Dewpoint Temperature", getLatestTemperature(1));
    }
    if(Flipper.statusMobile)
    {
        SLOT_sendPushNotification(1, getLatestTemperature(1));
    }
}

void MainWindow::SLOT_sendEmailTemperature(const QString &subject, const double &value)
{
    QString timeStamp;

    if(connectToDatabase())
    {
        timeStamp = getLatestTimeStamp(1);
    }

    if(connectTodbtest())
    {

        // Get Email Addresses of receivers
        QString querrycommand;
        querrycommand.append("SELECT * FROM emailist");
        QSqlQuery query;
        query.prepare(querrycommand);
        //query.prepare("INSERT INTO CH1 (time, value) VALUES (CURRENT_TIMESTAMP(),:value)")
        if(query.exec())
        {
            while(query.next())
            {
                QStringList argo,list;
                qDebug()<< query.value(2).toString() << "\t" << query.value(1).toString() << "\n";
                QProcess * exec;
                exec =new QProcess(this);

                argo <<"/home/pi/SendPN/sendmail.js";
                argo <<"--user";
                argo <<EMAIL_SENDER_ADDRESS;
                argo <<"--pw";
                argo <<EMAIL_SENDER_PASSWORD;
                argo <<"--senderName";
                argo << WHname;
                argo <<"--mailTitle";
                argo <<WHname+"-" +subject;
                argo <<"--content";
                argo <<"Current Temperature: " + QString::number(value)+ " Celcius; TimeStamp: " + timeStamp ;
                argo <<"--receiver";
                argo <<query.value(1).toString();
                argo <<"--receiverAddress";
                argo <<query.value(2).toString();

                list <<"PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:";

                exec->setEnvironment(list);
                exec->setProcessChannelMode(QProcess::ForwardedChannels );
                exec->start("/usr/bin/node", argo);
                exec->waitForFinished();
            }
        }
        else
        {
            qDebug()<< "could not get email addressed" << endl;
            return;
        }
    }
}

void MainWindow::SLOT_sendPushNotification(const int &chanel, const double &val)
{
    QString  Mgs;
    Mgs.append("CH");
    Mgs.append(chanel);
    Mgs.append(" : ");
    Mgs.append(QString::number(val));
    Mgs.append(" Celcius");

    sendPushNotification(Mgs);
}

qint8 MainWindow::timeZoneOffsetToUTC()
{
    const QDateTime dateTime1 = QDateTime::currentDateTime();
    const QDateTime dateTime2 = QDateTime(dateTime1.date(), dateTime1.time(), Qt::UTC);
    return dateTime1.secsTo(dateTime2) / 3600;

}

void MainWindow::checkSetting()
{
    static bool firstChecked = false;
    QFile file(FLIPPER_CONFIG_PATH);
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Cannot open config file" << endl;
    }


    QString Settings = file.readLine();

    // close the file after reading
    file.close();
    QStringList SettingList = Settings.split(",");

    if(SettingList.count() == 20)
    {
        qDebug() << SettingList.at(19);
        if(SettingList.at(19) == "1\n" || !firstChecked || QString::compare(SettingList.at(2), publicIp,Qt::CaseInsensitive)!=0)
        {
            firstChecked = true;
            QString IP = SettingList.at(3);
            QString Port = SettingList.at(4);
            QString SpecCH1 = SettingList.at(5);
            QString SpecCH2 = SettingList.at(6);
            QString SpecCH3 = SettingList.at(7);
            QString NotiEmail = SettingList.at(8);
            QString NotiMobile = SettingList.at(9);
            QString AlertEmail = SettingList.at(10);
            QString AlertMobile = SettingList.at(11);
            QString OpenCH1 = SettingList.at(12);
            QString OpenCH2 = SettingList.at(13);
            QString OpenCH3 = SettingList.at(14);
            QString Hour = SettingList.at(15);
            QString Min = SettingList.at(16);
            QString Sec = SettingList.at(17);
            QString DecimalPoint = SettingList.at(18);
            QString WarehouseName = SettingList.at(0);

            //            QString localIP = SettingList.at(1);
            //            QString publicIP = SettingList.at(2);

            // update new Notification Time

            QTime TimeToSendNotification = QTime(Hour.toInt(), Min.toInt(), Sec.toInt(),0);
            QTime currentTime = QTime::currentTime();


            // get Currentime in UTC time

            // calculate the seconds to the first notification
            int secTonotification = currentTime.secsTo(TimeToSendNotification);


            if(secTonotification < 0)
                secTonotification = qAbs(secTonotification) + 87840;

            qDebug() << "Time to first notification: "<< secTonotification << endl;

            WHname = WarehouseName;
            Flipper.CH1spec = SpecCH1.toDouble();
            Flipper.CH2spec = SpecCH2.toDouble();
            Flipper.CH3spec = SpecCH3.toDouble();

            if(NotiEmail == "1") Flipper.statusEmail = true; else Flipper.statusEmail = false;
            if(NotiMobile == "1") Flipper.statusMobile = true; else Flipper.statusMobile = false;
            if(AlertEmail == "1") Flipper.alarmEmail = true; else Flipper.alarmEmail = false;
            if(AlertMobile == "1") Flipper.alarmMobile = true; else Flipper.alarmMobile = false;
            if(OpenCH1 == "1") Flipper.CH1ON = true; else Flipper.CH1ON = false;
            if(OpenCH2 == "1") Flipper.CH2ON = true; else Flipper.CH2ON = false;
            if(OpenCH3 == "1") Flipper.CH3ON = true; else Flipper.CH3ON = false;

            Flipper.DecimalPoint = DecimalPoint.toInt();
            // if secToNotification < 0, add one more day before the first notification occur
            // create a single shot timer to trigger the first notification
            // the next notification will be the next 24 hours

            if(Flipper.CH1ON || Flipper.CH2ON || Flipper.CH3ON)
            {
                FirstNotificationTimer.stop();
                TimerForStatusNotification.stop();
                FirstNotificationTimer.singleShot(secTonotification*1000,this,SLOT(sendFirstNotification()));
            }

            // update config to UI

            ui->lineEditCH1Spec->setText(SpecCH1);
            ui->lineEditCH2Spec->setText(SpecCH2);
            ui->lineEditCH3Spec->setText(SpecCH3);

            ui->checkBoxCH1->setChecked(Flipper.CH1ON);
            ui->checkBoxCH2->setChecked(Flipper.CH2ON);
            ui->checkBoxCH3->setChecked(Flipper.CH3ON);

            ui->checkBoxAlarmEmail->setChecked(Flipper.alarmEmail);
            ui->checkBoxAlarmMobile->setChecked(Flipper.alarmMobile);
            ui->checkBoxStatusEmail->setChecked(Flipper.statusEmail);
            ui->checkBoxStatusMobile->setChecked(Flipper.statusMobile);

            ui->lineEditWarehouseName->setText(WHname);

            ui->lineEditDecimalpoint->setText(QString::number(Flipper.DecimalPoint));

            // write the 19th element back to 0
            if(QString::compare(IP,Flipper._serverIp) != 0)
            {
                Flipper.setSeveraddress(IP, Port.toInt());
                //  need to reconnect the shit out of the flipper
                ui->lineEditFlipperIP->setText(IP);
                ui->lineEditFlipperPort->setText(Port);
                Flipper.setFlipperaddress(ui->lineEditFlipperAddr->text().toInt());
                Flipper.start();

                qDebug() << "New Flipper IP and Ports, Start new connections";
            }
            QString newSetting;

            newSetting.append(WHname+",");  //0
            newSetting.append(localIp + ","); //1
            newSetting.append(publicIp + ",");//2
            for (int i = 3; i < 19; i++)
            {
                newSetting.append(SettingList.at(i));
                newSetting.append(",");
            }
            newSetting.append("0");

            qDebug() << newSetting << endl;
            if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
            {
                qDebug() << "Cannot open config file" << endl;
            }
            else
            {
                QTextStream output(&file);
                output << newSetting;
                qDebug()  << "file written" << endl;
                file.close();
            }

        }

    }

    file.close();
}


void MainWindow::sendFirstNotification()
{

    qDebug() << "SLOT_sendFirstNotification" << endl;
    // get the latest temperature

    // check if Notification per Email/Mobile is set
    if(Flipper.statusEmail)
    {
        SLOT_sendEmailTemperature("-[Update]-Dewpoint Temperature", getLatestTemperature(1));
        qDebug() << "Sent email Notification"<< endl;
    }
    if(Flipper.statusMobile)
    {
        SLOT_sendPushNotification(1, getLatestTemperature(1));
        qDebug() << "Sent Mobile Notification" << endl;
    }
    // send the notification


    // trigger the periodic notification

    TimerForStatusNotification.start(1440*60*1000); // 24 hours period
}


void MainWindow::getLocalIP()
{
    QTcpSocket socket;
    QEventLoop aloop;
    QTimer aTempTimer;
    connect(&socket, SIGNAL(connected()), &aloop, SLOT(quit()));
    aTempTimer.singleShot(1000, &aloop, SLOT(quit()));

    socket.connectToHost("8.8.8.8", 53); // google DNS, or something else reliable
    aloop.exec();
    if(socket.localAddress().toString() != "")
    {
        ui->labelLocalIP->setText("Local IP: " + socket.localAddress().toString());
        localIp.clear();
        localIp.append(socket.localAddress().toString());
    }
    else
        ui->labelLocalIP->setText("Local IP not found");

}

void MainWindow::getPublicIP()
{
    QNetworkAccessManager *accessManager = new QNetworkAccessManager(this);


    QNetworkReply *reply = accessManager->get(QNetworkRequest(QUrl("http://httpbin.org/ip")));

    connect(accessManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(SLOT_getPublicIP(QNetworkReply*)));


}

void MainWindow::SLOT_getPublicIP(QNetworkReply *reply)
{

    if(reply->error() == QNetworkReply::NoError)
    {
        QByteArray TmpArray(reply->readAll());
        //TmpArray = TmpArray.mid(15,13);
        TmpArray = TmpArray.remove(0,15);
        uint8_t counter = 0;
        QByteArray tempPublicIp;
        while(TmpArray.at(counter) != 0x22 && counter < TmpArray.length())
        {
            tempPublicIp.append(TmpArray.at(counter));
            counter++;
        }

        publicIp.clear();
        publicIp.append(tempPublicIp);
        ui->labelPublicIP->setText("Public IP: " + tempPublicIp);
    }
    else
    {
        ui->labelPublicIP->setText("Public IP not found");
    }
    reply->deleteLater();

}
