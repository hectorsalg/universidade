from datetime import datetime

class Pessoa:

    def __init__(self, nome, dia, mes, ano, altura):
        self._nome = nome
        self._dia = dia
        self._mes = mes
        self._ano = ano
        self._altura = altura

    @property
    def nome(self):
        return self._nome
    
    @nome.setter
    def nome(self, nome):
        self._nome = nome
    
    @property
    def dia(self):
        return self._dia
    
    @dia.setter
    def dia(self, dia):
        self._dia = dia
    
    @property
    def mes(self):
        return self._mes
    
    @mes.setter
    def mes(self, mes):
        self._mes = mes

    @property
    def ano(self):
        return self._ano
    
    @ano.setter
    def ano(self, ano):
        self._dt = ano
    
    @property
    def altura(self):
        return self._altura
    
    @altura.setter
    def altura(self, altura):
        self._altura = altura

    def imprimir(self):
        print(f'{self.nome}')
        print(f'{self.dt}')
        print(f'{self.altura}')

    def calcIdade(self):
        hoje = datetime.today()
        idade = hoje.year - self.ano - ((hoje.month, hoje.day) < (self.mes, self.dia))

        return idade