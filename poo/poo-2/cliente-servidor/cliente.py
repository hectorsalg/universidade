import socket
# ipconfig CMD
ip = 'localhost'
port = 1234
addr = ((ip, port))
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect(addr)
mensagem = input('digite seu nome: ')
client_socket.send(mensagem.encode())

while(True):
    try:
        mensagem = input('digite uma mensagem para enviar ao servidor: ')
        client_socket.send(mensagem.encode())
        if mensagem == 'tchau':
            client_socket.close()
            break
        print('mensagem enviada!')
        print('mensagem recebida: ' + client_socket.recv(1024).decode())
    except:
        client_socket.close()
        break