import abc
from random import randint

class Conta(abc.ABC):
    
    __slot__ = ['_titular', '_numero', '_saldo', '_limite']

    _total_contas = 0

    def __init__(self, numero, titular, saldo = 0.0, limite = 1000.0):
        self._titular = titular
        self._numero = numero
        self._saldo = saldo
        self._limite = limite
    
    @staticmethod
    def get_contas():
        return Conta._total_contas

    @property
    def numero(self):
        return self._numero

    @property
    def saldo(self):
        return self._saldo
    
    @saldo.setter
    def saldo(self, saldo):
        if self._saldo < 0:
            print('Saldo não pode ser negativo!')
            return False
        else:
            self._saldo = saldo
            return True
        
    def __str__(self):
        return (f'titular da conta: {self._titular}\nNúmero da conta: {self._numero}\nSaldo da conta: {self.saldo:.2f}\nSaldo da conta: {self._limite:.2f}')
        
    def sacar(self, valor):
        self.saldo -= valor
        return True
        
    def depositar(self, valor):
        self.saldo += valor
        return True

    def transferir(self, conta, valor):
        self.sacar(valor)
        conta.depositar(valor)
        return True

    @abc.abstractclassmethod
    def atualizar(self, taxa):
        self._saldo += self._saldo * taxa
        return self._saldo

class ContaCorrente(Conta):

    def atualizar(self, taxa):
        self._saldo += self._saldo * taxa * 2
        return self._saldo, self

    def depositar(self, valor):
        self._saldo += valor - 0.10
        return True

class ContaPoupanca(Conta):

    def atualizar(self, taxa):
        self._saldo += self._saldo * taxa * 3
        return self._saldo

class ContaInvestimento(Conta):

    def atualizar(self, taxa):
        self._saldo += self._saldo * taxa * 5
        return self._saldo

class AtualizadorDeContas:

    def __init__(self, selic, saldo_total=0):
        self._selic = selic
        self._saldo_total = saldo_total

    @property
    def saldo_total(self):
        return self._saldo_total

    def roda(self, conta):
        print(f'Saldo anterior: {self._saldo_total}')
        self._saldo_total += conta.atualizar(self._selic)
        print(f'Saldo Final: {self._saldo_total}')
