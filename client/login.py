from Tkinter import *
from ttk import *
import tkMessageBox
from socket import *
import struct
import thread
import json

from lobby import *
from client_data import *

class Login(Frame):
    def __init__(self, parent):
        Frame.__init__(self, parent)   
         
        self.parent = parent
        
        self.initUI()
        
    def initUI(self):
      
        self.parent.title("Login")
        self.style = Style()
        self.style.theme_use("default")

        self.pack(fill=BOTH, expand=1)

        lblInfo = Label(self, text="GOMOKU ONLINE", anchor=CENTER)
        lblInfo.grid(row=0, column=0, columnspan=2, pady=4, padx=5, sticky=E+W)

        lblName = Label(self, text="Your Name")
        lblName.grid(row=1, column=0, pady=4, padx=5, sticky=W)

        entryName = Entry(self)
        self.entryName = entryName
        entryName.grid(row=1, column=1, pady=4, padx=5, columnspan=4, sticky=E)

        lblServer = Label(self, text="Server IP")
        lblServer.grid(row=2, column=0, pady=4, padx=5, sticky=W)

        entryIP = Entry(self) 
        self.entryIP = entryIP
        entryIP.insert(0, "localhost")       
        entryIP.grid(row=2, column=1, pady=4, padx=5, columnspan=4)

        lblServer = Label(self, text="Server Port")
        lblServer.grid(row=3, column=0, pady=4, padx=5, sticky=W)

        entryPort = Entry(self)
        self.entryPort = entryPort
        entryPort.insert(0, 55555)
        entryPort.grid(row=3, column=1, pady=4, padx=5, sticky=E)
        
        PLbtn = Button(self, text="Play", command=self.onLogin)
        PLbtn.grid(row=4, column=0, pady=4, padx=5, columnspan=5, sticky=E+W)

    
    def onLogin(self):      
        global cd_name
        global cd_host
        global cd_port
        global cd_clientsocket
        global cd_addr

        cd_name = self.entryName.get()
        cd_host = self.entryIP.get()
        cd_port = int(self.entryPort.get())

        cd_clientsocket.connect(cd_addr)

        # Kirim pesan bahwa player login ke server agar dicatat
        sendMessage({"type":"login","name":cd_name})

        self.destroy()
        app = Lobby(self.parent)