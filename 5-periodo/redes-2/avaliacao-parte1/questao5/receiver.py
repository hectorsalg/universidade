import socket
import checksum

def receiver():
    receiver_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    receiver_socket.bind(("0.0.0.0", 12345))
    
    while True:
        data, addr = receiver_socket.recvfrom(1024)
        message = data.decode()
        
        if message == "The End":
            print("Fim da transmissão")
            break
        
        msg_bits, received_checksum = message.split(',')
        bits = [int(bit) for bit in msg_bits]
        calculated_checksum = checksum.calculate_checksum(bits)
        
        if calculated_checksum == int(received_checksum):
            print(f"Mensagem recebida corretamente: {msg_bits}")
        else:
            print(f"Erro na mensagem recebida: {msg_bits}")

    receiver_socket.close()

if __name__ == "__main__":
    receiver()
