#include "client.h"

client connection;

client::client(QObject *parent) : QObject(parent)
{
}

void client::doConnect(QString server_ip, quint16 server_port)
{
	socket = new QTcpSocket(this);
	connect(socket, SIGNAL(connected()),this, SLOT(connected()));
	connect(socket, SIGNAL(disconnected()),this, SLOT(disconnected()));
	connect(socket, SIGNAL(readyRead()),this, SLOT(readMessage()));
	//connect(socket, SIGNAL(bytesWritten(qint64)),this, SLOT(sendMessageJSON()));

	qDebug() << "connecting...";

	socket->connectToHost(server_ip, server_port);
	if (!socket->waitForConnected(3000)){
		qDebug() << "Error: " << socket->errorString();
	}
}

void client::connected()
{
	qDebug() << "connected...";
}

void client::disconnected()
{
	qDebug() << "disconnected...";
}

void client::sendMessageJSON(QByteArray message)
{
	qDebug() << "writing...";
	if (socket->write(message) < 0){
		qDebug() << "Error: " << socket->errorString();
	}
}

void client::readMessage()
{
	qDebug() << "reading...";
	QByteArray message = socket->readAll();
	qDebug() << message;

	QJsonDocument json_document = QJsonDocument::fromJson(message);

	QJsonObject json_object;
	json_object = json_document.object();

	if (json_object.value("type") == "login"){
		emit on_login();
	} else if (json_object.value("type") == "response"){
		if (json_object.value("object") == "rooms"){

			emit on_refresh_rooms(json_object.value("data").toArray());
		} else if (json_object.value("object") == "players"){
			emit on_refresh_players();
		}
	}
}

