decimal = float(input('Informe o decimal: '))

resto1 = decimal
i = 1
bin2 = ''
while resto1 >= 1:
    bin = resto1 % 2
    bin = int(bin)
    bin2 = str(bin) + bin2
    resto1 = resto1 // 2
print(bin2)