import mysql.connector as mysql

conexao = mysql.connect(host='localhost', db='cript', user='root', passwd='$algueiroS20')
cursor = conexao.cursor()

sql = """CREATE TABLE IF NOT EXISTS usuarios (id integer AUTO_INCREMENT PRIMARY KEY, nome text NOT NULL, email text NOT NULL, senha text NOT NULL);"""

nome = "hector"
senha = "senhasenha"
email = "hector@email.com"

cursor.execute(sql)
#for i in range(5):
cursor.execute('INSERT INTO usuarios (nome, email) VALUES (%s, %s, MD5(%s))', (nome, email, senha))

# cursor.execute('SELECT * from usuarios')
cursor.execute('SELECT * from usuarios WHERE nome = %s AND senha = MD5(%s)', (nome, senha))

for c in cursor:
    print(c)

conexao.commit()
conexao.close()