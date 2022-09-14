import random
loteria = []
cartao1 = []
cartao2 = []
cartao3 = []

for i in range(0, 13):
    numLoto = random.randint(1, 3)
    loteria.append(numLoto)
    numLoto = random.randint(1, 3)
    cartao1.append(numLoto)
    numLoto = random.randint(1, 3)
    cartao2.append(numLoto)
    numLoto = random.randint(1, 3)
    cartao3.append(numLoto)
    
def compara(loteria, cartao):
    ponto = 0
    for i in range(0, 13):
        if cartao[i] == loteria[i]:
            ponto += 1
    return ponto
print(f'L: {loteria}')
print(f'1: {cartao1}')
print(f'2: {cartao2}')
print(f'3: {cartao3}')


print(f'Pontos Apostador 1: {compara(loteria, cartao1)}')
print(f'Pontos Apostador 2: {compara(loteria, cartao2)}')
print(f'Pontos Apostador 3: {compara(loteria, cartao3)}')

if compara(loteria, cartao1) == 13:
    print('Ganhador: Apostador 1')
elif compara(loteria, cartao2) == 13:
    print('Ganhador: Apostador 2')
elif compara(loteria, cartao3) == 13:
    print('Ganhador: Apostador 3')
elif compara(loteria, cartao1) >= compara(loteria, cartao2) and compara(loteria, cartao1) >= compara(loteria, cartao3):
    print('Apostador 1 tem mais pontos!')
elif compara(loteria, cartao2) >= compara(loteria, cartao1) and compara(loteria, cartao2) >= compara(loteria, cartao3):
    print('Apostador 2 tem mais pontos!')
else: 
    print('Apostador 3 tem mais pontos!')