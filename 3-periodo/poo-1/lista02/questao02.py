lista = [0, 1, [2, [3, 4]], 5]

def questao2(lista):
    for i in range(len(lista)):
        if type(lista[i]) == list:
            for j in range(len(lista[i])):
                if type(lista[i][j]) == list:
                    for k in range(len(lista[i][j])):
                        print(lista[i][j][k], end=' ')
                else:
                    print(lista[i][j], end=' ')
        else:
            print(lista[i], end=' ')

questao2(lista)