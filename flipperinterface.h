#ifndef FLIPPERINTERFACE_H
#define FLIPPERINTERFACE_H

#include <QTcpSocket>
#include <QtNetwork>
#include <QDataStream>
#include <QTimer>

#define FLIPPER_SERVERTIMEOUT 2000

#define FLIPPER_CH1_MEASURE_RELATIVE_ADDR 0x0064
#define FLIPPER_CH2_MEASURE_RELATIVE_ADDR 0x0065
#define FLIPPER_CH3_MEASURE_RELATIVE_ADDR 0x0066
#define FLIPPER_CH4_MEASURE_RELATIVE_ADDR 0x0068
#define FLIPPER_CH5_MEASURE_RELATIVE_ADDR 0x0069
#define FLIPPER_CH6_MEASURE_RELATIVE_ADDR 0x006A
#define FLIPPER_READOUTWORDNUMBER_MEASURECOMMAND 0x0001


#define FLIPPER_DATAUPDATE_RATE 60000 // ms
#define FLIPPER_DECIMAL_VALUE 100

class flipperinterface : public QObject
{

   Q_OBJECT
public:
    flipperinterface(QObject *parent = 0);
    ~flipperinterface();
    void testconnection(QString &_serverIp, const quint16 &_serverPort);

    bool CH1ON = false;
    bool CH2ON = false;
    bool CH3ON = false;
    double CH1spec = 0;
    double CH2spec = 0;
    double CH3spec = 0;
    bool alarmNotification = false;
    bool alarmEmail = false;
    bool alarmMobile = false;
    bool statusEmail = false;
    bool statusMobile = false;
    bool statusNotification = false;
    bool sentAlarmNotification = false;

    int DecimalPoint;
    int currentCH = 0;
    QString _serverIp;
    quint16   _serverPort;

    void setSeveraddress(const QString &IP, const quint16 &PORT);
    void setFlipperaddress(const qint16 &addr);
public slots:

    void start();
    void readPacket();
    void flipper_S_ConnectedtoServer();
    void SLOT_flipper_serverTimeout();
    void taskGetMeasuredValues();

signals:
    void flipperServerConnected();
    void flipperServerNotConnected();
    void SIG_flipper_readMeasureValue();
    void SIG_Measurevalue(const int &chanel, const double &val);
    void SIG_sendPushNotification(const int &chanel, const double &val);
    void SIG_sendEmailNotification(const QString &subject, const double &val);
private:

    qint16   _flipperAddr;
    QTcpSocket *tcpSocket;
    QDataStream in;


QByteArray generateCommmandMessage(qint16 StationNO,qint16 FunctionCode, qint32 relativeAddr, qint32 readoutWordnumber);


    bool ConnetedtoSever = false;

    QTimer performTaskTimer;
};

#endif // FLIPPERINTERFACE_H
