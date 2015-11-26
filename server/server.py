from socket import *
from server_structure import GameServer
from server_structure import MessageServer

import struct
import thread
import json

def listener(clientsocket, clientaddr, GameServer):
	ms = MessageServer(clientsocket, clientaddr, GameServer)
	del ms

def main():
    host = 'localhost'
    port = 55555
    addr = (host, port)

    serversocket = socket(AF_INET, SOCK_STREAM)
    serversocket.bind(addr)
    serversocket.listen(2)

    gs = GameServer()

    while 1:
        print "Server is listening for connections\n"

        clientsocket, clientaddr = serversocket.accept()
        thread.start_new_thread(listener, (clientsocket, clientaddr, gs))
    serversocket.close()


if __name__ == '__main__':
	main()
