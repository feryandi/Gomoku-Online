#ifndef CONNECTION_H
#define CONNECTION_H

#include <QtNetwork>
#include <iostream>
using namespace std;

class connection
{
	public:
		connection();
		int doConnect(string server_ip_, int server_port_);
		int doSendJSON(QByteArray message_);
		//QByteArray doReceive();
		string getIP();
		int getPort();
		void setIP(string server_ip_);
		void setPort(int server_port_);


	private:
		QTcpSocket *socket;
		string server_ip;
		int server_port;
};

extern connection connection_instance;

#endif // CONNECTION_H
