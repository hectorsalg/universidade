import random

numSort = random.randint(0, 100)
print(numSort)
num = -1
tentativa = 0
jogar = ''

print('Adivinhe o número!')

while num != numSort:
    if tentativa < 10:
        num = int(input('Qual seu número?\n'))
        tentativa += 1
        print(f'{tentativa}ª tentativa')
        if num == numSort:
            jogar = input('Você acertou! Deseja jogar novamente?\n')
            if jogar == 'sim' or jogar == 'Sim':
                num = -1
                numSort = random.randint(0, 100)
                tentativa = 0
            else:
                break
    else:
        print('Você chegou no limite de tentativas!')
        break
