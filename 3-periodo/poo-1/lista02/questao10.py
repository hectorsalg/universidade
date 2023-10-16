import math
import random
lista = []
for i in range(0, 100):
    lista.append(random.randint(1,100))
print(lista)

def media(lista):
    n = 0
    aux = 0
    for i in lista:
        aux += i
        n += 1
    media = aux/n
    return media

def mediana(lista):
    list(lista).sort()
    n = 0
    for n in lista:
        n += 1
    if n % 2 == 0:
        return lista[49]
    else:
        return (lista[49] + lista[50]) / 2

def variancia(lista):
    aux = media(lista)
    div = 0
    vari = 0
    for i in lista:
        vari += (i - aux)**2
        div += 1
    vari = vari / (div - 1)
    return vari

def desvioPadrao(lista):
    desvio = variancia(lista)
    desvio = math.sqrt(desvio)
    return desvio

print(f'A média é {media(lista)}')
print(f'A mediana é {mediana(lista)}')
print(f'A variância é {variancia(lista)}')
print(f'O desvio padrão é {desvioPadrao(lista)}')
