ingresso = 5.0
qtd = 120
lucromax = 0
qtdmax = 0
ingressomax = 0

while ingresso >= 1.5:
    lucro = qtd * ingresso - 200
    print(f'preço ingresso = {ingresso}, quantidade = {qtd}, lucro = {lucro}')
    if lucro >= lucromax:
        lucromax = lucro
        qtdmax = qtd
        ingressomax = ingresso
    ingresso -= 0.5
    qtd += 26

print(f'Lucro máximo = {lucromax:.2f}')
print(f'Preço do ingresso = {ingressomax:.2f}')
print(f'Quantidade vendida = {qtdmax}')
