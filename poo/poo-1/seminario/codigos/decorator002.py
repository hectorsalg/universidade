def textoGrande(texto):
    return texto.upper()

def textoPequeno(texto):
    return texto.lower()

def aviso(func):

    avisando = func('Esta mensagem foi criada por uma função passada como argumento!')
    print(avisando)

aviso(textoGrande)
aviso(textoPequeno)