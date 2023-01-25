import socket
# ipconfig CMD
ip = 'localhost'
port = 3232
addr = ((ip, port))
serv_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serv_socket.bind(addr)
serv_socket.listen(1)
print('aguardando conexão...')
con, cliente = serv_socket.accept()
print('conectado')
print('aguardadando mensagem...')

while(True):
    try:
        recebe = con.recv(1024)
        if recebe.decode() == 'tchau':
            serv_socket.close()
            break
        enviar = input('digite uma mensagem para enviar ao cliente: ')
        print('mensagem recebida: ' + recebe.decode())
        con.send(enviar.encode())
    except:
        serv_socket.close()
        break