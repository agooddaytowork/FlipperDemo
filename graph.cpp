#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::initGraph()
{
    QFont font;
    font.setStyleStrategy(QFont::NoAntialias);
    ui->GraphCH1->setOpenGl(true);
    ui->GraphCH1->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
    // Init for Graph Channel 1

    ui->GraphCH1->setNotAntialiasedElements(QCP::aeAll);
    ui->GraphCH1->xAxis->setTickLabelFont(font);
    ui->GraphCH1->yAxis->setTickLabelFont(font);
    ui->GraphCH1->yAxis2->setTickLabelFont(font);
    ui->GraphCH1->legend->setFont(font);

    QSharedPointer<QCPAxisTickerDateTime> timeTicker(new QCPAxisTickerDateTime);
    timeTicker->setDateTimeFormat(" hh:mm\n MM/dd/yy");
    //     QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    //     timeTicker->setTimeFormat("%h:%m:%s");
    timeTicker->setTickCount(6);
    ui->GraphCH1->xAxis->setRange(QDateTime::currentDateTime().toTime_t(),500,Qt::AlignRight);

    ui->GraphCH1->xAxis->setTicker(timeTicker);

    ui->GraphCH1->yAxis->grid()->setSubGridVisible(true);
    ui->GraphCH1->xAxis->grid()->setSubGridVisible(true);
    //ui->GraphCH1->yAxis2->setScaleType(QCPAxis::stLogarithmic);
    QSharedPointer<QCPAxisTicker> TemperatureTicker (new QCPAxisTicker);
    ui->GraphCH1->yAxis->setTicker(TemperatureTicker);
    //ui->GraphCH1->yAxis->setNumberPrecision(1); // makes sure "1*10^4" is displayed only as "10^4"
    //ui->GraphCH1->yAxis->setRange(-100,0);


    QPen pen;
    pen.setColor(QColor(105, 35, 224));
    pen.setWidth(3);

    ui->GraphCH1->addGraph();
    ui->GraphCH1->graph(0)->setPen(pen);
    ui->GraphCH1->graph(0)->setName("Temp");

    ui->GraphCH1->yAxis->setLabel("Temperature");


    if(connectToDatabase())
    {
        QSqlQuery query;
        if(query.exec("SELECT * FROM CH1 ORDER BY time DESC LIMIT 1440"))
        {
            qDebug()<< "Query to get 1 day data succeeed" << endl;

            while(query.next())
            {
                // some code that executes every time
                for(static bool first = true;first;first=false)
                {
                    ui->GraphCH1->xAxis->setRange(query.value(0).toDateTime().toTime_t(),1440*60,Qt::AlignRight);

                    qDebug()<< "Set Range for the first time" << endl;
                }

                ui->GraphCH1->graph(0)->addData(query.value(0).toDateTime().toTime_t(), query.value(1).toDouble());
            }
        }
    }
    ui->GraphCH1->yAxis->rescale(true);
    ui->GraphCH1->replot();


}


void MainWindow::SLOT_plotGraph(const int &CH, const double &value)
{
    static int Range = 0;
    static int RangeValue = 120;
    double key = QDateTime::currentDateTime().toTime_t();
    switch (CH)
    {
    case 1:

        ui->GraphCH1->graph(0)->addData(key, value);
        if(Range % 50 == 0)
        {
            if(RangeValue <1440*60)
            {
                RangeValue = RangeValue +60;
            }

        }
        if(((ui->GraphCH1->xAxis->range().upper) - (ui->GraphCH1->xAxis->range().lower)) < 1200*60)
        {
            ui->GraphCH1->xAxis->setRange(key,RangeValue,Qt::AlignRight);
        }
        else {
            ui->GraphCH1->xAxis->setRange(key,1440*60,Qt::AlignRight);
        }

        ui->GraphCH1->yAxis->rescale(true);

        ui->GraphCH1->replot();
        //ui->GraphCH1->xAxis->setRange();

        break;
    case 2:
        break;
    case 3:
        break;
    }
    Range++;
}
