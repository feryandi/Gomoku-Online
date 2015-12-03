#include "game.h"
#include "ui_game.h"

game::game(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::game)
{
	ui->setupUi(this);
}

game::~game()
{
	delete ui;
}

void game::closeEvent(QCloseEvent *event)
{
	emit on_closegame();
	event->ignore();
}

void game::do_destroy()
{
	this->hide();
	qDebug() << "game destroyed!";
	//delete this;
}

void game::do_show()
{
	this->show();
}

void game::on_game_destroyed()
{
	QJsonObject json_object;
	json_object.insert("type", "closegame");

	QJsonDocument json_document;
	json_document.setObject(json_object);

	connection.sendMessageJSON(json_document.toJson(QJsonDocument::Compact));
}

void game::populate_players(QJsonArray data)
{
	ui->listPlayer->clear();
	QStringList list_players;
	qDebug() << data.at(0);
	for (int i=0; i<data.size(); i++){
		list_players += data.at(i).toObject().value("name").toString();
	}
	ui->listPlayer->addItems(list_players);

}

void game::on_buttonPlay_clicked()
{
	QJsonObject json_object;
	json_object.insert("type", "startgame");

	QJsonDocument json_document;
	json_document.setObject(json_object);

	connection.sendMessageJSON(json_document.toJson(QJsonDocument::Compact));
}

void game::do_startgame()
{
	ui->buttonPlay->setText("Game Started!");
	ui->buttonPlay->setDisabled(1);
}
