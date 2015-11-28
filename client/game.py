from Tkinter import *
from ttk import *
import tkMessageBox
from socket import *
import struct
import thread
import json

from client_data import *

class GameRoom(Frame):
    def __init__(self, parent):
        Frame.__init__(self, parent) 
        self.size = 20 
         
        self.parent = parent
        
        self.initUI()
        
    def initUI(self):
        global cd_playerList
        global cd_gameStatus

        self.parent.title("Gomoku Game")
        self.style = Style()
        self.style.theme_use("default")

        self.pack(fill=BOTH, expand=1)

        self.createInitalBoard()
        
        lblInfo = Label(self, text="GOMOKU ONLINE", width=35, anchor=CENTER)
        lblInfo.grid(row=0, column=self.size, rowspan=2, pady=4, padx=5, sticky=E+W)

        lblTurn = Label(self, text="Turn", relief=RIDGE, width=35, anchor=CENTER)
        lblTurn.grid(row=2, column=self.size, padx=5, sticky=E+W)

        lblTurn = Label(self, text="feryandi [ X ]", width=35, anchor=CENTER)
        lblTurn.grid(row=3, column=self.size, padx=5, sticky=E+W)

        lblTurn = Label(self, text="Players List", relief=RIDGE, width=35, anchor=CENTER)
        lblTurn.grid(row=4, column=self.size, padx=5, sticky=E+W)

        lblTurn = Label(self, textvariable=cd_playerList, width=35, anchor=N)
        lblTurn.grid(row=5, column=self.size, rowspan=10, padx=5, sticky=N)

        cd_gameStatus = StringVar()

        lblGame = Label(self, textvariable=cd_gameStatus, width=35, anchor=CENTER)
        lblGame.grid(row=self.size-3, column=self.size, rowspan=3, padx=5)

        cd_gameStatus.set("Waiting for 3 Players\nto Enter the Room")

        sendMessage({"type":"request", "object":"players"})


    def createInitalBoard(self):
        global cd_board
        for x in range(self.size):
            for y in range(self.size):
                buttonName = str(x) + "," + str(y)
                cd_board[x][y] = StringVar()
                boardButton = Button(self,
                                     width=2,
                                     textvariable=cd_board[x][y],
                                     command=lambda name=buttonName: self.pushButton(name))
                boardButton.grid(row = x, column = y, pady=0)

    def __del__ (self):
        print "Game Window closed"
