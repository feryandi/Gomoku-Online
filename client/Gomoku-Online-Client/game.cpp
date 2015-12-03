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

void game::do_show()
{
	this->show();
}

void game::do_hide()
{
	this->hide();
}

void game::do_startgame()
{
	ui->buttonPlay->setText("Game Started!");
	ui->buttonPlay->setDisabled(1);
}

void game::on_game_destroyed()
{
	QJsonObject json_object;
	json_object.insert("type", "closegame");
	connection.sendMessageJSONObject(json_object);
}

void game::on_buttonPlay_clicked()
{
	QJsonObject json_object;
	json_object.insert("type", "startgame");
	connection.sendMessageJSONObject(json_object);
}

void game::on_tableBoard_cellClicked(int row, int column)
{
	QJsonObject json_object;
	json_object.insert("type", "play");
	json_object.insert("x", column);
	json_object.insert("y", row);
	connection.sendMessageJSONObject(json_object);
}
