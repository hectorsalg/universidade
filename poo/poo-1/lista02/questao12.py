import random
kart = {}

for i in range(1, 4):
    nome = input(f'Digite o nome do corredor {i}: ')
    volta1 = int(input('Digite quantos segundos foi a primeira volta: '))
    volta2 = int(input('Digite quantos segundos foi a segunda volta: '))
    volta3 = int(input('Digite quantos segundos foi a terceira volta: '))
    kart[nome] = [volta1, volta2, volta3]

print(kart)

def media(corredor):
    n = 0
    aux = 0
    for i in corredor:
        aux += i
        n += 1
    media = aux/n
    return media

def nomeMelhorVolta(kart):
    lista = []
    for i in kart:
        for j in kart[i]:
            lista.append(j)
    lista.sort()
    melhorVolta = lista[0]
    for i in kart:
        for j in kart[i]:
            if j <= melhorVolta:
                menorNome = i
    return menorNome

def volta(kart):
    menor = 99999
    menorVolta = 0
    for i in kart[nome]:
        if i <= menor:
            menorVolta += 1
    return menorVolta

menorNome = nomeMelhorVolta(kart)
menorVolta = volta(kart)

print(f'A menor volta foi de {menorNome}, na volta {menorVolta}')

campeao = 10000
for i in kart:
    aux = media(kart[i])
    if campeao > aux:
        campeao = aux
        nomeCampeao = i
print(f'O campeão foi o/a corredor(a) {nomeCampeao}!')
 