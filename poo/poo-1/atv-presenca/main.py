from conta import Conta, Cliente

contas = {}

i = 0
while i != 7:
    print('1 - Criar Conta\n2 - Listar Contas\n3 - Sacar Valor\n4 - Depositar Valor\n5 - Excluir Conta\n6 - Transferir\n7 - Histórico\n8 - Sair\n')
    i = int(input('Digite sua escolha: '))
    if i == 1:
        nome = input('Digite o nome do titular: ')
        telefone = int(input('Digite o número de telefone do titular: '))
        cpf = int(input('Digite o CPF do titular: '))
        endereco = input('Digite o endereço do titular: ')

        titular = Cliente(nome, cpf, telefone, endereco)
        c = Conta(titular)
        contas[c.numero] = c
        print('\n')
        
    elif i == 2:
        flag = False
        for i in contas:
            contas[i].listar()
            flag = True
            print('\n')
        if flag == False:
            print('Não há contas cadastradas!')
            print('\n')
            
    elif i == 3:
        for i in contas:
            contas[i].listar()
            print('\n')
        saque = int(input('Digite o número da conta: '))
        valor = float(input('Digite o valor do saque: '))
        flag = False
        for i in contas.keys():
            if saque == i:
                contas[i].sacar(valor)
                flag = True
        if flag:
            print('Saque realizado com sucesso!')
        else:
            print('Não foi possível realizar saque!')
        print('\n')
        
    elif i == 4:
        for i in contas:
            contas[i].listar()
            print('\n')
        deposito = int(input('Digite o número da conta: '))
        valor = float(input('Digite o valor do deposito: '))
        flag = False
        for i in contas.keys():
            if deposito == i:
                contas[i].depositar(valor)
                flag = True
        if flag:
            print('Deposito reazilado com sucesso!')
        else:
            print('Não foi possível realizar deposito!')
        print('\n')
        
    elif i == 5:
        for i in contas:
            contas[i].listar()
            print('\n')
        excluir = int(input('Digite o número da conta que será excluida: '))
        flag = False
        for i in contas.keys():
            if excluir == i and contas[i].saldo == 0:
                flag = True
        if flag:
            contas.pop(excluir)
            print('Conta excluída com sucesso!')
        else:
            print('Não foi possível excluir conta!')
        
    elif i == 6:
        for i in contas:
            contas[i].listar()
            print('\n')
        transfere = int(input('Digite o número da conta que irá transferir: '))
        transfere2 = int(input('Digite o número da conta que receberá a transferência: '))
        valor = float(input('Digite o valor da transferência: '))
        flag = False
        for i in contas.keys():
            if transfere == i:
                for j in contas.keys():
                    if transfere2 == j:
                        contas[i].transferir(contas[j], valor)
                        flag = True
        if flag:
            print('Transferência realizada com sucesso!')
        else:
            print('Não foi possível realizar transferência!')
        print('\n')

    elif i == 7:
        for i in contas:
            contas[i].listar()
            print('\n')
        historico = int(input('Digite o número da conta para visualizar histórico: '))
        flag = False
        for i in contas.keys():
            if historico == i:
                contas[historico].hist()
                flag = True
        if flag:
            print('Acesso ao histórico realizado!')
        else:
            print('Não foi possível acessar histórico da conta!')
        print('\n')

    elif i == 8:
        break
