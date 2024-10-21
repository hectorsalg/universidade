import socket
import time
import json
import numpy as np

def main():
    udp_ip = "0.0.0.0"
    udp_port = 5005

    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.bind((udp_ip, udp_port))

    message_count = 0
    rates = []
    last_timestamp = None

    while True:
        data, addr = sock.recvfrom(1024)
        message = json.loads(data.decode())

        if message["content"] == "The End":
            break

        message_id = message["id"]
        message_count += 1

        # Calcular taxa de recebimento
        timestamp = message["timestamp"]
        if last_timestamp is not None:
            interval = timestamp - last_timestamp
            rate = 1 / interval
            rates.append(rate)
        last_timestamp = timestamp

        # Enviar confirmação (ack) de volta ao sender
        ack = {"id": message_id, "status": "received"}
        sock.sendto(json.dumps(ack).encode(), addr)

    # Calcular métricas
    rate_min = np.min(rates) if rates else 0
    rate_max = np.max(rates) if rates else 0
    rate_avg = np.mean(rates) if rates else 0
    rate_std = np.std(rates) if rates else 0
    
    # Enviar a contagem de mensagens recebidas de volta ao sender
    sock.sendto(str(message_count).encode(), addr)

    print(f"Taxa de recebimento (mensagens/segundo):")
    print(f"Mínimo: {rate_min:.2f}, Máximo: {rate_max:.2f}, Média: {rate_avg:.2f}, Desvio padrão: {rate_std:.2f}")


if __name__ == "__main__":
    main()
