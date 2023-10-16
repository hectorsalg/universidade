l1 = float(input('primeiro lado: '))
l2 = float(input('segundo lado: '))
l3 = float(input('terceiro lado: '))

if l1 > l2 + l3:
    print('não é um triangulo')
elif l2 > l1 + l3:
    print('não é um triangulo')
elif l3 > l1 + l2:
    print('não é um triangulo')
elif l1 == l2 == l3:
    print('É um triângulo Equilátero!')
elif l1 != l2 and l1 == l3 or l2 != l3 and l2 == l1 or l3 == l2 and l3 != l1:
    print('É um triângulo Isóceles!')
else:
    print('É um triângulo Escaleno!')