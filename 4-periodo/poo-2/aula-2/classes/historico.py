import datetime as dt


class Historico:
    def __init__(self):
        self.data_abertura = dt.datetime.now().strftime("%d/%m/%Y %H:%M:%S")
        self.transacoes = []

    def imprime(self):
        print(f'Data de abertura: {self.data_abertura}')
        print('Transações: ')
        for t in self.transacoes:
            print('-', t)

    def criaData(self):
        aux = dt.datetime.now()
        return aux
