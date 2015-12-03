#include "interface.h"

interface::interface(QObject *parent) : QObject(parent)
{
	connect(&connection, SIGNAL(on_login()), this, SLOT(on_login()));
	login* w = new login;
	connect(&connection, SIGNAL(on_login()), w, SLOT(do_destroy()));
	w->show();

}

void interface::on_login()
{
	lobby *w = new lobby;
	connect(&connection, SIGNAL(on_refresh_rooms(QJsonArray)), w, SLOT(populate_room(QJsonArray)));
	w->show();

}

