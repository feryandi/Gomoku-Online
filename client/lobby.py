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
        thread.start_new_thread(self.listener, ())       
        
    def initUI(self):
        # TO-DO
        # Minta list room yang terdaftar diserver
        sendMessage({"type":"request", "object":"rooms"})

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

        self.entry = Entry(self)
        self.entry.grid(row=0, column=1, pady=4, padx=5, columnspan=4, sticky=E)
        
        CRbtn = Button(self, text="Create", command=self.newRoom)
        CRbtn.grid(row=0, column=5, pady=4, padx=5, sticky=E)

        # TO-DO
        # Bikin fungsi buat bikin room baru dan kirim pesan ke server kalo player mau bikin room

        self.roomlist = Listbox(self)
        self.roomlist.bind("<<ListboxSelect>>", self.onRoomSelect)
        self.roomlist.grid(row=1, column=0, rowspan=6, columnspan=6, sticky=E+W+S+N, padx=5, pady=5)
        
        JOINbtn = Button(self, text="JOIN", width=25, command=self.onJoin)
        JOINbtn.grid(row=7, column=0, pady=4, padx=6, columnspan=6, sticky=E+W)


    def onRoomSelect(self, var):
        global cd_ridSelected
        cd_ridSelected = var.widget.curselection()
        # mengeluarkan () kalau list kosong
        # mengeluarkan (x,) kalau ada yang di select

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

    def newRoom(self):
        if not(self.entry.get() == ''):
            sendMessage({"type":"newroom","name":self.entry.get()})

    def interpreter(self, message):
        msg = json.loads(message)

        if msg['type'] == 'response':
            if msg['object'] == 'rooms':
                # Refresing rooms
                self.roomlist.delete(0, END)
                for room in msg['data']:
                    self.roomlist.insert(END, room['name'])

    def listener(self):
        global cd_clientsocket        
        
        print "Listening to server"
        while True:
            size = struct.unpack("i", cd_clientsocket.recv(struct.calcsize("i")))
            data = ""
            while len(data) < size[0]:
                msg = cd_clientsocket.recv(size[0] - len(data))
                if not msg:
                    return None
                data += msg

            if not data:
                break
            else:
                print data
                self.interpreter(data)
        cd_clientsocket.close()


