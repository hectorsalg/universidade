dicionario = {}
qtd = int(input('Digite a quantidade de pessoas: '))

for i in range(0, qtd):
    cpf = input('Digite o cpf: ')
    nome = input('Digite o nome: ')
    idade = int(input('Digite a idade: '))
    dicionario[cpf] = [nome, idade]
# nome
lista1 = [lista[0] for lista in dicionario.values() if lista[1] >= 18]
print(lista1)
# cpf
lista2 = [i for i in dicionario if dicionario[i][1] >= 18]
print(lista2)
# cpf e nome
lista3 = [[cpf, lista[0]] for lista in dicionario.values() if lista[1] >= 19]
print(lista3)