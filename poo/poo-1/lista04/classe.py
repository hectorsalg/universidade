class Cadastro:

    def __init__(self, nome, cpf, dt_nasc):
        self._nome = nome
        self._cpf = cpf
        self._dt_nasc = dt_nasc

class CriaConta:

    def __init__(self, numero, saldo, hist_trans):
        self._numero = numero
        self._saldo = saldo
        self._hist_trans = hist_trans

class Funcionario(Cadastro):

    def __init__(self, nome, cpf, dt_nasc, salario):
        super().__init__(nome, cpf, dt_nasc)
        self._salario = salario

class Cliente(Cadastro):

    def __init__(self, nome, cpf, dt_nasc, profissao):
        super().__init__(nome, cpf, dt_nasc)
        self._profissao = profissao
        self._total_corrente = 0
        self._total_poupanca = 0

    def contaCorrente(self, numero, saldo, hist_trans):
        if self._total_corrente == 0:
            self._numero_corrente = numero
            self._saldo_corrente = saldo
            self._hist_trans_corrente = hist_trans
            self._total_corrente += 1
            return True
        else:
            print('Não foi possível criar conta corrente, o usuário já possui!')
            return False

    def contaPoupanca(self, numero, saldo, hist_trans):
        if self._total_poupanca == 0:
            self._numero_poupanca = numero
            self._saldo_poupanca = saldo
            self._hist_trans_poupanca = hist_trans
            self._total_poupanca += 1
            return True
        else:
            print('Não foi possível criar conta poupança, o usuário já possui!')
            return False
    
    def sacar(self, valor):
        escolha = input('Digite a conta que deseja sacar: ')
        if escolha == 'corrente':
            if self._saldo_corrente - valor >= 0:
                self._saldo_corrente -= valor
                return True
            else:
                print('Não foi possível realizar saque!')
                return False
        elif escolha == 'poupanca':
            if self._saldo_poupanca - valor >= 0:
                self._saldo_poupanca -= valor
                return True
            else:
                print('Não foi possível realizar saque!')
                return False
    
    def depositar(self, valor):
        escolha = input('Digite a conta que deseja depositar: ')
        if escolha == 'corrente':
            self._saldo_corrente += valor
            return True
        elif escolha == 'poupanca':
            self._saldo_poupanca += valor
            return True
    
    def transferir(self, cliente, valor):
        escolha = input('Digite a conta que deseja transferir: ')
        if escolha == 'corrente':
            if self._saldo_corrente - valor >= 0:
                self._saldo_corrente -= valor
                cliente._saldo_corrente += valor
                return True
            else:
                print('Não foi possível realizar transferência!')
                return False

        elif escolha == 'poupanca':
            if self._saldo_poupanca - valor >= 0:
                self._saldo_poupanca -= valor
                cliente._saldo_poupanca += valor
                return True
            else:
                print('Não foi possível realizar transferência!')
                return False

    def SeguroDeVida(self, valor_mensal, valor_total):
        self._valor_mensal = valor_mensal
        self._valor_total = valor_total
