import socket
import time
import json

def main():
    udp_ip = "receiver"  # Nome do serviço do receiver no Docker Compose
    udp_port = 5005
    duration = 5 * 60  # 5 minutos
    message_interval = 0.1  # Intervalo de envio em segundos
    total_sent = 0
    ack_timeout = 1  # Tempo limite para aguardar confirmação (em segundos)

    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.settimeout(ack_timeout)  # Define o timeout para o ack

    start_time = time.time()
    message_id = 0

    while time.time() - start_time < duration:
        message = {"id": message_id, "content": "message", "timestamp": time.time()}
        sock.sendto(json.dumps(message).encode(), (udp_ip, udp_port))
        total_sent += 1

        # Aguardar confirmação (ack) do receiver
        try:
            data, _ = sock.recvfrom(1024)
            ack = json.loads(data.decode())

            if ack.get("id") == message_id and ack.get("status") == "received":
                print(f"Ack recebido para a mensagem {message_id}")
                message_id += 1  # Incrementa o ID da mensagem
            else:
                print(f"Ack incorreto para a mensagem {message_id}, reenviando...")
        except socket.timeout:
            print(f"Ack não recebido para a mensagem {message_id}, reenviando...")

        time.sleep(message_interval)

    # Enviar mensagem de encerramento "The End"
    end_message = {"id": message_id, "content": "The End"}
    sock.sendto(json.dumps(end_message).encode(), (udp_ip, udp_port))

    # Receber a contagem de mensagens recebidas pelo receiver
    data, _ = sock.recvfrom(1024)
    received_count = int(data.decode())

    # Calcular a taxa de perda de mensagens
    lost_count = total_sent - received_count
    loss_rate = (lost_count / total_sent) * 100
    print(f"Total de mensagens enviadas: {total_sent}")
    print(f"Mensagens recebidas pelo receiver: {received_count}")
    print(f"Taxa de perda de mensagens: {loss_rate:.2f}%")

if __name__ == "__main__":
    main()
