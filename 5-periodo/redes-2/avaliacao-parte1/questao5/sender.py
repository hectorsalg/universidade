import socket
import random
import checksum


def generate_bits(n):
    return [random.randint(0, 1) for _ in range(n)]


def sender():
    sender_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    receiver_address = ("receiver", 12345)

    n = random.randint(5, 10)

    for i in range(n):
        bits = generate_bits(16)
        msg = ''.join(map(str, bits))
        checksum_value = checksum.calculate_checksum(bits)
        sender_socket.sendto(
            f"{msg},{checksum_value}".encode(), receiver_address)
        print(f"Mensagem {i+1} enviada: {msg} com checksum {hex(checksum_value)}")

    sender_socket.sendto("The End".encode(), receiver_address)
    sender_socket.close()


if __name__ == "__main__":
    sender()
