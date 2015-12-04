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
		void do_show(int rid);
		void do_hide();
		void do_startgame();
		void do_updategame(QJsonObject data);
		void do_highlight(QJsonObject data);
		void on_game_destroyed();
		void on_buttonPlay_clicked();
		void on_tableBoard_cellClicked(int row, int column);

	private:
		Ui::game *ui;
};

#endif // GAME_H
