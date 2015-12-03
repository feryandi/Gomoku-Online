#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include "client.h"

namespace Ui {
class game;
}

class game : public QMainWindow
{
		Q_OBJECT

	public:
		explicit game(QWidget *parent = 0);
		~game();
		void closeEvent(QCloseEvent *);

	signals:
		void on_closegame();

	private slots:
		void populate_players(QJsonArray data);
		void on_game_destroyed();
		void do_destroy();
		void do_show();
		void do_startgame();

		void on_buttonPlay_clicked();

	private:
		Ui::game *ui;
};

#endif // GAME_H
