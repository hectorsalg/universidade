from classes.conta import Conta
from classes.cliente import Cliente
from classes.banco import Banco


def main():

    banco = Banco()

    c1 = Cliente('hec', 'salg', '111.111.111-11')
    c2 = Cliente('jose', 'rod', '222.222.222-22')
    conta1 = Conta('123-4', c1, saldo=110.0, limite=1000.0)
    banco.addConta(conta1)
    conta2 = Conta('234-5', c2, saldo=0.0, limite=1000.0)
    banco.addConta(conta2)

    conta1.transfere_para(conta2, 200)
    print(conta1.saldo)
    banco.busca('123-4')

main()
