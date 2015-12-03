#include "connection.h"

//connection	connection_instance;

connection::connection() :
	server_ip("127.0.0.1"),
	server_port(55555)
{
	socket = new QTcpSocket();
}

connection::doConnect(string server_ip_, int server_port_)
{
	setIP(server_ip_);
	setPort(server_port_);

	cout << "Connecting..." << endl;
	socket->disconnectFromHost();
	socket->connectToHost(server_ip.c_str(), server_port);
	if (!socket->waitForConnected(5000)){
		cout << "Error: " << socket->errorString().toStdString() << endl;
		return 0;
	} else{
		cout << "Connection established!" << endl;
		return 1;
	}
}

int connection::doSendJSON(QByteArray message_)
{
	QByteArray byteArray;

	QDataStream stream(&byteArray, QIODevice::WriteOnly);
	stream.setByteOrder(QDataStream::LittleEndian);
	stream << message_.length()-13;
	QByteArray to_send = byteArray + message_.simplified().replace(" ", "");

	if (socket->write(to_send) > 0){
		cout << "Message sent!" << endl;
		return 1;
	} else{
		cout << "Error: " << socket->errorString().toStdString() << endl;
		return 0;
	}
}

/*QByteArray connection::doReceive()
{
	return socket->readAll();
}*/


string connection::getIP()
{
	return server_ip;
}

int connection::getPort()
{
	return server_port;
}

void connection::setIP(string server_ip_)
{
	server_ip = server_ip_;
}

void connection::setPort(int server_port_)
{
	server_port = server_port_;
}
