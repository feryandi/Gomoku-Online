#include "login.h"
#include "lobby.h"
#include "game.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	login w;
	w.show();
	//lobby x;
	//x.show();
	//game z;
	//z.show();

	return a.exec();
}
