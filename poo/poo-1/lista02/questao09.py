agenda = []

qtd = int(input('Digite a quantidade de pessoas da agenda: '))
for i in range(0, qtd):
    agenda.append([])
x=0

for i in agenda:
    nomePessoa = input('Digite o nome: ')
    enderecoPessoa = input('Digite o endereço: ')
    cepPessoa = int(input('Digite a cep: '))
    bairroPessoa = input('Digite o bairro: ')
    telefonePessoa = int(input('Digite a telefone: '))
    
    agenda[x].append(nomePessoa)
    agenda[x].append(enderecoPessoa)
    agenda[x].append(cepPessoa)
    agenda[x].append(bairroPessoa)
    agenda[x].append(telefonePessoa)
    x+=1

agenda.reverse()

aux = 0
for i in agenda:
    print(agenda[aux])
    aux += 1