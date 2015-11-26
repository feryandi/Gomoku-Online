from socket import *

# Connection 
cd_host = 'localhost'
cd_port = 55555
cd_addr = (cd_host,cd_port)
cd_clientsocket = socket(AF_INET, SOCK_STREAM)

# Player Data
cd_name = 'undefined'
cd_board = [ [ 'x' for x in range(20) ] for x in range(20) ]