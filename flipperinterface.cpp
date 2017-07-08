#include "flipperinterface.h"

flipperinterface::flipperinterface(QObject *parent)
{
    // initialize the private parameters
    _serverIp = "localhost";
    _serverPort = 502;
    _flipperAddr = 1;

    QByteArray sendArray = generateCommmandMessage(1,0x04,0x0065,0x0001);
    int i = 1;

    //Initialize the Tcp Socket with the instance name tcpSocket;
    tcpSocket = new QTcpSocket(this);

    // connect some SIGNAL and SLOTS to do the jobs
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readPacket()));
    connect (tcpSocket, SIGNAL(connected()),this,SLOT(flipper_S_ConnectedtoServer()));

    connect(&performTaskTimer,SIGNAL(timeout()),this,SLOT(taskGetMeasuredValues()));

}

void flipperinterface::testconnection(QString &_serverIp, const quint16 &_serverPort)
{

    QEventLoop loop;
    QTimer timeoutTimer;
    tcpSocket->abort();
    tcpSocket->connectToHost(_serverIp, _serverPort);

    connect(tcpSocket,SIGNAL(connected()),&loop,SLOT(quit()));
    timeoutTimer.singleShot(FLIPPER_SERVERTIMEOUT,&loop,SLOT(quit()));
    loop.exec();

    if(!ConnetedtoSever)
    {
        // do some shit here
        // emit some signal to inform the gui for example

        emit flipperServerNotConnected();
        ConnetedtoSever = false;
        qDebug() << "Could not connect to Flipper";
    }

}

void flipperinterface::flipper_S_ConnectedtoServer()
{
    ConnetedtoSever = true;

    //start the goddam timer that do the freaking job
    performTaskTimer.start(FLIPPER_DATAUPDATE_RATE);


}

/*
 * This Read Packet slot is written follow the example client fortune
 * /
*/

void flipperinterface::readPacket()
{

    //in.startTransaction();
    QByteArray thePacket;


    thePacket.append(tcpSocket->readAll());
    //insert raw data from in to thePacket
    //in >> thePacket;

    // if the transaction hasn't finished, return. Wait for new data to arrive.
    //    if(!in.commitTransaction())
    //    {
    //        return;
    //    }
    // after the transaction is commited/finished. Process the data here.
    // assume that the data is sent correctly, dât size í 11 bytes
    // <2byte transaction identifier> <2byte protocol identifier> <2byte Length unit identifier>
    //<1byte station number> <1byte function code> <1 byte of the read out byte number> <2 byte of the content>

    // so I really want to check the size of the qbytearray to make sure that it is 11 bytes

    if(thePacket.size() == 11)
    {
        // then proceed to do some nifty stuff here
        // IN this example, I don't need to care about the functioncode as well as the relative address.
        // just the content is really important.
        // convert the 2byte of the content into an integer and then use a signal to send it away hihi


        qint16 value;
        thePacket.remove(0,9);
        value = thePacket.at(0) << 8 | thePacket.at(1);
        // QDataStream s(&thePacket, QIODevice::ReadWrite);
        // s >> value;

        // get the decimal value by divided to the FLIPPER_DECIMAL_VALUE

        double DecimalVal = ((double) value / (double) this->DecimalPoint);


        // send signal along with decimal value
        emit SIG_Measurevalue(this->currentCH,DecimalVal);

        static qint32 counter = 0;

        if(DecimalVal > CH1spec || DecimalVal > CH2spec || DecimalVal > CH3spec)
        {
            if(!sentAlarmNotification)
            {
                if(alarmEmail)
                {
                    emit SIG_sendEmailNotification("-[Alert]-Dewpoint Temperature",DecimalVal);
                }
                if(alarmMobile)
                {
                    emit SIG_sendPushNotification(currentCH, DecimalVal);
                }

                sentAlarmNotification = true;
                counter = 0;
            }
            counter++;
            if(counter == 30)
            {
                counter = 0;
                sentAlarmNotification = false;
            }
        }

    }

}

flipperinterface::~flipperinterface()
{

}

void flipperinterface::start()
{

    in.setDevice(tcpSocket);
    in.setVersion(QDataStream::Qt_4_0);

    testconnection(_serverIp,_serverPort);
}

QByteArray flipperinterface::generateCommmandMessage(qint16 StationNO,qint16 FunctionCode, qint32 relativeAddr, qint32 readoutWordnumber)
{
    QByteArray streamData;
    qint16 dummy = 0x00;
    streamData.append(dummy);
    streamData.append(dummy);
    streamData.append(dummy);
    streamData.append(dummy);

    streamData.append(dummy);
    streamData.append(0x06); // Message Length

    streamData.append(StationNO);

    streamData.append(FunctionCode);

    streamData.append(relativeAddr >> 8); // get upper relative addr
    streamData.append(relativeAddr & 0x00FF); // get lower relative addr

    streamData.append(readoutWordnumber >> 8); // get upper relative addr
    streamData.append(readoutWordnumber & 0x00FF); // get lower relative addr

    return streamData;
}

//Sample: QByteArray sendArray = generateCommmandMessage(1,0x04,0x0065,0x0001);
void flipperinterface::taskGetMeasuredValues()
{
    QEventLoop loop;
    QTimer timeoutTimer;


    connect(&timeoutTimer,SIGNAL(timeout()),&loop,SLOT(quit()));
    connect(&timeoutTimer,SIGNAL(timeout()),this,SLOT(SLOT_flipper_serverTimeout()));

    connect(this,SIGNAL(SIG_flipper_readMeasureValue()),&loop,SLOT(quit()));


    timeoutTimer.start(FLIPPER_SERVERTIMEOUT);

    if(CH1ON)
    {
        QByteArray tmpCommand = generateCommmandMessage(_flipperAddr, 0x04,FLIPPER_CH1_MEASURE_RELATIVE_ADDR, FLIPPER_READOUTWORDNUMBER_MEASURECOMMAND);
        tcpSocket->write(tmpCommand);
        currentCH = 1;
        loop.exec();
    }

    if(CH2ON)
    {
        QByteArray tmpCommand = generateCommmandMessage(_flipperAddr, 0x04,FLIPPER_CH2_MEASURE_RELATIVE_ADDR, FLIPPER_READOUTWORDNUMBER_MEASURECOMMAND);
        tcpSocket->write(tmpCommand);
        currentCH = 2;
        loop.exec();
    }

    if(CH3ON)
    {
        QByteArray tmpCommand = generateCommmandMessage(_flipperAddr, 0x04,FLIPPER_CH3_MEASURE_RELATIVE_ADDR, FLIPPER_READOUTWORDNUMBER_MEASURECOMMAND);
        tcpSocket->write(tmpCommand);
        currentCH = 3;
        loop.exec();
    }

}

void flipperinterface::SLOT_flipper_serverTimeout()
{
    // inform the world that the server is time out and handle the shit out of it.
}

void flipperinterface::setSeveraddress(const QString &IP, const quint16 &PORT)
{
    _serverIp = IP;
    _serverPort = PORT;
}

void flipperinterface::setFlipperaddress(const qint16 &addr)
{
    _flipperAddr = addr;
}
