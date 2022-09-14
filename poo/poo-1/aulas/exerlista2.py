import random

sorteio = []

intervalo2 = 1
intervalo1 = 0

while intervalo2 > intervalo1:
    intervalo1 = int(input('Digite o primeiro intevalo: '))
    intervalo2 = int(input('Digite o segundo intevalo: '))

qtd = int(input('Digite quantos números serão sorteados: '))
i = 0

while i < qtd:
    sorte = random.randint(intervalo1, intervalo2)
    sorteio.append(sorte)
    
    if sorteio.count(sorte) > 1:
        sorteio.remove(sorte)
        i -= 1
    i += 1

print(sorteio)