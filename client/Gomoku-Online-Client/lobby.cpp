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

void lobby::refresh_room(QString data)
{
	qDebug() << data;
}

