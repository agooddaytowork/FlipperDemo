#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "flipperinterface.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QEventLoop>
#include <QProcess>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QTime>

#define FLIPPER_CONFIG_PATH "/var/www/html/config.csv"

#include <QTcpSocket>
#include <QHostAddress>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUrl>

//#include <QJsonObject>
//#include <QJsonArray>
//#include <QJsonDocument>
#include <QNetworkRequest>
#include <QUrl>
#include <QNetworkAccessManager>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void SLOT_plotGraph(const int &CH,const double &value);
private slots:
    void on_pushButtonStart_clicked();

    void on_checkBoxCH1_clicked(bool checked);

    void on_checkBoxCH2_clicked(bool checked);

    void on_checkBoxCH3_clicked(bool checked);

    bool insertNewDataToDatabase(const int &CH, const double &value);
    void sendNewDataToOnlineDatabase(const int &CH, const double &value);
    void on_checkBoxStatusEmail_clicked(bool checked);

    void on_checkBoxAlarmEmail_clicked(bool checked);

    void getStatustoSendNotification();

    void SLOT_sendEmailTemperature(const QString &subject, const double &value);
    void SLOT_sendPushNotification(const int &chanel, const double &val);
    void on_pushButton_clicked();

    void on_checkBoxStatusEmail_clicked();
    void checkSetting();

    void on_checkBoxStatusMobile_clicked(bool checked);

    void on_checkBoxStatusMobile_clicked();

    void on_checkBoxAlarmMobile_clicked(bool checked);

    // slot for execute the first notification, then trigger the series of notifications
    void sendFirstNotification();
    void SLOT_getPublicIP(QNetworkReply *reply);
    void on_buttonResetDatabase_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    flipperinterface Flipper;

    QSqlDatabase db;
    void initGraph();
    bool connectToDatabase();
    bool connectTodbtest();
    QString Name1;
    QString Name2;

    QString EmailAddress1;
    QString EmailAddress2;

    void sendPushNotification(const QString &myMSG);
    void toggleStatusNotification(const bool &status);
    void toggleAlarmNotification(const bool &status);
    double getLatestTemperature(const int &CH);
    QString getLatestTimeStamp(const int CH);
    void getLocalIP();
    void getPublicIP();
    bool resetDatabase();
    qint8 timeZoneOffsetToUTC();


    QTimer TimerForStatusNotification;
    QTimer checkSettingTimer;
    QTimer FirstNotificationTimer;
    QString FlipperIP;
    QString WHname;
    QString localIp;
    QString publicIp;


};

#endif // MAINWINDOW_H
