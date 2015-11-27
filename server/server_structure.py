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
		print "Player [ " +  self.name + " ("  + str(self.id) + ") ] exited"

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
		print "Room [ " + self.name + "(" + str(self.id) + ") ] deleted"

class Game:
	def __init__ (self, rid, pid):
		self.room = rid
		self.board = [ [ 0 for x in range(20) ] for x in range(20) ]
		self.turn = 0
		self.winner = -1
		self.players = []

	def getPlayerCount (self):
		return len(self.players)

	def getTurn (self):
		return self.players[self.turn]

	def nextTurn (self):
		self.turn += 1
		if self.turn > len(self.players):
			self.turn = 0

	def addPlayer (self, pid):
		self.players.append(pid)

	def delPlayer (self, pid):
		self.players.remove(pid)

	def __del__ (self):
		print "Game from Room ( " + str(self.room) + " ) stopped"

class GameServer:
	character = ['X', 'O', 'Y', 'L', 'M'] # maximum 5 players per room (?)

	def __init__ (self):
		self.players = [""] * 5 # maximum players online 
		self.rooms = [""] * 5 # maximum rooms active

	def getPlayerList (self):
		return self.players

	def getRoomList (self):
		return self.rooms

	def broadcastByRoom (self, rid, message):
		msg = json.dumps(message,separators=(',',':'))
		for player in self.players:
			if ( ( player != "" ) and ( player.getRoomID() == rid ) ):
				player.getIPort().send(struct.pack("i", len(msg)) + msg)

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
				return i
			i += 1
		return None

	def delPlayer (self, pid):
		del self.players[pid]
		self.players[pid] = ""

	def delRoom (self, rid):
		self.rooms[rid] = ""

	def playerJoin (self, pid, rid):
		if self.rooms[rid][1].getPlayerCount() < 5:
			self.players[pid].setRoomID(rid)
			self.rooms[rid][1].addPlayer(pid)
			self.players[pid].setChar(GameServer.character[self.rooms[rid][1].getPlayerCount() - 1])
			print "Player join room (" + str(rid) + ") and get character '" + self.players[pid].getChar() + "'"
			return 1
		else:
			print "User trying to join full room"
			return 0

	def playerQuit (self, pid):
		rid = self.players[pid].getRoomID()
		self.rooms[rid][1].delPlayer(pid)
		self.players[pid].setChar("?")
		print "Player (" + str(pid) + ") quit from game"

		if self.rooms[rid][1].getPlayerCount() == 0:
			self.delRoom(rid)
			print "Room (" + str(rid) + ") deleted because lack of players"


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
				GameServer.delPlayer(self.clientid)
				MessageServer.client -= 1
				onLoop = False

		clientsocket.close()


	def interpreter (self, message, clientsocket, GameServer):
		msg = json.loads(message)

		if msg['type'] == 'login':
			# Register player ke Server
			GameServer.newPlayer(msg['name'], clientsocket)

			# Berikan list Room yang ada
			self.sendResponse(clientsocket, self.objectToJSON("rooms", GameServer))

		elif msg['type'] == 'newroom':
			# Buat room baru,
			rid = GameServer.newRoom(msg['name'], self.clientid)

			# Kirim ulang data rooms ke Client
			GameServer.broadcastByRoom(-1, json.loads(self.objectToJSON("rooms", GameServer)))

			# Kasi tau bahwa room berhasil dibuat
			self.sendResponse(clientsocket, json.dumps({"type":"newroom", "rid":rid}))

		elif msg['type'] == 'join':
			if msg['rid'] >= 0:
				# Join Player ke Game
				if GameServer.playerJoin(self.clientid, msg['rid']) == 1:
					# Beritahu ke player bahwa berhasil join
					self.sendResponse(clientsocket, json.dumps({"type":"join", "rid":msg['rid']}))
				else:
					# Beritahu ke player bahwa GAGAL join					
					self.sendResponse(clientsocket, json.dumps({"type":"join", "rid":-1}))

		elif msg['type'] == 'closegame':
			GameServer.playerQuit(self.clientid)

		elif msg['type'] == 'request':
			if msg['object'] == 'rooms':
				self.sendResponse(clientsocket, self.objectToJSON("rooms", GameServer))


	def objectToJSON (self, request, GameServer):
		class message(object):
			def __init__(self):
				self.type = "response"
				self.object = "undefined"
				self.data = []

		msgobj = message()

		if (request == "rooms"):
			msgobj.object = "rooms"
			for room in GameServer.getRoomList():
				if ( room != "" ):
					msgobj.data.append({"id": room[0].getID(), "name":room[0].getName()})

		msg = json.dumps(msgobj.__dict__)
		return msg

	def sendResponse (self, clientsocket, msg):

		clientsocket.send(struct.pack("i", len(msg)) + msg)


	def __del__ (self):
		print "Message Server destroyed"
