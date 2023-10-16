import sys
from PyQt5 import QtWidgets
from PyQt5.QtWidgets import QMessageBox, QMainWindow, QApplication

from telaInicial import TelaInicial
from telaCadastro import TelaCadastro
from telaBusca import TelaBusca
from cadastro import Cadastro
from pessoa import Pessoa

class Ui_Main(QtWidgets.QWidget):
    def setupUi(self, Main):
        Main.setObjectName('Main')
        Main.resize(640,480)

        self.QtStack = QtWidgets.QStackedLayout()

        self.stack0 = QtWidgets.QMainWindow()
        self.stack1 = QtWidgets.QMainWindow()
        self.stack2 = QtWidgets.QMainWindow()

        self.telaInicial = TelaInicial()
        self.telaInicial.setupUi(self.stack0)

        self.telaCadastro = TelaCadastro()
        self.telaCadastro.setupUi(self.stack1)
        
        self.telaBusca = TelaBusca()
        self.telaBusca.setupUi(self.stack2)

        self.QtStack.addWidget(self.stack0)
        self.QtStack.addWidget(self.stack1)
        self.QtStack.addWidget(self.stack2)

class Main(QMainWindow, Ui_Main):
    def __init__(self):
        super(Main, self).__init__(None)
        self.setupUi(self)

        self.cad = Cadastro()
        self.telaInicial.btnCadastrar.clicked.connect(self.abrirCadastro)
        self.telaInicial.btnBuscar.clicked.connect(self.abrirBusca)
        self.telaInicial.btnSair.clicked.connect(self.fecharPrograma)

        self.telaCadastro.btnCadastrar.clicked.connect(self.cadastrar)
        self.telaCadastro.btnSair.clicked.connect(self.voltar)

        self.telaBusca.btnBuscar.clicked.connect(self.buscar)
        self.telaBusca.btnVoltar.clicked.connect(self.voltar)

    @staticmethod
    def fecharPrograma():
        sys.exit(app.exec_())

    def voltar(self):
        self.QtStack.setCurrentIndex(0)

    def abrirCadastro(self):
        self.QtStack.setCurrentIndex(1)

    def abrirBusca(self):
        self.QtStack.setCurrentIndex(2)

    def cadastrar(self):
        nome = self.telaCadastro.lineEditNome.text()
        endereco = self.telaCadastro.lineEditEndereco.text()
        cpf = self.telaCadastro.lineEditCPF.text()
        nascimento = self.telaCadastro.lineEditNascimento.text()
        if not(nome == '' or endereco == '' or cpf == '' or nascimento == ''):
            p = Pessoa(nome, endereco, cpf, nascimento)
            if (self.cad.addPessoa(p)):
                self.telaCadastro.lineEditNome.setText('')
                self.telaCadastro.lineEditEndereco.setText('')
                self.telaCadastro.lineEditCPF.setText('')
                self.telaCadastro.lineEditNascimento.setText('')
                QMessageBox.information(None, 'Cadastro', 'Cadastro realizado com sucesso.')
            else:
                QMessageBox.information(None, 'Cadastro', 'O CPF já consta no banco de dados!')
        else:
            QMessageBox.information(None, 'Cadastro', 'Todos os dados devem estar preenchidos!')

    def buscar(self):
        cpf = self.telaBusca.lineEditCPF.text()
        if cpf == '':
            QMessageBox.information(None, 'Busca', 'O espaço do CPF deve ser preenchido!')
        else:
            if (self.cad.buscaPessoa(cpf) != None):
                self.telaBusca.lineEditNome.setText(self.cad.buscaPessoa(cpf).nome)
                self.telaBusca.lineEditEndereco.setText(self.cad.buscaPessoa(cpf).endereco)
                self.telaBusca.lineEditNascimento.setText(self.cad.buscaPessoa(cpf).nascimento)
            else:
                QMessageBox.information(None, 'Busca', 'CPF não cadastrado na base de dados!')

if __name__ == '__main__':
    app = QtWidgets.QApplication(sys.argv)
    show_main = Main()
    sys.exit(app.exec_())