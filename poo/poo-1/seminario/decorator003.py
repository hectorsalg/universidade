def criarAdicionador(num1):
    def adicionar(num2):
        return num1 + num2

    return adicionar

add_15 =  criarAdicionador(15)

print(add_15(10))