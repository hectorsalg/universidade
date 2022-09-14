par = []
impar = []
zero = []

num = 0
while num >= 0:
    num = int(input('Digite um número: '))

    if num < 0:
        break
    elif num == 0:
        zero.append(num)
    elif num % 2 == 0:
        par.append(num)
    else:
        impar.append(num)

par.sort()
impar.sort()
print(par + zero + impar)