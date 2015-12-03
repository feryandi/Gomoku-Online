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

		void on_buttonPlay_clicked();

	private:
		Ui::lobby *ui;
};

#endif // LOBBY_H
