from classe import ControleRemoto

i = 0
controle = ControleRemoto()
while i != 7:
    print('1- Aumentar Volume\t2- Diminuir Volume\n3- Avançar Canal\t4- Voltar Canal\n5- Escolher Canal\t6- Consultar Volume e Canal\n7- Finalizar Programa')
    i = int(input('Digite sua escolha: '))
    if i == 1:
        controle.aumentar()

    elif i == 2:
        controle.diminuir()

    elif i == 3:
        controle.passarCanal()
    
    elif i == 4:
        controle.voltarCanal()

    elif i == 5:
        controle.trocarCanal()
    
    elif i == 6:
        controle.consultar()
    
    elif i == 7:
        break
    
    else:
        print('Número inválido!')

    
