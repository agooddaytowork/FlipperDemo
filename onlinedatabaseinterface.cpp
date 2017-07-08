#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::sendNewDataToOnlineDatabase(const int &CH, const double &value)
{

    QJsonObject SendData = QJsonObject({
                                           QPair<QString, QJsonValue> ("Location" , WHname),
                                           QPair<QString, QJsonValue> ("FlipperCH"+QString::number(CH) , value)
                                       });

    QByteArray data = QJsonDocument(SendData).toJson();

    QUrl url("http://tamduongs.com:82/iot/flipperdataupdate.php");
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkAccessManager *manager = new QNetworkAccessManager();

    manager->post(request, data);
}
