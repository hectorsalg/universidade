class cadastro:

    def __init__(self, nome, cpf, dt_nasc):
        self._nome = nome
        self._cpf = cpf
        self._dt_nasc = dt_nasc

class criaConta:

    def __init__(self, numero, saldo, hist_trans):
        self._numero = numero
        self._saldo = saldo
        self._hist_trans = hist_trans

class funcionario(cadastro):

    def __init__(self, nome, cpf, dt_nasc, salario):
        super().__init__(nome, cpf, dt_nasc)
        self._salario = salario

class cliente(cadastro):

    def __init__(self, nome, cpf, dt_nasc, profissao):
        super().__init__(nome, cpf, dt_nasc)
        self._profissao = profissao

class contaCorrente(criaConta):

    def __init__(self, numero, saldo, hist_trans):
        super().__init__(numero, saldo, hist_trans)

class contaPoupanca(criaConta):

    def __init__(self, numero, saldo, hist_trans):
        super().__init__(numero, saldo, hist_trans)

class seguroDeVida:

    def __init__(self, valor_mensal, valor_total):
        self._valor_mensal = valor_mensal
        self._valor_total = valor_total
