class Cadastro:

    __slots__ = ['_listaPessoas']

    def __init__(self):
        self._listaPessoas = {}

    def addPessoa(self, pessoa):
        if not(self.buscaPessoa(pessoa.cpf)):
            self._listaPessoas[pessoa.cpf] = pessoa
            return True
        return False

    def buscaPessoa(self, cpf):
        for cpfSource in self._listaPessoas:
            if (cpfSource == cpf):
                return self._listaPessoas[cpf]
        return None
