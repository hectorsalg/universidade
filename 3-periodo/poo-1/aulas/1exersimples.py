a = float(input('Tamanho do lado A: '))
b = float(input('Tamanho do lado B: '))
c = float(input('Tamanho do lado C: '))

if (a >= (b + c)) or (b >= (a + c)) or (c >= (a + b)):
    print('Não é possível formar um triângulo!')
elif a == b and b == c:
    print('Triângulo Equilátero!')
elif a != b and b != c and a != c:
    print('Triângulo Escaleno!')
else:
    print('Triângulo Isóceles!')