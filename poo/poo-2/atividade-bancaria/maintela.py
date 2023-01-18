import sys
import random
from PyQt5 import QtWidgets
from PyQt5.QtWidgets import QMessageBox, QMainWindow, QApplication

from telainicial import TelaInicial
from telaconta import TelaConta
from telacadastro import TelaCadastro
from telaextrato import TelaExtrato
from teladeposito import TelaDeposito
from telasacar import TelaSacar
from telatransferir import TelaTransferir

from banco import Banco
from cliente import Cliente
from conta import Conta

class Ui_Main(QtWidgets.QWidget):
    def setupUi(self, Main):
        Main.setObjectName('Main')
        Main.resize(640,480)

        self.QtStack = QtWidgets.QStackedLayout()

        self.stack0 = QtWidgets.QMainWindow()
        self.stack1 = QtWidgets.QMainWindow()
        self.stack2 = QtWidgets.QMainWindow()
        self.stack3 = QtWidgets.QMainWindow()
        self.stack4 = QtWidgets.QMainWindow()
        self.stack5 = QtWidgets.QMainWindow()
        self.stack6 = QtWidgets.QMainWindow()

        self.telaInicial = TelaInicial()
        self.telaInicial.setupUi(self.stack0)

        self.telaConta = TelaConta()
        self.telaConta.setupUi(self.stack1)

        self.telaCadastro = TelaCadastro()
        self.telaCadastro.setupUi(self.stack2)
        
        self.telaDeposito = TelaDeposito()
        self.telaDeposito.setupUi(self.stack3)

        self.telaSacar = TelaSacar()
        self.telaSacar.setupUi(self.stack4)

        self.telaTransferir = TelaTransferir()
        self.telaTransferir.setupUi(self.stack5)

        self.telaExtrato = TelaExtrato()
        self.telaExtrato.setupUi(self.stack6)

        self.QtStack.addWidget(self.stack0)
        self.QtStack.addWidget(self.stack1)
        self.QtStack.addWidget(self.stack2)
        self.QtStack.addWidget(self.stack3)
        self.QtStack.addWidget(self.stack4)
        self.QtStack.addWidget(self.stack5)
        self.QtStack.addWidget(self.stack6)

