agenda = {}
class Pessoa:
    def __init__(self, nome, idade, altura):
        self.nome = nome
        self.idade = idade
        self.altura = altura
    
    def armazenaPessoa(self):
        pessoas = 0
        for i in agenda:
            pessoas += 1
        if pessoas < 10:
            agenda[self.nome] = [self.idade, self.altura]
        else:
            print('Não foi possível adicionar pessoa a agenda!')
    
    def removePessoa(self, nome):
        flag = False
        for i in agenda:
            if nome == i:
                agenda.pop(nome)
                flag = True
        if flag:
            print('Pessoa removida da agenda!')
        else:
            print('Não foi possível remover conta!')

class Imprimir:

    def __init__(self):
        pass

    def imprimir(self):
        print(agenda)
