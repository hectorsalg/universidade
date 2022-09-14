num = int(input('Digite um número: '))
primos = [i for i in range(1, num + 1) if num % i == 0]

x = 0
for i in primos:
    x += 1
if x > 2:
    print('Não é primo!')
else:
    print('É primo!')
