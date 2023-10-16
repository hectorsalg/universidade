class Conta:
    
    def __init__(self, numero, titular, saldo, limite):
        self.numero = numero
        self.titular = titular
        self.saldo = saldo
        self.limite = limite

    def sacar(self, saque):
        self.saldo -= saque
        while self.saldo < 0:
            self.saldo += saque
            print('Valor invalido para saque!')
            saque = float(input('Informe o valor de saque correto: '))
            self.saldo -= saque
        print('Saque realizado com sucesso!')
    
    def deposito(self, deposito):
        self.saldo += deposito
        while (self.saldo > self.limite):
            self.saldo -= deposito
            print('Valor invalido para deposito!')
            deposito = float(input('Informe o valor de deposito correto: '))
            self.saldo += deposito
        print('Deposito realizado com sucesso!')
        
    def extrato(self):
        print('Numero da conta:', self.numero)
        print('Titular da conta:', self.titular)
        print(f'Saldo da conta: {self.saldo:.2f}')
        print(f'Limite da conta: {self.limite:.2f}')
    
c = Conta('123-4', 'hector', 100.00, 1000.00)

c.sacar(120)
c.deposito(1200)
print('\n')
c.extrato()