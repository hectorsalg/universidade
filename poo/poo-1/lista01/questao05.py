def fat(num):
    if num == 0 or num == 1:
        return 1
    else:
        return num * fat(num - 1)

N = int(input('Informe o valor de N: '))
P = int(input('Informe o valor de P: '))
R = int(input('Informe o valor de R: '))

arranjo = fat(N) / fat(N - P)
comb = fat(N) / fat(R) * fat(N - R)

print(f'O arranjo equivale a {arranjo}!')
print(f'A combinação equivala a {comb}')