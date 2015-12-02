from socket import *
from Tkinter import *
import json
import struct

#GUI
root = Tk()

# Connection 
cd_host = 'localhost'
cd_port = 55555
cd_addr = (cd_host,cd_port)
cd_clientsocket = socket(AF_INET, SOCK_STREAM)

# Player Data
cd_name = 'undefined'
cd_board = [ [ 'x' for x in range(20) ] for x in range(20) ]
cd_ridSelected = -1
cd_currentRoom = -2
cd_isOnGame = -1
cd_isOwner = False

# Current Game Data
cd_currentPlayers = []
cd_playerList = StringVar()
cd_gameStatus = StringVar()
cd_gameWindowOpen = False

def sendMessage(message):
	global cd_clientsocket

	msg = json.dumps(message,separators=(',',':'))
	cd_clientsocket.send(struct.pack("i", len(msg)) + msg)

def test():
	print cd_currentPlayers