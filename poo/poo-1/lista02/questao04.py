def ordenaString(string):
    lista = list(string)
    for i in range(len(lista)):
        for j in range(len(lista)):
            if lista[i] < lista[j]:
                aux = lista[i]
                lista[i] = lista[j]
                lista[j] = aux
    nova_string = '' .join(lista)
    return nova_string

nome = input('Digite a String: ')
print(ordenaString(nome))