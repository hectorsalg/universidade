import socket
# ipconfig CMD
ip = '10.180.84.97'
port = 3232
addr = ((ip, port))
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect(addr)

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