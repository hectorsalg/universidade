from classes import *

total_corredores = {}

l = Listas()

def menu():
    print('1 - Cadastrar Corredor\t2 - Partida de Corredores\t3 - Voltas de Corredor Específico\n4 - Imprimir Detalhes de Corredor\t5 - Imprimir Todos os Corredores\t6 - Sair')

    return int(input('Digite uma opção: '))

def corredor():
    nome = input('Digite o nome do corredor: ')
    empresa = input('Digite a empresa do corredor: ')
    carro = input('Digite o carro do corredor: ')
    numero = input('Digite o numero do corredor: ')
    return l.addCorredor(nome, empresa, carro, numero)

def voltas():
    numero = input('Digite o numero do corredor: ')
    return l.addVolta(numero)

def voltasCorridas():
    numero = input('Digite o numero do corredor: ')
    return l.voltasCorredor(numero)

def imprimirDetalhes():
    return l.detalhesCorredor()

def imprimirLista():
    return l.imprimirCorredores()
while True:
    
    op = menu()

    if op == 1:
        retorno, mensagem = corredor()
        print(mensagem)
    
    elif op == 2:
        retorno, mensagem = voltas()
        print(mensagem)

    elif op == 3:
        retorno, mensagem = voltasCorridas()
        print(mensagem)
    
    elif op == 4:
        retorno, mensagem = imprimirDetalhes()
        print(mensagem)

    elif op == 5:
        retorno, mensagem = imprimirLista()
        print(mensagem)

    elif op == 6:
        break
