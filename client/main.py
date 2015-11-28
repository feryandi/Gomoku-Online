from Tkinter import *
import tkMessageBox
from socket import *
import struct
import thread
import json

from login import *
from client_data import *

def main():
	global root
	
	app = Login(root)

	root.mainloop()

if __name__ == '__main__':
	main()
