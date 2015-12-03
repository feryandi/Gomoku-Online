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

int client::getRidByIndex(int idx)
{
	return rooms.at(idx).toObject().value("id").toInt();
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
	qDebug() << message;
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
	QJsonValue type = json_object.value("type");

	if (type == "login"){
		emit on_login();
	} else if (type == "response"){
		if (json_object.value("object") == "rooms"){
			rooms = json_object.value("data").toArray();
			emit on_refresh_rooms(rooms);
		} else if (json_object.value("object") == "players"){
			players = json_object.value("data").toArray();
			emit on_refresh_players(players);
		}
	} else if (type == "newroom"){
		emit on_create_room(json_object.value("rid").toInt());
	} else if (type == "join"){
		emit on_join(json_object.value("rid").toInt());
	} else if (type == "closegame") {
		emit on_close_game();
	} else if (type == "startgame") {
		emit on_start_game();
	}
}
