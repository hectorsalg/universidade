dicionario = {'nome': 'hector', 'idade': 19, 'sexo': 'm'}
teste = {'name': 'jose', 'idade': 19, 'sexo': 'm'}
copia = dicionario.copy()

print(copia)
print(dicionario)
print('\n')

print(dicionario['nome'])
print('\n')
'''
dicionario.clear()
print(dicionario)
print(copia)
print('\n')
'''

dicionario.update(teste)
print(dicionario)
print(copia)