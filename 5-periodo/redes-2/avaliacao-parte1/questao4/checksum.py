import random


def generate_bits(n):
    """
    Gera uma lista de n números inteiros (0 ou 1) representando bits.
    """
    return [random.randint(0, 1) for _ in range(n)]


def calculate_checksum(bits):
    """
    Calcula o checksum para uma lista de bits de 16 bits.
    A operação é feita bit a bit.
    """
    checksum = 0
    for bit in bits:
        checksum += bit
        # Se o checksum exceder 16 bits, ajusta para ficar dentro do limite de 16 bits
        if checksum > 0xFFFF:  # 65535 é o valor máximo para 16 bits
            checksum = (checksum & 0xFFFF) + 1
    checksum = ~checksum & 0xFFFF
    return checksum


def main():
    n = int(input("Digite quantas mensagens você deseja gerar: "))

    for i in range(n):
        print(f"Mensagem {i}:")
        tam_bits = 16
        bits = generate_bits(tam_bits)
        print("Bits gerados:", bits)
        checksum = calculate_checksum(bits)
        print("Checksum calculado:", hex(checksum))
        print()


if __name__ == "__main__":
    main()
