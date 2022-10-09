import abc
from random import randint
from classes import *
 
class Autenticavel(abc.ABC):

    def autentica(self, numero):
        pass
class Cadastro(abc.ABC):

    def __init__(self, nome, empresa):
        self._nome = nome
        self._empresa = empresa

    def __str__(self):
        print(self._nome)
        print(self._empresa)
        return True
    
    @abc.abstractmethod
    def imprimir(self):
        pass

class Corredor(Cadastro):

    def __init__(self, nome, empresa, carro, numero):
        super().__init__(nome, empresa)
        self._carro = carro
        self._numero = numero

    @property
    def nome(self):
        return self._nome

    @nome.setter
    def nome(self, nome):
        self._nome = nome

    @property
    def empresa(self):
        return self._empresa

    @empresa.setter
    def empresa(self, empresa):
        self._empresa = empresa

    @property
    def carro(self):
        return self._carro

    @carro.setter
    def carro(self, carro):
        self._carro = carro
    
    @property
    def numero(self):
        return self._numero

    @numero.setter
    def numero(self, numero):
        self._numero = numero

    def __str__(self):
        super().__str__()
        print(self.carro)
        print(self.numero)
        return True

    def autentica(self, numero):
        if self.numero == numero:
            print('Corredor Inscrito!')
            return True
        else:
            return False

class Listas():

    def __init__(self):
        self._total_corredores = {}
        self._voltas_corredor = {}

    def addCorredor(self, nome, empresa, carro, numero):
        if numero not in self._total_corredores.keys():
            self._total_corredores[numero] = [nome, empresa, carro, numero]
            self._voltas_corredor[numero] = []
            return True, 'Corredor adicionado com sucesso!'
        else:
            return False, 'Número de corredor já cadastrado!'

    def addVolta(self, numero):
        if numero in self._voltas_corredor:
            self._voltas_corredor[numero] = [randint(100, 120), randint(100, 120), randint(100, 120)]
            return True, 'Voltas do corredor registradas com sucesso!'
        else:
            return False, 'Não foi possível realizar voltas!'

    def voltasCorredor(self, numero):
        if numero in self._voltas_corredor.keys():
            print(self._voltas_corredor[numero])
            return True, 'Visualização de voltas realizada com sucesso!'
        else:
            return False, 'Não foi possível realizar visualização de voltas!'

    def detalhesCorredor(self, numero):
        if numero in self._total_corredores.keys():
            print(self._total_corredores[numero])
            return True, 'Visualização de voltas realizada com sucesso!'
            
    def imprimirCorredores(self):
        print(self._total_corredores)
        return True

    def inscricao(self, obj):
        if isinstance(obj, Autenticavel):
            numero = int(input('Informe o número do corredor: '))
            return obj.autentica(numero)
        else:
            print('Método autentica não implementado!')
            return False