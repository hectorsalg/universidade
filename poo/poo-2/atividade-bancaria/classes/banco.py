class Banco:

    contas = []

    __slots__ = ['Banco']

    def __init__(self, conta):
        Banco.contas.append(conta)
