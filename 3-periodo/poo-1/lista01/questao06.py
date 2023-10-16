def is_primo(n):
    cont = 0
    for i in range(1, n+1):
        if n % i == 0:
            cont += 1
    if cont > 2:
        return False
    else:
        return True

def entrePrimos(n1, n2):
    flag = False
    for i in range(n1, n2 + 1):
        if is_primo(i):
            flag = True
            print(i)
    if flag == False:
        print('Não existe nenhum número primo neste intervalo!')