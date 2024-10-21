def calculate_checksum(bits):
    """
    Calcula o checksum para uma lista de bits de 16 bits.
    """
    checksum = 0
    for bit in bits:
        checksum += bit
        if checksum > 0xFFFF:
            checksum = (checksum & 0xFFFF) + 1
    checksum = ~checksum & 0xFFFF
    return checksum
