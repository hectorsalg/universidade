class Cadastro:

    __slots__ = ['_listaPessoas']

    def __init__(self):
        self._listaPessoas = {}

    def addPessoa(self, pessoa):
        self._listaPessoas[pessoa.cpf] = [pessoa]

    def buscaPessoa(self, cpf):
        for cpfSource in self._listaPessoas:
            if (cpfSource == cpf):
                return True
        return False
