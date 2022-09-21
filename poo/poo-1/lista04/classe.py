from datetime import datetime

banco = {}
contas = [0]
cliente_contas = []
hist_tributo = []

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
        contas[0] += 0
        banco['Quantidade de Bancos'] = contas
        banco[self._nome] = [self._total_corrente + self._total_poupanca, self._total_seguros]
        self._hist_trans = []
        self._count_tributo = 0
            
    def contaCorrente(self, numero, saldo, hist_trans = datetime.now()):
        if self._total_corrente == 0:
            self._numero_corrente = numero
            self._saldo_corrente = saldo
            self._hist_trans.append(f'Conta Corrente criada: {hist_trans}')
            self._total_corrente += 1
            cliente_contas.append(self)
            contas[0] += 1
            banco['Quantidade de Bancos'] = contas
            banco[self._nome] = [f'Total de contas: {self._total_corrente + self._total_poupanca}', f' Total de seguros: {self._total_seguros}']
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
            contas[0] += 1
            banco['Quantidade de Bancos'] = contas
            banco[self._nome] = [f'Total de contas: {self._total_corrente + self._total_poupanca}', f' Total de seguros: {self._total_seguros}']
            return True
        else:
            print('Não foi possível criar conta poupança, o usuário já possui!')
            return False
    
    def tributacao(self):
        self._tributo = 0
        if self._total_corrente == 0:
            self._saldo_corrente = 0
        if self._total_seguros == 0:
            self._valor_mensal = 0
        self._tributo += 10 + (0.01 * self._saldo_corrente) + (0.02 * self._valor_mensal)
        self._count_tributo += 1
        hist_tributo.append(f'{self._count_tributo} tributação = {self._tributo}')
        if self._count_tributo > 1:
            print(hist_tributo)

    def sacar(self, valor):
        if self._total_corrente == 0 and self._total_poupanca == 0:
            print('Impossível sacar, nenhuma conta existente!')
        elif self._total_corrente == 1 and self._total_poupanca == 0:
            if self._saldo_corrente - valor >= 0:
                self._saldo_corrente -= valor
                self._hist_trans.append(f'- {valor} : {datetime.now()} na conta corrente')
                return True
            else:
                print('Não foi possível realizar saque!')
                return False
        elif self._total_corrente == 0 and self._total_poupanca == 1:
            if self._saldo_poupanca - valor >= 0:
                self._saldo_poupanca -= valor
                self._hist_trans.append(f'- {valor} : {datetime.now()} na conta poupança')
                return True
            else:
                print('Não foi possível realizar saque!')
                return False
        else:
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
        if self._total_corrente == 0 and self._total_poupanca == 0:
            print('Impossível depositar, nenhuma conta existente!')
        elif self._total_corrente == 1 and self._total_poupanca == 0:
            self._saldo_corrente += valor
            self._hist_trans.append(f'+ {valor} : {datetime.now()} na conta corrente')
            return True
        elif self._total_corrente == 0 and self._total_poupanca == 1:
            self._saldo_poupanca += valor
            self._hist_trans.append(f'+ {valor} : {datetime.now()} na conta poupança')
            return True
        else:
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
        if self._total_corrente == 0 and self._total_poupanca == 0:
            print('Impossível depositar, nenhuma conta existente!')
        elif self._total_corrente == 1 and self._total_poupanca == 0:
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
        elif self._total_corrente == 0 and self._total_poupanca == 1:
            if self._saldo_poupanca - valor >= 0:
                self._saldo_poupanca -= valor
                self._hist_trans.append(f'- {valor} : {datetime.now()} na conta poupança')
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
        else:
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
        banco[self._nome] = [f'Total de contas: {self._total_corrente + self._total_poupanca}', f' Total de seguros: {self._total_seguros}']
    
    def historico(self):
        print(self._hist_trans)
        return True

class Banco:

    def __init__(self):
        pass

    def informacoes(self):
        print(banco)
        return True