agenda = {}

def incluirNovoNome(nome, numero):
    lista = []
    lista.append(numero)
    agenda[nome] = lista

def incluirTelefone(nome, novoNumero):
    flag = False
    for i in agenda:
        if i == nome:
            flag = True
        if flag == True:
            lista = agenda[nome]
            lista.append(novoNumero)
            agenda[nome] = lista
    if flag == False:
        incluirNome = int(input('Deseja incluir este nome e número na agenda? 1 - Sim, 2 - Não\n'))
        if incluirNome == 1:
            incluirNovoNome(nome, novoNumero)
        elif incluirNome == 2:
            return 0

def excluirTelefone(nome, numero):
    lista = agenda[nome]
    lista.remove(numero)
    agenda[nome] = lista
    if agenda[nome] == []:
        agenda.pop(nome)

def excluirNome(nome):
    agenda.pop(nome)

def consultarTelefone(nome):
    return agenda[nome]

escolha = 0

while escolha >= 0:
    print('Menu\n'
          '1 - Incluir Novo Nome\n'
          '2 - Incluir Telefone\n'
          '3 - Excluir Telefone\n'
          '4 - Excluir Nome\n'
          '5 - Consultar Telefone\n'
          'Números negativos para fechar o programa!')

    escolha = int(input('Qual sua escolha? '))
    if escolha == 1:
        nome = input('Digite o nome: ')
        telefone = input('Digite o telefone: ')
        incluirNovoNome(nome, telefone)
    elif escolha == 2:
        nome = input('Digite o nome: ')
        telefone = input('Digite o telefone: ')
        incluirTelefone(nome, telefone)
    elif escolha == 3:
        nome = input('Digite o nome: ')
        telefone = input('Digite o telefone: ')
        excluirTelefone(nome, telefone)
    elif escolha == 4:
        nome = input('Digite o nome: ')
        excluirNome(nome)
    elif escolha == 5:
        nome = input('Digite o nome: ')
        consultarTelefone(nome)
    print('\n', agenda, '\n')