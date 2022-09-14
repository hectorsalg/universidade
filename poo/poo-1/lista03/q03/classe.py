class Elevador:
    
    def __init__(self, andarAtual, totalAndares, capacidade, qtdPessoas):
        self._andarAtual = andarAtual
        self._totalAndares = totalAndares
        self._capacidade = capacidade
        self._qtdPessoas = qtdPessoas

    @property
    def andarAtual(self):
        return self._andarAtual
    
    @andarAtual.setter
    def andarAtual(self, andarAtual):
        self._andarAtual = andarAtual

    @property
    def totalAndares(self):
        return self._totalAndares
    
    @totalAndares.setter
    def totalAndares(self, totalAndares):
        self._totalAndares = totalAndares
    
    @property
    def capacidade(self):
        return self._capacidade
    
    @capacidade.setter
    def capacidade(self, capacidade):
        self._capacidade = capacidade

    @property
    def qtdPessoas(self):
        return self._qtdPessoas
    
    @qtdPessoas.setter
    def qtdPessoas(self, qtdPessoas):
        self._qtdPessoas = qtdPessoas

    def inicializa(self, capacidade, totalAndares):
        self.andarAtual = 0
        self.qtdPessoas = 0
        self.totalAndares = totalAndares
        self.capacidade = capacidade
    
    def entra(self):
        if self.capacidade > self.qtdPessoas:
            self.qtdPessoas += 1
            print('Entrou uma pessoa no elevador')
            print('\n')
        else:
            print('Elevador lotado!')
            print('\n')
    
    def sai(self):
        if self.qtdPessoas > 0:
            self.qtdPessoas -= 1
            print('Saiu uma pessoa no elevador')
            print('\n')
        else:
            print('Elevador vazio!')
            print('\n')

    def sobe(self):
        if self.andarAtual < self.totalAndares:
            self.andarAtual += 1
            print('O elevador subiu um andar')
            print('\n')
        else:
            print('Impossível subir, estamos no último andar!')
            print('\n')
    
    def desce(self):
        if self.andarAtual > 0:
            self.andarAtual -= 1
            print('O elevador desceu um andar')
            print('\n')
        else:
            print('Impossível descer, estamos no térreo!')
            print('\n')
