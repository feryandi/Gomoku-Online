#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::login),
	nickname("user_name")
{
	ui->setupUi(this);
}

login::~login()
{
	delete ui;
}

void login::on_buttonPlay_clicked()
{
	nickname = ui->textNickname->text().toStdString();
	string server_ip = ui->textServerIP->text().toStdString();
	int server_port = ui->textServerPort->text().toInt();




	if (connection_instance.doConnect(server_ip, server_port)){
		QJsonObject json_object;
		json_object.insert("type", "login");
		json_object.insert("name", nickname.c_str());

		QJsonDocument json_document;
		json_document.setObject(json_object);

		if (connection_instance.doSendJSON(json_document.toJson())){

		}
	}

}
