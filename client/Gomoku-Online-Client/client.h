#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include <QCloseEvent>
#include <QTableWidgetItem>

class client : public QObject
{
		Q_OBJECT
	public:
		explicit client(QObject *parent = 0);
		void doConnect(QString server_ip, quint16 server_port);
		int getRidByIndex(int idx);
		QJsonArray getPlayers();
		int getPid();


	signals:
		void on_login();
		void on_refresh_rooms(QJsonArray data);
		void on_refresh_players(QJsonArray data);
		void on_join(int rid);
		void on_close_game();
		void on_create_room(int rid);
		void on_start_game();
		void on_update_game(QJsonObject data);
		void on_game_over(QJsonObject data);


	public slots:
		void connected();
		void disconnected();
		void sendMessageJSONObject(QJsonObject message);
		void readMessage();

	private:
		QTcpSocket *socket;
		QJsonArray rooms;
		QJsonArray players;
		int player_id;
};

/* Universal connection handler */
extern client connection;
#endif // CLIENT_H
