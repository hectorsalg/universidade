from classe import Elevador

i = 0
elevador = Elevador(0, 8, 3, 0)
while i != 7:
    print('1- Configurar Elevador\t2- Inicialziar\n3- Entra\t\t4- Sai\n5- Sobe\t\t\t6- Desce\n7- Finalizar Programa')
    i = int(input('Digite sua escolha: '))
    if i == 1:
        totalAndares = int(input('Digite o total de andares do prédio: '))
        andarAtual = int(input('Digite o andar atual: '))
        capacidade = int(input('Digite a capacidade do elevador: '))
        qtdPessoas = int(input('Digite a quantidade de pessoas no elevador: '))

        if qtdPessoas > capacidade:
            print('Elevador possui muita gente!')
            print('\n')
            qtdPessoas = int(input('Digite a quantidade de pessoas no elevador: '))

        elevador = Elevador(andarAtual, totalAndares, capacidade, qtdPessoas)
    
    elif i == 2:
        totalAndares = int(input('Digite o total de andares do prédio: '))
        capacidade = int(input('Digite a capacidade do elevador: '))
        elevador.inicializa(capacidade, totalAndares)
    
    elif i == 3:
        elevador.entra()
    
    elif i == 4:
        elevador.sai()
    
    elif i == 5:
        elevador.sobe()
    
    elif i == 6:
        elevador.desce()
    
    elif i == 7:
        break

    else:
        print('Número inválido!')