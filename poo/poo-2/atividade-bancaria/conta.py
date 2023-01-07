from historico import Historico

import datetime as dt

tempo = dt.datetime.now().strftime("%d/%m/%Y %H:%M:%S")


class Conta:

    __slots__ = ['_numero', '_titular', '_saldo',
                 '_limite', '_historico', 'Banco', '_user', '_password']

    _total_contas = 0

    @staticmethod
    def getTotalContas():
        return Conta._total_contas

    def __init__(self, numero, cliente, saldo, limite, user, password):
        self._numero = numero
        self._titular = cliente
        self._saldo = saldo
        self._limite = limite
        self._user = user
        self._password = password
        self._historico = Historico()

    def deposita(self, valor, flag = True):
        if (self._saldo + valor) > self._limite:
            return False
        self._saldo += valor
        if flag:
            self._historico.transacoes.append(
            f'Deposito de {valor} na data {tempo}')
        return True

    def saca(self, valor, flag = True):
        if (self._saldo < valor):
            return False
        else:
            self._saldo -= valor
            if flag:
                self._historico.transacoes.append(
                f'Saque de {valor} na data {tempo}')
            return True

    def transfere_para(self, destino, valor):
        retirou = self.saca(valor, flag = False)
        if not (retirou):
            return False
        else:
            destino.deposita(valor, flag = False)
            self._historico.transacoes.append(
                f'Transferência realizada')
            destino._historico.transacoes.append(
                f'Transferência realizada')
            return True

    def extrato(self):
        self._historico.transacoes.append(
            f'Tirou extrato - saldo de {self._saldo} na data {tempo}')

    # get numero
    @property
    def numero(self):
        return self._numero

    @numero.setter
    def numero(self, numero):
        self._numero = numero

    # get titular
    @property
    def titular(self):
        return self._titular.nome, self._titular.sobrenome, self._titular.cpf

    # get saldo
    @property
    def saldo(self):
        return self._saldo

    # get limite
    @property
    def limite(self):
        return self._limite

    # gethistorico
    @property
    def historico(self):
        return self._historico


    # get user
    @property
    def usuario(self):
        return self._user

    # get senha
    @property
    def senha(self):
        return self._senha