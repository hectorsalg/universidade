from classes.fotografo import Fotografo
from classes.fotografia import Fotografia

fotografo1 = Fotografo('Hec', '111.111.111-11', 'Rua minha', '(11)11111-1111')

fotografia1 = Fotografia('https://github.com/hectorsalg.png',
                         fotografo1, fotografo1.nome)

fotografia1.detailsPhoto()
fotografia1.showPhoto()
