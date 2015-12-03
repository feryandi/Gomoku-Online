#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>

class client : public QObject
{
		Q_OBJECT
	public:
		explicit client(QObject *parent = 0);
		void doConnect(QString server_ip, quint16 server_port);

	signals:
		void on_login();
		void on_refresh_rooms(QString data);
		void on_refresh_players();


	public slots:
		void connected();
		void disconnected();
		void sendMessageJSON(QByteArray message);
		void readMessage();

	private:
		QTcpSocket *socket;
};

extern client connection;
#endif // CLIENT_H
