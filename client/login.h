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
		void do_destroy();
		void on_buttonPlay_clicked();

	private:
		Ui::login *ui;

		/* Login property */
		QString nickname;

};

#endif // LOGIN_H
