#ifndef LOBBY_H
#define LOBBY_H

#include <QMainWindow>

namespace Ui {
class lobby;
}

class lobby : public QMainWindow
{
		Q_OBJECT

	public:
		explicit lobby(QWidget *parent = 0);
		~lobby();

	private:
		Ui::lobby *ui;
};

#endif // LOBBY_H
