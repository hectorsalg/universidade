import socket, threading

class ClienteThread(threading.Thread):
    def __init__(self, clientAddress, clientesocket):
        threading.Thread.__init__(self)
        self.csocket = clientesocket
        self.name = ''
        self.addr = clientAddress
        print('Nova conexão: ', clientAddress)

    def run(self):
        self.name = self.csocket.recv(1024).decode()
        print(self.name, "se conectou!")
        msg = ''
        while True:
            data = self.csocket.recv(1024)
            msg = data.decode()
            if msg == 'tchau':
                break
            print('from', self.name+": ", msg)
            self.csocket.send(msg.encode())
        print('Client at ', self.addr, 'disconnected...')
if __name__ == '__main__':
    localhost = 'localhost'
    port = 1234
    addr = (localhost, port)
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    #server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADOR, 1)
    server.bind(addr)
    print('Servidor iniciado!')
    print('Aguardando nova conexão...')
    while True:
        server.listen(1)
        clientsock, clientAddress = server.accept()
        newthread = ClienteThread(clientAddress, clientsock)
        newthread.start()