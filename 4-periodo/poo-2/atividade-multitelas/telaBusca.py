# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'telaBusca.ui'
#
# Created by: PyQt5 UI code generator 5.15.7
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class TelaBusca(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(656, 526)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.titulo = QtWidgets.QLabel(self.centralwidget)
        self.titulo.setGeometry(QtCore.QRect(270, 30, 111, 51))
        font = QtGui.QFont()
        font.setPointSize(18)
        font.setBold(True)
        font.setWeight(75)
        self.titulo.setFont(font)
        self.titulo.setObjectName("titulo")
        self.btnBuscar = QtWidgets.QPushButton(self.centralwidget)
        self.btnBuscar.setGeometry(QtCore.QRect(420, 90, 111, 31))
        self.btnBuscar.setObjectName("btnBuscar")
        self.btnVoltar = QtWidgets.QPushButton(self.centralwidget)
        self.btnVoltar.setGeometry(QtCore.QRect(50, 360, 111, 31))
        self.btnVoltar.setObjectName("btnVoltar")
        self.labelNome = QtWidgets.QLabel(self.centralwidget)
        self.labelNome.setGeometry(QtCore.QRect(140, 220, 58, 16))
        font = QtGui.QFont()
        font.setPointSize(14)
        font.setBold(True)
        font.setWeight(75)
        self.labelNome.setFont(font)
        self.labelNome.setObjectName("labelNome")
        self.labelEndereco = QtWidgets.QLabel(self.centralwidget)
        self.labelEndereco.setGeometry(QtCore.QRect(140, 260, 91, 16))
        font = QtGui.QFont()
        font.setPointSize(14)
        font.setBold(True)
        font.setWeight(75)
        self.labelEndereco.setFont(font)
        self.labelEndereco.setObjectName("labelEndereco")
        self.labelCPF = QtWidgets.QLabel(self.centralwidget)
        self.labelCPF.setGeometry(QtCore.QRect(140, 100, 91, 16))
        font = QtGui.QFont()
        font.setPointSize(14)
        font.setBold(True)
        font.setWeight(75)
        self.labelCPF.setFont(font)
        self.labelCPF.setObjectName("labelCPF")
        self.labelNascimento = QtWidgets.QLabel(self.centralwidget)
        self.labelNascimento.setGeometry(QtCore.QRect(140, 300, 111, 16))
        font = QtGui.QFont()
        font.setPointSize(14)
        font.setBold(True)
        font.setWeight(75)
        self.labelNascimento.setFont(font)
        self.labelNascimento.setObjectName("labelNascimento")
        self.lineEditNome = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEditNome.setGeometry(QtCore.QRect(270, 210, 181, 28))
        self.lineEditNome.setObjectName("lineEditNome")
        self.lineEditEndereco = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEditEndereco.setGeometry(QtCore.QRect(270, 250, 181, 28))
        self.lineEditEndereco.setObjectName("lineEditEndereco")
        self.lineEditCPF = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEditCPF.setGeometry(QtCore.QRect(270, 90, 111, 28))
        self.lineEditCPF.setObjectName("lineEditCPF")
        self.lineEditNascimento = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEditNascimento.setGeometry(QtCore.QRect(270, 290, 111, 28))
        self.lineEditNascimento.setObjectName("lineEditNascimento")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 656, 22))
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
        self.titulo.setText(_translate("MainWindow", "Cadastro"))
        self.btnBuscar.setText(_translate("MainWindow", "Buscar"))
        self.btnVoltar.setText(_translate("MainWindow", "Voltar"))
        self.labelNome.setText(_translate("MainWindow", "Nome"))
        self.labelEndereco.setText(_translate("MainWindow", "Endereço"))
        self.labelCPF.setText(_translate("MainWindow", "CPF"))
        self.labelNascimento.setText(_translate("MainWindow", "Nascimento"))
