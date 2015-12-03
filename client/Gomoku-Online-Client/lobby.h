#ifndef LOBBY_H
#define LOBBY_H

#include <QMainWindow>
#include "client.h"

namespace Ui {
class lobby;
}

class lobby : public QMainWindow
{
		Q_OBJECT

	public:
		explicit lobby(QWidget *parent = 0);
		~lobby();

	private slots:
		void populate_room(QJsonArray data);

		void on_buttonRefreshRoom_clicked();

		void on_buttonCreateRoom_clicked();

		void do_destroy();

		void do_show();

		void on_join(int rid);

		void on_buttonJoinRoom_clicked();

	private:
		Ui::lobby *ui;
};

#endif // LOBBY_H
