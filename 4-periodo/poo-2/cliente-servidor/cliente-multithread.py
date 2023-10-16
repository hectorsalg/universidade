import socket
ip = '10.180.47.52'
port = 5003
name = input('Qual seu nome? ')
addr = ((ip, port))
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect(addr)
client_socket.send(name.encode())
while(True):
    mensagem = input('digite uma mensagem para enviar ao servidor: ')
    while (True):
        client_socket.send(mensagem.encode())
        client_socket.send(mensagem.encode())
        client_socket.send(mensagem.encode())
        client_socket.send(mensagem.encode())
        client_socket.send(mensagem.encode())
        client_socket.send(mensagem.encode())