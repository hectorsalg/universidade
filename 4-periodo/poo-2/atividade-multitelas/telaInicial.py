# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'telaInicial.ui'
#
# Created by: PyQt5 UI code generator 5.15.7
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class TelaInicial(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(656, 526)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setGeometry(QtCore.QRect(210, 80, 241, 51))
        font = QtGui.QFont()
        font.setPointSize(18)
        font.setBold(True)
        font.setWeight(75)
        self.label.setFont(font)
        self.label.setObjectName("label")
        self.btnCadastrar = QtWidgets.QPushButton(self.centralwidget)
        self.btnCadastrar.setGeometry(QtCore.QRect(110, 190, 111, 31))
        self.btnCadastrar.setObjectName("btnCadastrar")
        self.btnBuscar = QtWidgets.QPushButton(self.centralwidget)
        self.btnBuscar.setGeometry(QtCore.QRect(450, 190, 111, 31))
        self.btnBuscar.setObjectName("btnBuscar")
        self.btnSair = QtWidgets.QPushButton(self.centralwidget)
        self.btnSair.setGeometry(QtCore.QRect(70, 300, 111, 31))
        self.btnSair.setObjectName("btnSair")
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
        self.label.setText(_translate("MainWindow", "Controle de Estoque"))
        self.btnCadastrar.setText(_translate("MainWindow", "Cadastrar"))
        self.btnBuscar.setText(_translate("MainWindow", "Buscar"))
        self.btnSair.setText(_translate("MainWindow", "Sair"))