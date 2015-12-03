#include "lobby.h"
#include "ui_lobby.h"

lobby::lobby(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::lobby)
{
	ui->setupUi(this);
}

lobby::~lobby()
{
	delete ui;
}

void lobby::populate_room(QJsonArray data)
{
	ui->listRoom->clear();
	QStringList list_room;
	for (int i=0; i<data.size(); i++){
		list_room += data.at(i).toObject().value("name").toString();
	}
	ui->listRoom->addItems(list_room);

}

void lobby::on_buttonRefreshRoom_clicked()
{
	QJsonObject json_object;
	json_object.insert("type", "request");
	json_object.insert("object", "rooms");

	QJsonDocument json_document;
	json_document.setObject(json_object);

	connection.sendMessageJSON(json_document.toJson(QJsonDocument::Compact));
}

void lobby::on_buttonCreateRoom_clicked()
{
	QJsonObject json_object;
	json_object.insert("type", "newroom");
	json_object.insert("name", ui->textCreateRoom->text());

	QJsonDocument json_document;
	json_document.setObject(json_object);

	connection.sendMessageJSON(json_document.toJson(QJsonDocument::Compact));
}

void lobby::do_destroy()
{
	qDebug() << "lobby destroyed!";
	this->hide();
	//delete this;
}

void lobby::do_show()
{
	this->show();
	//delete this;
}

void lobby::on_join(int rid)
{
	QJsonObject json_object;
	json_object.insert("type", "join");
	json_object.insert("rid", rid);
	QJsonDocument json_document;
	json_document.setObject(json_object);

	connection.sendMessageJSON(json_document.toJson(QJsonDocument::Compact));
}

void lobby::on_buttonJoinRoom_clicked()
{
	QJsonObject json_object;
	json_object.insert("type", "join");
	int rid = connection.getRidByIndex(ui->listRoom->currentRow());
	json_object.insert("rid", rid);
	QJsonDocument json_document;
	json_document.setObject(json_object);

	connection.sendMessageJSON(json_document.toJson(QJsonDocument::Compact));
}
