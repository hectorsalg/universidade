from classes.historico import Historico

import datetime as dt

tempo = dt.datetime.now().strftime("%d/%m/%Y %H:%M:%S")


class Conta:

    __slots__ = ['_numero', '_cliente', '_saldo', '_limite']

    _total_contas = 0

    @staticmethod
    def getTotalContas():
        return Conta._total_contas

    def __init__(self, numero, cliente, saldo, limite):
        self._numero = numero
        self._titular = cliente
        self._saldo = saldo
        self._limite = limite
        self._historico = Historico()
        Conta._total_contas += 1

    # get and set numero
    @property
    def numero(self):
        return self._numero

    @numero.setter
    def numero(self, numero):
        self._numero = numero

    # get and set titular
    @property
    def titular(self):
        return self._titular

    @titular.setter
    def titular(self, cliente):
        self._titular = cliente

    # get and set limite
    @property
    def limite(self):
        return self._limite

    @limite.setter
    def limite(self, limite):
        self._limite = limite

    # get and set historico
    @property
    def historico(self):
        return self._historico

    @historico.setter
    def historico(self, historico):
        self._historico = historico

    def deposita(self, valor):
        self._saldo += valor
        self._historico.transacoes.append(
            f'Deposito de {valor} na data {tempo}')
        return True

    def saca(self, valor):
        if (self._saldo < valor):
            return False
        else:
            self._saldo -= valor
            self._historico.transacoes.append(
                f'Saque de {valor} na data {tempo}')
            return True

    def transfere_para(self, destino, valor):
        retirou = self.saca(valor)
        if not (retirou):
            return False
        else:
            destino.deposita(valor)
            self._historico.transacoes.append(
                f'Transferência de {valor} para conta {destino._numero} na data {tempo}')
            destino._historico.transacoes.append(
                f'Transferência de {valor} recebida de conta {self._numero} na data {tempo}')
            return True

    def extrato(self):
        print(f'Numero: {self._numero}.\nSaldo: {self._saldo}.')
        self._historico.transacoes.append(
            f'Tirou extrato - saldo de {self._saldo} na data {tempo}')
