class Fotografo:

    __slots__ = ['_nome', '_cpf', '_endereco', '_telefone']

    def __init__(self, nome, cpf, endereco, telefone):
        self._nome = nome
        self._cpf = cpf
        self._endereco = endereco
        self._telefone = telefone

    # get and set nome
    @property
    def nome(self):
        return self._nome

    @nome.setter
    def nome(self, nome):
        self._nome = nome

    # get and set cpf
    @property
    def cpf(self):
        return self._cpf

    @cpf.setter
    def cpf(self, cpf):
        self._cpf = cpf

    # get and set endereco
    @property
    def endereco(self):
        return self._endereco

    @endereco.setter
    def endereco(self, endereco):
        self._endereco = endereco

    # get and set telefone
    @property
    def telefone(self):
        return self._telefone

    @telefone.setter
    def telefone(self, telefone):
        self._telefone = telefone
