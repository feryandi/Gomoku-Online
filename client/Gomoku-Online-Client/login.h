#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "connection.h"
#include "lobby.h"

namespace Ui {
class login;
}

class login : public QMainWindow
{
		Q_OBJECT

	public:
		explicit login(QWidget *parent = 0);
		~login();

	private slots:
		void on_buttonPlay_clicked();

	private:
		Ui::login *ui;

		//Login Property
		string nickname;

		connection connection_instance;
};

#endif // LOGIN_H
