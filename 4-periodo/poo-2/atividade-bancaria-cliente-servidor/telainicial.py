# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'telainicial.ui'
#
# Created by: PyQt5 UI code generator 5.15.7
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class TelaInicial(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(900, 600)
        MainWindow.setCursor(QtGui.QCursor(QtCore.Qt.ArrowCursor))
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.labelWelcome = QtWidgets.QLabel(self.centralwidget)
        self.labelWelcome.setGeometry(QtCore.QRect(350, 40, 331, 41))
        font = QtGui.QFont()
        font.setPointSize(14)
        font.setBold(True)
        font.setWeight(75)
        self.labelWelcome.setFont(font)
        self.labelWelcome.setObjectName("labelWelcome")
        self.labelUser = QtWidgets.QLabel(self.centralwidget)
        self.labelUser.setGeometry(QtCore.QRect(350, 90, 61, 41))
        font = QtGui.QFont()
        font.setPointSize(12)
        font.setBold(True)
        font.setWeight(75)
        self.labelUser.setFont(font)
        self.labelUser.setObjectName("labelUser")
        self.labelSenha = QtWidgets.QLabel(self.centralwidget)
        self.labelSenha.setGeometry(QtCore.QRect(350, 170, 61, 41))
        font = QtGui.QFont()
        font.setPointSize(12)
        font.setBold(True)
        font.setWeight(75)
        self.labelSenha.setFont(font)
        self.labelSenha.setObjectName("labelSenha")
        self.lineEditUser = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEditUser.setGeometry(QtCore.QRect(350, 130, 171, 21))
        self.lineEditUser.setObjectName("lineEditUser")
        self.lineEditSenha = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEditSenha.setGeometry(QtCore.QRect(350, 210, 171, 21))
        self.lineEditSenha.setObjectName("lineEditSenha")
        self.btnLogin = QtWidgets.QPushButton(self.centralwidget)
        self.btnLogin.setGeometry(QtCore.QRect(350, 250, 91, 31))
        self.btnLogin.setCursor(QtGui.QCursor(QtCore.Qt.PointingHandCursor))
        self.btnLogin.setObjectName("btnLogin")
        self.btnCadastrar = QtWidgets.QPushButton(self.centralwidget)
        self.btnCadastrar.setGeometry(QtCore.QRect(350, 290, 91, 31))
        self.btnCadastrar.setCursor(QtGui.QCursor(QtCore.Qt.PointingHandCursor))
        self.btnCadastrar.setObjectName("btnCadastrar")
        self.btnSair = QtWidgets.QPushButton(self.centralwidget)
        self.btnSair.setGeometry(QtCore.QRect(40, 450, 91, 31))
        self.btnSair.setCursor(QtGui.QCursor(QtCore.Qt.PointingHandCursor))
        self.btnSair.setObjectName("btnSair")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 652, 21))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.labelWelcome.setText(_translate("MainWindow", "Bem-vindo(a) ao Banco"))
        self.labelUser.setText(_translate("MainWindow", "Usuário"))
        self.labelSenha.setText(_translate("MainWindow", "Senha"))
        self.btnLogin.setText(_translate("MainWindow", "Login"))
        self.btnCadastrar.setText(_translate("MainWindow", "Cadastrar"))
        self.btnSair.setText(_translate("MainWindow", "Sair"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = TelaInicial()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())
