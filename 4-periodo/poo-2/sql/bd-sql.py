import mysql.connector as mysql

conexao = mysql.connect(host='localhost', db='pooii', user='root', passwd='$algueiroS20')
cursor = conexao.cursor()

sql = """CREATE TABLE IF NOT EXISTS usuarios (id integer AUTO_INCREMENT PRIMARY KEY, nome text NOT NULL, email text NOT NULL);"""

nome = "hector"
email = "hector@email.com"

cursor.execute(sql)
for i in range(5):
    cursor.execute('INSERT INTO usuarios (nome, email) VALUES (%s, %s)', (nome, email))

cursor.execute('SELECT * from usuarios')

for c in cursor:
    print(c)

conexao.commit()
conexao.close()