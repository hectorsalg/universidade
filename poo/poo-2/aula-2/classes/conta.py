from classes.historico import Historico

import datetime as dt

tempo = dt.datetime.now().strftime("%d/%m/%Y %H:%M:%S")


class Conta:
    def __init__(self, numero, cliente, saldo, limite):
        self.numero = numero
        self.titular = cliente
        self.saldo = saldo
        self.limite = limite
        self.historico = Historico()

    def deposita(self, valor):
        self.saldo += valor
        self.historico.transacoes.append(
            f'Deposito de {valor} na data {tempo}')
        return True

    def saca(self, valor):
        if (self.saldo < valor):
            return False
        else:
            self.saldo -= valor
            self.historico.transacoes.append(
                f'Saque de {valor} na data {tempo}')
            return True

    def transfere_para(self, destino, valor):
        retirou = self.saca(valor)
        if not (retirou):
            return False
        else:
            destino.deposita(valor)
            self.historico.transacoes.append(
                f'Transferência de {valor} para conta {destino.numero} na data {tempo}')
            destino.historico.transacoes.append(
                f'Transferência de {valor} recebida de conta {self.numero} na data {tempo}')
            return True

    def extrato(self):
        print(f'Numero: {self.numero}.\nSaldo: {self.saldo}.')
        self.historico.transacoes.append(
            f'Tirou extrato - saldo de {self.saldo} na data {tempo}')
