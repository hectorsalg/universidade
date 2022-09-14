obj = 0

while obj != 'sair':
    obj = input('Informe a forma do objeto: ')

    if obj == 'triângulo':
        altura = float(input('Informe a altura do triângulo: '))
        base = float(input('Informa a base do triângulo: '))

        area = (base * altura) / 2
        print(f'A área do triângulo é {area}')
        print('')

    elif obj == 'quadrado':
        lado = float(input('Informe o lado do quadrado: '))
    
        area = lado * lado
        print(f'A área do quadrado é {area}')
        print('')

    elif obj == 'círculo':
        raio = float(input('Infome o raio do círculo: '))
        pi = 3.14

        area = pi * raio * raio
        print(f'A área do círculo é {area}')
        print('')

    else:
        print('Forma inválida!')
        print('')
