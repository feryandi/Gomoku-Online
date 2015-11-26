from socket import *
import struct
import thread
import json

class Player:
	def __init__ (self, pid, iport, name):
		self.id = pid
		self.iport = iport
		self.name = name
		self.room = -1
		self.char = '?'

	def getID (self):
		return self.id

	def getIPort (self):
		return self.iport

	def getName (self):
		return self.name

	def getChar (self):
		return self.char

	def getRoomID (self):
		return self.room

	def setRoomID (self, rid):
		self.room = rid

	def setChar (self, char):
		self.char = char

	def __del__ (self):
		print "Player destroyed"

class Room:
	def __init__ (self, rid, name, pid):
		self.id = rid
		self.name = name
		self.ownerid = pid

	def getID (self):
		return self.id

	def getName (self):
		return self.name

	def __del__ (self):
		print "Room destroyed"

class Game:
	def __init__ (self, rid, pid):
		self.room = rid
		self.board = [ [ 0 for x in range(20) ] for x in range(20) ]
		self.turn = pid
		self.winner = -1
		self.players = 1

	def getPlayerCount (self):
		return self.players

	def addPlayer (self):
		self.players += 1

	def delPlayer (self):
		self.players -= 1

	def __del__ (self):
		print "Game destroyed"

class GameServer:
	character = ['X', 'O', 'Y', 'L', 'M'] # maximum 5 players per room (?)

	def __init__ (self):
		self.players = [""] * 5 # maximum players online 
		self.rooms = [""] * 1 # maximum rooms active

	def getPlayerList (self):
		return self.players

	def getRoomList (self):
		return self.rooms

	def broadcastByRoom (self, rid, message):
		for player in self.players:
			if ( ( player != "" ) and ( player.getRoomID() == rid ) ):
				player.getIPort().send(struct.pack("i", len(message)) + message)

	def newPlayer (self, name, iport):
		i = 0
		for x in self.players:
			if ( x == "" ):
				self.players[i] = Player(i, iport, name)
				return 1
			i += 1
		return None

	def newRoom (self, name, pid):
		i = 0
		for x in self.rooms:
			if ( x == "" ):
				self.rooms[i] = (Room(i, name, pid), Game(i, pid))
				self.playerJoin(pid, i)
				return 1
			i += 1
		return None

	def playerJoin (self, pid, rid):
		self.players[pid].setRoomID(rid)
		self.rooms[rid][1].addPlayer()
		self.players[pid].setChar(GameServer.character[self.rooms[rid][1].getPlayerCount() - 1])

class MessageServer:
	client = 0

	def __init__ (self, clientsocket, clientaddr, GameServer):
		self.clientid = MessageServer.client
		MessageServer.client += 1
		print "Accepted connection from ", tuple(clientaddr)

		onLoop = True

		while onLoop:			
			try:
				size = struct.unpack("i", clientsocket.recv(struct.calcsize("i")))
				data = ""
				while len(data) < size[0]:
					msg = clientsocket.recv(size[0] - len(data))
					if not msg:
						return None
					data += msg

				if not data:
					break
				else:
					print data
					self.interpreter(data, clientsocket, GameServer)
			except error:
				MessageServer.client -= 1
				onLoop = False

		clientsocket.close()

	def interpreter (self, message, clientsocket, GameServer):
		msg = json.loads(message)

		if msg['type'] == 'newroom':
			GameServer.newPlayer(msg['name'], clientsocket)
			
			#debug only
			if (self.clientid == 0):
				GameServer.newRoom("roomname", self.clientid)
			else:
				GameServer.playerJoin(self.clientid, 0)

			GameServer.broadcastByRoom(0, "{\"type\":\"HELLO!\"}")

	def __del__ (self):
		print "Message Server destroyed"
