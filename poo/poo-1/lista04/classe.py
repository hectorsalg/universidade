from datetime import datetime

banco = {}
class Cadastro:

    def __init__(self, nome, cpf, dt_nasc):
        self._nome = nome
        self._cpf = cpf
        self._dt_nasc = dt_nasc

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
        self._total_seguros = 0
        self._total_contas = 0
        self._hist_trans = []
            
    def contaCorrente(self, numero, saldo, hist_trans = datetime.now()):
        if self._total_corrente == 0:
            self._numero_corrente = numero
            self._saldo_corrente = saldo
            self._hist_trans.append(f'Conta Corrente criada: {hist_trans}')
            self._total_corrente += 1
            self._total_contas += 1
            banco['Quantidade de Bancos'] = [self._total_contas]
            return True
        else:
            print('Não foi possível criar conta corrente, o usuário já possui!')
            return False

    def contaPoupanca(self, numero, saldo, hist_trans = datetime.now()):
        if self._total_poupanca == 0:
            self._numero_poupanca = numero
            self._saldo_poupanca = saldo
            self._hist_trans.append(f'Conta Poupança criada: {hist_trans}')
            self._total_poupanca += 1
            self._total_contas += 1
            banco['Quantidade de Bancos'] = [self._total_contas]
            return True
        else:
            print('Não foi possível criar conta poupança, o usuário já possui!')
            return False
    
    def sacar(self, valor):
        escolha = input('Digite a conta que deseja sacar: ')
        if escolha == 'corrente':
            if self._saldo_corrente - valor >= 0:
                self._saldo_corrente -= valor
                self._hist_trans.append(f'- {valor} : {datetime.now()} na conta corrente')
                return True
            else:
                print('Não foi possível realizar saque!')
                return False
        elif escolha == 'poupanca' or 'poupança':
            if self._saldo_poupanca - valor >= 0:
                self._saldo_poupanca -= valor
                self._hist_trans.append(f'- {valor} : {datetime.now()} na conta poupança')
                return True
            else:
                print('Não foi possível realizar saque!')
                return False
    
    def depositar(self, valor):
        escolha = input('Digite a conta que deseja depositar: ')
        if escolha == 'corrente':
            self._saldo_corrente += valor
            self._hist_trans.append(f'+ {valor} : {datetime.now()} na conta corrente')
            return True
        elif escolha == 'poupanca' or 'poupança':
            self._saldo_poupanca += valor
            self._hist_trans.append(f'+ {valor} : {datetime.now()} na conta poupança')
            return True
    
    def transferir(self, cliente, valor):
        escolha = input('Digite a conta que deseja transferir: ')
        if escolha == 'corrente':
            if self._saldo_corrente - valor >= 0:
                self._saldo_corrente -= valor
                self._hist_trans.append(f'- {valor} : {datetime.now()} na conta corrente')
                try:
                    cliente._saldo_corrente += valor
                    cliente._hist_trans.append(f'+ {valor} : {datetime.now()} na conta corrente')
                except:
                    cliente._saldo_poupanca += valor
                    cliente._hist_trans.append(f'+ {valor} : {datetime.now()} na conta poupanca')
                return True
            else:
                print('Não foi possível realizar transferência!')
                return False

        elif escolha == 'poupanca' or 'poupança':
            if self._saldo_poupanca - valor >= 0:
                self._saldo_poupanca -= valor
                self._hist_trans.append(f'- {valor} : {datetime.now()} na conta poupança')
                try:
                    cliente._saldo_corrente += valor
                    cliente._hist_trans.append(f'+ {valor} : {datetime.now()} na conta corrente')
                except:
                    cliente._saldo_poupanca += valor
                    cliente._hist_trans.append(f'+ {valor} : {datetime.now()} na conta poupança')
                return True
            else:
                print('Não foi possível realizar transferência!')
                return False

    def seguroDeVida(self, valor_mensal, valor_total):
        self._valor_mensal = valor_mensal
        self._valor_total = valor_total
        self._total_seguros += 1
    
    def historico(self):
        print(self._hist_trans)

class Banco:

    def __init__(self):
        pass

    def informacoes(self):
        print(banco)
        return True