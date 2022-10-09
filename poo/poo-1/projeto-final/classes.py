import abc
from random import randint
from classes import *
 
_total_corredores = {}
class Autenticavel(abc.ABC):

    def autentica(self, numero):
        pass
class Cadastro(abc.ABC):

    def __init__(self, nome, empresa):
        self._nome = nome
        self._empresa = empresa
    
    @abc.abstractmethod
    def imprimir(self):
        pass

class Corredor(Cadastro):

    def __init__(self, nome, empresa, carro, numero):
        super().__init__(nome, empresa)
        self._carro = carro
        self._numero = numero
        self._voltas_corredor = []
        if numero not in _total_corredores.keys():
            _total_corredores[numero] = [nome, empresa, carro, numero]
        else:
            print('Número de corredor já registrado!')

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

    def addVolta(self):
        if self._voltas_corredor != []:
            self._voltas_corredor = [randint(100, 120), randint(100, 120), randint(100, 120)]
            return True
        else:
            return False

    def voltasCorredor(self):
        print(self._voltas_corredor)
        return True

    def imprimir(self):
        print(f'Nome: {self.nome}, Empresa: {self.empresa}, Carro: {self.carro}, Número: {self.numero}')
        return True

    def autentica(self, numero):
        if self.numero == numero:
            print('Corredor Inscrito!')
            return True
        else:
            return False

class SistemaAutenticacao():

    def inscricao(self, obj):
        if isinstance(obj, Autenticavel):
            numero = int(input('Informe o número do corredor: '))
            return obj.autentica(numero)
        else:
            print('Método autentica não implementado!')
            return False