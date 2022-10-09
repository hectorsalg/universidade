from classes import *

total_corredores = {}

sa = SistemaAutenticacao()

def menu():
    print('1 - Cadastrar Corredor\t2 - Partida de Corredores\t3 - Voltas de Corredor Específico\n4 - Imprimir Detalhes de Corredor\t5 - Imprimir Todos os Corredores\t6- Verificar se Corredor foi Inscrito\n7 - Sair')

    return int(input('Digite uma opção: '))

while True:
    
    op = menu()
    total_c = 0
    if op == 1:
        total_c += 1
        nome = input('Digite o nome do corredor: ')
        empresa = input('Digite a empresa do corredor: ')
        carro = input('Digite o carro do corredor: ')
        numero = input('Digite o numero do corredor: ')
        c = Corredor(nome, empresa, carro, numero)
    
    elif op == 2:
        c.addVolta()

    elif op == 3:
        c.voltasCorredor()
    
    elif op == 4:
        retorno, mensagem = imprimirDetalhes()
        print(mensagem)

    elif op == 5:
        retorno, mensagem = imprimirLista()
        print(mensagem)

    # elif op == 6:
    #     l.inscricao()

    elif op == 7:
        break
