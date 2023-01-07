import datetime as dt


class Historico:

    __slots__ = ['data_abertura', 'transacoes']

    def __init__(self):
        self.data_abertura = dt.datetime.now().strftime("%d/%m/%Y %H:%M:%S")
        self.transacoes = []

    def imprime(self):
        data = f'Data de abertura: {self.data_abertura}\n'
        data += 'Transações: \n'
        for t in self.transacoes:
            data += f'- {t}\n'

        return data

    def criaData(self):
        aux = dt.datetime.now()
        return aux
