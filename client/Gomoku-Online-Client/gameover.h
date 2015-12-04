#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QDialog>
#include "client.h"

namespace Ui {
class gameover;
}

class gameover : public QDialog
{
		Q_OBJECT

	public:
		explicit gameover(QWidget *parent = 0);
		~gameover();

	signals:
		void on_deletegameover();
		void on_closegame();

	private slots:
		void on_buttonOK_clicked();
		void do_show(QJsonObject data);
		void delete_game_over();

	private:
		Ui::gameover *ui;
};

#endif // GAMEOVER_H
