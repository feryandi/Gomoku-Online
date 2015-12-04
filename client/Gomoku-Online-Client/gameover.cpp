#include "gameover.h"
#include "ui_gameover.h"

gameover::gameover(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::gameover)
{
	ui->setupUi(this);
}

gameover::~gameover()
{
	delete ui;
}

void gameover::on_buttonOK_clicked()
{
	QJsonObject json_object;
	json_object.insert("type", "closegame");
	connection.sendMessageJSONObject(json_object);
	emit on_closegame();
	emit on_deletegameover();
}

void gameover::do_show(QJsonObject data)
{
	if (data.value("id") != connection.getPid()){
		ui->labelGameover->setText("YOU SUCK MAN :(");
		ui->labelWinner->setText("The winner is " + data.value("name").toString());

	}
	this->show();
}

void gameover::delete_game_over()
{
	delete this;
}
