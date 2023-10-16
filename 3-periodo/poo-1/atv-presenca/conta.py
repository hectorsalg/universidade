import datetime
from random import randint

class Conta:
    
    __slot__ = ['_titular', '_numero', '_saldo', '_historico', '_criacao', '_total_contas', '_lista']

    _total_contas = 0

    def __init__(self, titular, numero = 0, saldo = 0.0):
        numero = randint(100, 999)
        self._titular = titular
        self._numero = numero
        self._saldo = saldo
        self._historico = Historico()
        self._criacao = Historico()._data_criacao.isoformat(' ', 'minutes')
        self._total_contas += 1
    
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
        else:
            self._saldo = saldo
        
    def listar(self):
        print(f'Nome do titular da conta: {self._titular._nome}')
        print(f'Cpf do titular da conta: {self._titular._cpf}')
        print(f'Telefone do titular da conta: {self._titular._telefone}')
        print(f'Endereço do titular da conta: {self._titular._endereco}')
        print(f'Número da conta: {self._numero}')
        print(f'Saldo da conta: {self.saldo:.2f}')
        
    def sacar(self, valor):
        self.saldo -= valor
        self._saque = datetime.datetime.now().isoformat(' ', 'minutes')
        self._historico.add_transacoes(f'Data {self._saque} -{valor:.2f}')

        
    def depositar(self, valor):
        self.saldo += valor
        self._deposito = datetime.datetime.now().isoformat(' ', 'minutes')
        self._historico.add_transacoes(f'Data {self._deposito}: +{valor:.2f}')

    def transferir(self, conta, valor):
        self.sacar(valor)
        conta.depositar(valor)
    
    def hist(self):
        self._lista = []
        print(f'Data de Criação da conta: {self._criacao}')
        for t in self._historico._transacao:
            self._lista.append(t)
        print(self._lista)

class Cliente:

    def __init__(self, nome, cpf, telefone, endereco):
        self._nome = nome
        self._cpf = cpf
        self._telefone = telefone
        self._endereco = endereco

class Historico:
    
    def __init__(self):
        self._data_criacao = datetime.datetime.now()
        self._transacao = []

    def add_transacoes(self, t):
        self._transacao.append(t)
