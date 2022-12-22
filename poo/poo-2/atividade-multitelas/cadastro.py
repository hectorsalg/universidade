class Cadastro:

    __slots__ = ['_listaPessoas']

    def __init__(self):
        self._listaPessoas = []

    def addPessoa(self, pessoa):
        existe = self.buscaPessoa(pessoa.cpf)
        if (existe == None):
            self._listaPessoas.append(pessoa)
            return True
        return False

    def buscaPessoa(self, cpf):
        for lp in self._listaPessoas:
            if (lp.cpf == cpf):
                return lp
        return None
