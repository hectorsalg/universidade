import socket
from banco import *

class Servidor():
    
    def __init__(self):
        host = 'localhost'
        port = 3333
        addr = (host, port)
        self.serv_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM) #cria o socket
        self.serv_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1) #reinicia o socket
        self.serv_socket.bind(addr) #define as portas e quais ips podem se conectar com o servidor
        self.serv_socket.listen(10) #define o limite de conexões
        print("aguardando conexão...")
        con, cliente = self.serv_socket.accept() #servidor aguardando conexão
        print("conectado")
        print("aguardando mensagem...")

        while True:
            recebe = con.recv(2048).decode().split("*") 
            print(f"recebe completo: {recebe}")
            metodo = recebe.pop(0)
            print(f"recebe sem o metodo: {recebe}")
            banco = Banco()
            func = getattr(banco, metodo)
            re = func(*recebe)
            print(f"re {re}")
            con.send(f'{re}'.encode('utf-8')) #'utf-8'
        self.serv_socket.close()

c = Servidor()