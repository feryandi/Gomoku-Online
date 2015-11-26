from Tkinter import *
from ttk import *
import tkMessageBox
from socket import *
import struct
import thread
import json

from game import *
from client_data import *

class Lobby(Frame):
    def __init__(self, parent):
        Frame.__init__(self, parent)   
         
        self.parent = parent
        
        self.initUI()
        
    def initUI(self):
        # TO-DO
        # Minta list room yang terdaftar diserver

        self.parent.title("Lobby")
        self.style = Style()
        self.style.theme_use("default")

        self.pack(fill=BOTH, expand=1)

        self.columnconfigure(1, weight=1)
        self.columnconfigure(3, pad=7)
        self.rowconfigure(3, weight=1)
        self.rowconfigure(5, pad=7)

        lblCR = Label(self, text="Room List")
        lblCR.grid(row=0, column=0, pady=4, padx=5, sticky=W)

        entry = Entry(self)
        entry.grid(row=0, column=1, pady=4, padx=5, columnspan=4, sticky=E)
        
        CRbtn = Button(self, text="Create")
        CRbtn.grid(row=0, column=5, pady=4, padx=5, sticky=E)

        # TO-DO
        # Bikin fungsi buat bikin room baru dan kirim pesan ke server kalo player mau bikin room

        self.rooms = ['Room 1', 'Join US!', 
            'No Cheater~', 'Lets play']

        lb = Listbox(self)
        for i in self.rooms:
            lb.insert(END, i)

        #lb.bind("<<ListboxSelect>>", self.onSelect)
        lb.grid(row=1, column=0, rowspan=6, columnspan=6, sticky=E+W+S+N, padx=5, pady=5)
        
        JOINbtn = Button(self, text="JOIN", width=25, command=self.onJoin)
        JOINbtn.grid(row=7, column=0, pady=4, padx=6, columnspan=6, sticky=E+W)

    
    def onJoin(self):     
        # TO-DO
        # Kirim message kalo player ingin join ke room yang dipilih

        self.gameWindow = Toplevel(self.parent)

        self.parent.withdraw()

        app = GameRoom(self.gameWindow)

        self.gameWindow.protocol("WM_DELETE_WINDOW", self.onPlayClose)
        #app = GameRoom(self.parent) 

    def onPlayClose(self):
        self.parent.deiconify()
        self.gameWindow.destroy()

