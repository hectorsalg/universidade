from matplotlib import pyplot as plt
from skimage.io import imread
from datetime import datetime


class Fotografia:

    __slots__ = ['_foto', '_fotografo', '_data', '_proprietario']

    _totalFotos = 0

    @staticmethod
    def getTotalFotos():
        return Fotografia._totalFotos

    def __init__(self, foto, fotografo, proprietario):
        self._foto = imread(foto)
        self._fotografo = fotografo
        self._data = datetime.now()
        self._proprietario = proprietario
        Fotografia._totalFotos += 1

    # get and set foto
    @property
    def foto(self):
        return self._foto

    @foto.setter
    def foto(self, foto):
        self._foto = foto

    # get and set fotografia
    @property
    def fotografia(self):
        return self._fotografia

    @fotografia.setter
    def fotografia(self, fotografia):
        self._fotografia = fotografia

    # get and set data
    @property
    def data(self):
        return self._data

    @data.setter
    def data(self, data):
        self._data = data

    # get and set proprietario
    @property
    def proprietario(self):
        return self._proprietario

    @proprietario.setter
    def proprietario(self, proprietario):
        self._proprietario = proprietario

    def detailsPhoto(self):
        print(self._foto.shape)
        print(self._fotografo.nome)
        print(self._proprietario)
        print(self._data)

    def showPhoto(self):
        plt.imshow(self._foto)
        plt.show()
