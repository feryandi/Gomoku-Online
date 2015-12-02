#include <QApplication>
#include <QQmlApplicationEngine>
#include "login.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QQmlApplicationEngine engine;
	engine.load(QUrl(QStringLiteral("qrc:/login.qml")));
	engine.load(QUrl(QStringLiteral("qrc:/lobby.qml")));

	return app.exec();
}

