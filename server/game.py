from player import *
from room import *

class Game:
	def __init__ (self, rid, pid):
		self.room = rid
		self.board = [ [ 0 for x in range(20) ] for x in range(20) ]
		self.turn = 0
		self.winner = -1
		self.players = []
		self.isStart = False

	def setBoard(self, x, y, char):
		self.board[x][y] = char

	def countSame(self, x, y, char, x_incr, y_incr):
		count = 0
		temp = char
		x_iter = x + x_incr
		y_iter = y + y_incr
		while temp == char :
			temp = self.board[x_iter][y_iter]
			if temp == char :
				count = count + 1
			x_iter = x_iter + x_incr
			y_iter = y_iter + y_incr
		return count

	def checkWin(self, x, y, char, x_incr, y_incr):
		countA = self.countSame(x,y,char,x_incr,y_incr)
		countB = self.countSame(x,y,char,-x_incr,-y_incr)

		return countA + countB + 1 > 4

	def checkVertical(self, x, y, char):
		return self.checkWin(x,y,char,0,1)
		
	def checkHorizontal(self, x, y, char):
		return self.checkWin(x,y,char,1,0)

	def checkDiagonalA(self, x, y, char):
		return self.checkWin(x,y,char,1,1)

	def checkDiagonalB(self, x, y, char):
		return self.checkWin(x,y,char,-1,1)

	def isWin(self, x, y, char):
		win = 0
		if self.checkVertical(x,y,char) :
			win = win + 1
		if self.checkHorizontal(x,y,char) :
			win = win + 1
		if self.checkDiagonalA(x,y,char) :
			win = win + 1
		if self.checkDiagonalB(x,y,char) :
			win = win + 1
		return win > 0

	def getOwner (self):
		if self.getPlayerCount() == 0:
			return ""
		else:
			return self.players[0]

	def isOwner (self, player):
		return player.getID() == self.getOwner().getID()

	def isGameStarted (self):
		return self.isStart

	def getPlayerCount (self):
		return len(self.players)

	def getTurn (self):
		return self.players[self.turn]

	def nextTurn (self):
		self.turn += 1
		if self.turn > len(self.players) - 1:
			self.turn = 0

	def getPlayerList (self):
		return self.players

	def addPlayer (self, pid):
		self.players.append(pid)

	def delPlayer (self, pid):
		self.players.remove(pid)

	def startGame (self):
		self.isStart = True

	def stopGame (self):
		self.isStart = False

	def __del__ (self):
		print "Game from Room ( " + str(self.room) + " ) stopped"