class Main(QMainWindow, Ui_Main):
    def __init__(self):
        super(Main, self).__init__(None)
        self.setupUi(self)

        self.banco = Banco()

        self.telaInicial.btnCadastrar.clicked.connect(self.entrarCadastro)
        self.telaInicial.btnLogin.clicked.connect(self.login)
        self.telaInicial.btnSair.clicked.connect(sys.exit)

        self.telaCadastro.btnCadastrar.clicked.connect(self.cadastrar)
        self.telaCadastro.btnVoltar.clicked.connect(self.voltarInicial)

        self.telaConta.btnDepositar.clicked.connect(self.entrarDepositar)
        self.telaConta.btnSacar.clicked.connect(self.entrarSacar)
        self.telaConta.btnTransferir.clicked.connect(self.entrarTransferir)
        self.telaConta.btnExtrato.clicked.connect(self.entrarExtrato)
        self.telaConta.btnVoltar.clicked.connect(self.voltarInicial)
        self.telaConta.btnSair.clicked.connect(sys.exit)

        self.telaDeposito.btnDepositar.clicked.connect(self.depositar)
        self.telaDeposito.btnVoltar.clicked.connect(self.entrarConta)
        self.telaDeposito.btnSair.clicked.connect(sys.exit)

        self.telaSacar.btnSacar.clicked.connect(self.sacar)
        self.telaSacar.btnVoltar.clicked.connect(self.entrarConta)
        self.telaSacar.btnSair.clicked.connect(sys.exit)

        self.telaTransferir.btnTransferir.clicked.connect(self.transferir)
        self.telaTransferir.btnVoltar.clicked.connect(self.entrarConta)
        self.telaTransferir.btnSair.clicked.connect(sys.exit)

        self.telaExtrato.btnVoltar.clicked.connect(self.entrarConta)
        self.telaExtrato.btnSair.clicked.connect(sys.exit)

    def voltarInicial(self):
        self.QtStack.setCurrentIndex(0)

    def login(self):
        user = self.telaInicial.lineEditUser.text()
        senha = self.telaInicial.lineEditSenha.text()
        flag = self.banco.verificarLogin(user, senha)
        if self.banco.verificarLogin(user, senha):
            self.QtStack.setCurrentIndex(1)
            self.conta = flag[1]
            self.telaInicial.lineEditUser.setText('')
            self.telaInicial.lineEditSenha.setText('')
        else:
            QMessageBox.information(None, 'Login', 'Usuário ou senha incorreto.')

    def entrarConta(self):
        self.QtStack.setCurrentIndex(1)
        self.telaDeposito.lineEditDepositar.setText('')
        self.telaTransferir.lineEditTransferir.setText('')
        self.telaTransferir.lineEditConta.setText('')
        self.telaSacar.lineEditSacar.setText('')

    def entrarCadastro(self):
        self.QtStack.setCurrentIndex(2)
        self.telaInicial.lineEditUser.setText('')
        self.telaInicial.lineEditSenha.setText('')

    def entrarDepositar(self):
        self.QtStack.setCurrentIndex(3)

    def entrarSacar(self):
        self.QtStack.setCurrentIndex(4)

    def entrarTransferir(self):
        self.QtStack.setCurrentIndex(5)

    def entrarExtrato(self):
        self.QtStack.setCurrentIndex(6)
        self.telaExtrato.labelExtrato.setText(
            f'Saldo: {self.banco.contas[self.conta].saldo}\nLimite: {self.banco.contas[self.conta].limite}\nConta: {self.banco.contas[self.conta].numero}\n{self.banco.contas[self.conta].historico.imprime()}')

    def cadastrar(self):
        nome = self.telaCadastro.lineEditNome.text()
        sobrenome = self.telaCadastro.lineEditSobrenome.text()
        cpf = self.telaCadastro.lineEditCPF.text()
        user = self.telaCadastro.lineEditUser.text()
        senha = self.telaCadastro.lineEditSenha.text()
        if not(nome == '' or sobrenome == '' or cpf == '' or user == '' or senha == ''):
            num = random.randint(0, 9999)
            while self.banco.busca(num):
                num = random.randint(0, 9999)
            if (self.banco.addConta(nome, sobrenome, cpf, user, senha, num)):
                print(num)
                self.telaCadastro.lineEditNome.setText('')
                self.telaCadastro.lineEditSobrenome.setText('')
                self.telaCadastro.lineEditCPF.setText('')
                self.telaCadastro.lineEditUser.setText('')
                self.telaCadastro.lineEditSenha.setText('')
                QMessageBox.information(None, 'Cadastro', 'Cadastro realizado com sucesso.')
            else:
                QMessageBox.information(None, 'Cadastro', 'O CPF já consta no banco de dados!')
        else:
            QMessageBox.information(None, 'Cadastro', 'Todos os dados devem estar preenchidos!')
    
    def depositar(self):
        valor = float(self.telaDeposito.lineEditDepositar.text())
        if self.banco.contas[self.conta].deposita(valor):
            self.telaDeposito.lineEditDepositar.setText('')
            QMessageBox.information(None, 'Deposito', 'Deposito realizado com sucesso.')
        else:
            QMessageBox.information(None, 'Deposito', 'Limite insuficiente.')    

    def sacar(self):
        valor = float(self.telaSacar.lineEditSacar.text())
        if self.banco.contas[self.conta].deposita(valor):
            self.telaSacar.lineEditSacar.setText('')
            QMessageBox.information(None, 'Saque', 'Saque realizado com sucesso.')
        else:
            QMessageBox.information(None, 'Saque', 'Saldo insuficiente.')  
    
    def transferir(self):
        valor = float(self.telaTransferir.lineEditTransferir.text())
        destino = int(self.telaTransferir.lineEditConta.text())
        flag = self.banco.verificarNum(destino)
        if self.banco.verificarNum(destino):
            self.banco.contas[self.conta].transfere_para(self.banco.contas[flag[1]], valor)
            self.telaTransferir.lineEditTransferir.setText('')
            self.telaTransferir.lineEditConta.setText('')
            QMessageBox.information(None, 'Transferir', 'Transferências realizada com sucesso.')
        else:
            QMessageBox.information(None, 'Transferir', 'Saldo insuficiente ou conta inexistente.')

if __name__ == '__main__':
    app = QtWidgets.QApplication(sys.argv)
    show_main = Main()
    sys.exit(app.exec_())