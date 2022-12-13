class Banco:

    __slots__ = ['contas']

    def __init__(self):
        self.contas = []

    def addConta(self, conta):
        self.contas.append(conta)

    def busca(self, pesquisa):
        for item in self.contas:
            if (item == pesquisa):
                print(self.contas[item])

