#include "mainwindow.h"
#include "ui_mainwindow.h"

bool MainWindow::connectToDatabase()
{

    db.setHostName("localhost");
    db.setDatabaseName("flipper");
    db.setUserName("klaremote");
    db.setPassword("klaremote");
    if (!db.open())
    {
        qDebug() << db.lastError().text();
        db.close();
        return false;
    }
    return true;
}

bool MainWindow::connectTodbtest()
{
    db.setHostName("localhost");
    db.setDatabaseName("dbtest");
    db.setUserName("klaremote");
    db.setPassword("klaremote");
    if (!db.open())
    {
        qDebug() << db.lastError().text();
        db.close();
        return false;
    }
    return true;
}


bool MainWindow::insertNewDataToDatabase(const int &CH, const double &value)
{
    if(connectToDatabase())
    {
        QString querrycommand;
        querrycommand.append("INSERT INTO CH");
        querrycommand.append(QString::number(CH));
        querrycommand.append(" (time, value) VALUES (CURRENT_TIMESTAMP(),?)");
        //Qstring time = QDateTime::currentDateTime().toString("yyyy-MM-DD hh:mm:ss");
        QSqlQuery query;
        query.prepare(querrycommand);
        //query.prepare("INSERT INTO CH1 (time, value) VALUES (CURRENT_TIMESTAMP(),:value)");
        query.addBindValue(value);
        query.exec();

        db.close();
        return true;
    }
    return false;

}

double MainWindow::getLatestTemperature(const int &CH)
{
    if(connectToDatabase())
    {
        QString querrycommand;
        querrycommand.append("SELECT value FROM CH");
        querrycommand.append(QString::number(CH));
        querrycommand.append(" ORDER BY time DESC LIMIT 1");

        qDebug()<<querrycommand<< endl;
        //Qstring time = QDateTime::currentDateTime().toString("yyyy-MM-DD hh:mm:ss");
        QSqlQuery query;

        if(query.exec(querrycommand))
        {
            while(query.next())
            {
                qDebug() << "Get Latest Temp: " << query.value(0).toDouble() << endl;

                return query.value(0).toDouble();
            }
        }
    }

    qDebug() << "Get Latest Temp failed, return -200 ";
    return -200;

}

QString MainWindow::getLatestTimeStamp(const int CH)
{
    QString querrycommand;
    querrycommand.append("SELECT time FROM CH");
    querrycommand.append(QString::number(CH));
    querrycommand.append(" ORDER BY time DESC LIMIT 1");

    qDebug()<<querrycommand<< endl;
    //Qstring time = QDateTime::currentDateTime().toString("yyyy-MM-DD hh:mm:ss");
    QSqlQuery query;

    if(query.exec(querrycommand))
    {
        while(query.next())
        {
            qDebug() << "Get Latest TimeSamp: " << query.value(0).toString() << endl;

            return query.value(0).toString();
        }
    }
}

bool MainWindow::resetDatabase()
{
    if(connectToDatabase())
    {
        QSqlQuery query;
        if(query.exec("TRUNCATE TABLE CH1")) return  true;

    }
    return false;
}
