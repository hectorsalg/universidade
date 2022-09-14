def encontrar(palavra, letra):
    contador = 0
    for i in palavra:
        if i == letra:
            break
        elif i != letra:
            contador += 1
    print(contador)
    
palavra = input('Digite a palavra: ')
letra = input('Digite qual letra será pesquisada: ')

encontrar(palavra, letra)