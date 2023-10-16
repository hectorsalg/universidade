boletim = {}
qtd = int(input('Digite a quantidade de alunos: '))

for i in range(0, qtd):
    nome = input('Digite o nome: ')
    nota1 = float(input('Digite a primeira nota: '))
    nota2 = float(input('Digite a segunda nota: '))
    boletim[nome] = [nota1, nota2]

def media(aluno):
    n = 0
    aux = 0
    for i in aluno:
        aux += i
        n += 1
    media = aux/n
    return media

aluno_media = input('Digite o nome do aluno: ')
flag = False

for i in boletim:
    if i == aluno_media:
        flag = True
        print(media(boletim[i]))
if flag == False:
    print('Nenhum aluno cadastrado!')