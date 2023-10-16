from classes.conta import Conta
from classes.cliente import Cliente


def main():
    cliente1 = Cliente('Hector', 'Salgueiros', '111.111.111-11')
    minha_conta = Conta('123-4', cliente1, 120.0, 1000.0)

    cliente2 = Cliente('Lizzandro', 'Wel', '222.222.222-22')
    conta_dele = Conta('123-5', cliente2, 0, 1000.0)

    minha_conta.deposita(20)
    minha_conta.transfere_para(conta_dele, 20)
    minha_conta.saca(20)
    minha_conta.extrato()

    print('')
    minha_conta.historico.imprime()
    conta_dele.historico.imprime()

    print(minha_conta.getTotalContas())
    print(conta_dele.getTotalContas())
    print(Conta.getTotalContas())


main()
