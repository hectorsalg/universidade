import socket
from conta import Conta
# ipconfig CMD
class Server():
    def __init__(self):
        ip = '0.0.0.0'
        port = 3333
        addr = ((ip, port))
        self.serv_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.serv_socket.bind(addr)
        self.serv_socket.listen(1)
        print('aguardando conexão...')
        con, cliente = self.serv_socket.accept()
        print('conectado')
        print('aguardadando mensagem...')

        while(True):
            try:
                recebe = con.recv(1024).decode().split('*')
                print(f'recebe full: {recebe}')
                metodo = recebe.pop(0)
                print(f'recebe sem o metodo: {recebe}')
                conta = Conta()
                func = getattr(conta, metodo)
                resul = func(*recebe)
                print(f'resul: {resul}')
                con.send(f'{resul}'.encode())
                
                if recebe.decode() == 404:
                    self.serv_socket.close()
                    break
            except:
                self.serv_socket.close()
                break
c = Server()
