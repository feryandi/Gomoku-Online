#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "client.h"
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
		void do_destroy();

	private:
		Ui::login *ui;

		//Login Property
		QString nickname;

};

#endif // LOGIN_H
