from classe import *

b = Banco()
c = Cliente('mel', '123', '11/03/2001', 'front-end')
c2 = Cliente('hec', '321', '18/12/2002', 'back-end')

c.contaCorrente('465', 0.0)
# c.contaCorrente('999', 0.0)
c2.contaCorrente('222', 0.0)
# c2.contaPoupanca('422', 0.0)
c.contaPoupanca('678', 0.0)
c2.seguroDeVida(20, 140)

c2.depositar(10)
c.depositar(20)
c.depositar(40)
c.sacar(15)

c2.tributacao()
c2.depositar(30)
# c2.tributacao()

c.historico()
# c2.historico()
b.informacoes()