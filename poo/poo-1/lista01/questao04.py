def fat(num):
    if num == 0 or num == 1:
        return 1
    else:
        return num * fat(num - 1)

num = int(input('Informe um valor para o fatorial: '))
print(f'O fatorial de {num} é {fat(num)}!')