class Televisao:
    def __init__(self, canal = 1, volume = 5):
        self.canal =  canal
        self.volume = volume
class ControleRemoto:
    def __init__(self):
        self.televisao = Televisao()

    def aumentar(self):
        self.televisao.volume += 1
        print('Volume aumentou!')
        print('\n')
    
    def diminuir(self):
        if self.televisao.volume > 0:
            self.televisao.volume -= 1
            print('Volume diminuiu!')
            print('\n')
        else:
            print('Impossível diminuir, 0 de volume!')
            print('\n')

    def passarCanal(self):
        self.televisao.canal += 1
        print('Passou de canal!')
        print('\n')

    def voltarCanal(self):
        self.televisao.canal -= 1
        print('Volto o canal!')
        print('\n')
    
    def trocarCanal(self, canal):
        self.televisao.canal = canal
        print('Canal trocado!')
        print('\n')

    def consultar(self):
        print(f'Volume: {self.televisao.volume}')
        print(f'Canal: {self.televisao.canal}')
        print('\n')