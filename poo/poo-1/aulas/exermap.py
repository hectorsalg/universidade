lista = []

def is_par(num):
    if num % 2 == 0 and num != 0:
        return num

def is_impar(num):
    if num % 2 != 0:
        return num
def is_zero(num):
    if num == 0:
        return num == 0

num = 0
while num >= 0:
    num = int(input('Digite um número: '))
    if num < 0:
        break
    else: 
        lista.append(num)
# lista.sort() caminho mais rápido para ordenar lista, poré modifica lista original
par = list(filter(is_par, lista))
impar = list(filter(is_impar, lista))
zero = list(filter(is_zero, lista))

par.sort()
impar.sort()

print(par + zero + impar)