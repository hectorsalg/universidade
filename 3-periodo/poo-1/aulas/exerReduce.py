import functools as ft

lista = [1, 2, 3, 4, 5]
def soma(x, y):
    return x+y
resultado = ft.reduce(soma, lista)

print(resultado)
