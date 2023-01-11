from conta import Conta
from cliente import Cliente

class Banco:

    __slots__ = ['contas', 'login']

    def __init__(self):
        self.contas = {}
        self.login = {}

    def addConta(self, nome, sobrenome, cpf, user, senha, num):
        p = Cliente(nome, sobrenome, cpf)
        if cpf in self.contas.keys():
            return False
        self.contas[cpf] = Conta(num, p, 0.0, 1000.0, user, senha)

        if user in self.login.keys():
            return False
        self.login[user] = senha
        return True

    def busca(self, pesquisa):
        if pesquisa in self.contas.keys():
            return self.contas[pesquisa]
        return False

    def verificarLogin(self, usuario, senha):
        for chave, valor in self.login.items():
            if usuario == chave and valor == senha:
                for cpf in self.contas.keys():
                    if self.contas[cpf].usuario == usuario:
                        return True, cpf
        return False

    def verificarNum(self, num):
        for cpf in self.contas.keys():
            if num == self.contas[cpf].numero:
                return True, cpf
        return False