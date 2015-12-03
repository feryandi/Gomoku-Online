#include "interface.h"

interface::interface(QObject *parent) : QObject(parent)
{
	connect(&connection, SIGNAL(on_login()), this, SLOT(on_login()));
	w_login = new login;
	w_lobby = new lobby;
	w_game = new game;
	connect(&connection, SIGNAL(on_login()), w_login, SLOT(do_destroy()));
	w_login->show();

}

void interface::on_login()
{
	connect(&connection, SIGNAL(on_refresh_rooms(QJsonArray)), w_lobby, SLOT(populate_room(QJsonArray)));
	connect(&connection, SIGNAL(on_refresh_players(QJsonArray)), w_game, SLOT(populate_players(QJsonArray)));

	connect(&connection, SIGNAL(on_create_room(int)), w_lobby, SLOT(on_join(int)));
	connect(&connection, SIGNAL(on_join(int)), w_lobby, SLOT(do_destroy()));
	connect(&connection, SIGNAL(on_join(int)), w_game, SLOT(do_show()));

	connect(w_game, SIGNAL(on_closegame()), w_game, SLOT(on_game_destroyed()));
	connect(&connection, SIGNAL(on_close_game()), w_game, SLOT(do_destroy()));
	connect(&connection, SIGNAL(on_close_game()), w_lobby, SLOT(do_show()));

	connect(&connection, SIGNAL(on_start_game()), w_game, SLOT(do_startgame()));
	w_lobby->show();
}
