#include "login.h"

login::login()
{
	QQmlApplicationEngine engine;
	engine.load(QUrl(QStringLiteral("qrc:/login.qml")));
}

