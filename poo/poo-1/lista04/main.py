from datetime import datetime
from classe import *

c = Cliente('mel', '123', '11/03/2001', 'front-end')

c.criarCorrente('123', 0, datetime.now)
