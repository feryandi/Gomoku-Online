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

QJsonArray client::getPlayers()
{
	return players;
}

int client::getPid(){
	return player_id;
}

void client::connected()
{
	qDebug() << "connected...";
}

void client::disconnected()
{
	qDebug() << "disconnected...";
}

void client::sendMessageJSONObject(QJsonObject message)
{
	qDebug() << "writing...";
	qDebug() << message;


	QJsonDocument json_document;
	json_document.setObject(message);
	if (socket->write(json_document.toJson(QJsonDocument::Compact) + "\r\n") < 0){
		qDebug() << "Error: " << socket->errorString();
	}
}

void client::readMessage()
{
	QByteArray message = socket->readAll();

	qDebug() << "reading...";
	qDebug() << message;

	QJsonDocument json_document = QJsonDocument::fromJson(message);
	QJsonObject json_object;
	json_object = json_document.object();
	QJsonValue type = json_object.value("type");

	if (type == "login"){
		player_id = json_object.value("id").toInt();
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
	} else if (type == "play") {
		emit on_update_game(json_object);
	} else if (type == "win") {
		emit on_game_over(json_object);
	}
}
