lista1 = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
lista2 = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
lista3 = []

aux = 0
for i in lista1:
    for j in lista2:
        x = lista1[i] * lista2[i]
        aux = x
    lista3.append(aux)
print(lista3)