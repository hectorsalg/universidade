import random

class Perceptron:
    def __init__(self, num_inputs, learning_rate=0.5, threshold=0.5):
        """
        Inicializa o Perceptron.
        :param num_inputs: Número de características de entrada (excluindo o bias).
        :param learning_rate: A constante 'c' na fórmula de ajuste de peso.
        :param threshold: O limiar de ativação para o neurônio.
        """
        self.weights = [0.0] * num_inputs  # Inicializa os pesos com 0
        self.bias_weight = 0.0  # Peso do bias (frequentemente tratado como w0 com x0=1)
        self.learning_rate = learning_rate
        self.threshold = threshold # O limiar 't' para ativação

    def activate(self, s):
        """
        Aplica a função de ativação degrau.
        :param s: A soma das entradas ponderadas (entrada líquida).
        :return: 1 se s > limiar, 0 caso contrário.
        """
        if s > self.threshold:
            return 1
        else:
            return 0

    def predict(self, inputs):
        """
        Calcula a saída do perceptron para um dado conjunto de entradas.
        :param inputs: Uma lista de valores de entrada.
        :return: A saída prevista (0 ou 1).
        """
        # Calcula a soma ponderada das entradas (S = sum(wi * Xi))
        # Incluindo o bias como entrada x0=1 com peso w0 (bias_weight)
        weighted_sum = self.bias_weight
        for i in range(len(inputs)):
            weighted_sum += self.weights[i] * inputs[i]
        return self.activate(weighted_sum)

    def train(self, training_data, num_epochs=100):
        """
        Treina o perceptron usando os dados de treinamento fornecidos.
        :param training_data: Uma lista de tuplas, onde cada tupla é
                              (entradas, saída_desejada).
        :param num_epochs: O número de vezes para iterar por todo o
                           conjunto de dados de treinamento. Cada iteração é uma época.
        """
        print(f"Pesos Iniciais: {self.weights}, Peso do Bias: {self.bias_weight}")
        for epoch in range(num_epochs):
            total_error = 0
            # É recomendado randomizar a ordem das amostras em cada época
            random.shuffle(training_data)
            
            for inputs, desired_output in training_data:
                # Passo 1: Calcular a saída (y)
                predicted_output = self.predict(inputs)

                # Passo 2: Calcular o erro (E = saida_desejada - saida_obtida)
                error = desired_output - predicted_output
                total_error += abs(error) # Acumular erro absoluto

                # Passo 3: Ajustar os pesos se houver um erro
                if error != 0:
                    # Calcular o fator de correção (F = c * E * x)
                    # Novo peso = peso antigo + F

                    # Atualizar o peso do bias
                    # Para o bias, a entrada x é sempre 1 (x0 no exemplo)
                    self.bias_weight += self.learning_rate * error * 1 # x0 é 1 para o bias

                    # Atualizar os pesos das entradas
                    for i in range(len(inputs)):
                        correction = self.learning_rate * error * inputs[i]
                        self.weights[i] += correction
            
            # Imprimir o status a cada algumas épocas ou com base no total_error
            if epoch % 10 == 0:
                print(f"Época {epoch+1}/{num_epochs}, Erro Total: {total_error}")
                print(f"Pesos Atuais: {self.weights}, Peso do Bias: {self.bias_weight}")

            # Critério de parada: se o erro for aceitável
            if total_error == 0:
                print(f"Treinamento convergiu após {epoch+1} épocas.")
                break
        print(f"Pesos Finais: {self.weights}, Peso do Bias: {self.bias_weight}")


# Exemplo de Uso: Implementando a porta lógica AND
# Tabela verdade para AND:
# Entrada1 | Entrada2 | Saída
# ---------|----------|-------
# 0        | 0        | 0     
# 0        | 1        | 0     
# 1        | 0        | 0     
# 1        | 1        | 1     

training_data_and = [
    ([0, 0], 0),
    ([0, 1], 0),
    ([1, 0], 0),
    ([1, 1], 1)
]

print("Treinando Perceptron para a porta AND:")
perceptron_and = Perceptron(num_inputs=2, learning_rate=0.5, threshold=0.5)
perceptron_and.train(training_data_and, num_epochs=100)

print("\nTestando Perceptron para a porta AND:")
print(f"AND(0, 0) = {perceptron_and.predict([0, 0])}")
print(f"AND(0, 1) = {perceptron_and.predict([0, 1])}")
print(f"AND(1, 0) = {perceptron_and.predict([1, 0])}")
print(f"AND(1, 1) = {perceptron_and.predict([1, 1])}")

# Exemplo de Uso: Implementando a porta lógica OR
# Tabela verdade para OR:
# Entrada1 | Entrada2 | Saída
# ---------|----------|-------
# 0        | 0        | 0
# 0        | 1        | 1
# 1        | 0        | 1
# 1        | 1        | 1

training_data_or = [
    ([0, 0], 0),
    ([0, 1], 1),
    ([1, 0], 1),
    ([1, 1], 1)
]

print("Treinando Perceptron para a porta OR:")
perceptron_or = Perceptron(num_inputs=2, learning_rate=0.5, threshold=0.5)
perceptron_or.train(training_data_or, num_epochs=100)

print("\nTestando Perceptron para a porta OR:")
print(f"OR(0, 0) = {perceptron_or.predict([0, 0])}")
print(f"OR(0, 1) = {perceptron_or.predict([0, 1])}")
print(f"OR(1, 0) = {perceptron_or.predict([1, 0])}")
print(f"OR(1, 1) = {perceptron_or.predict([1, 1])}")

# Exemplo de Uso: Demonstrando o problema XOR com um único perceptron
# Um único perceptron não consegue implementar a função XOR

# Exemplo de Uso: Implementando a porta lógica XOR
# Tabela verdade para XOR:
# Entrada1 | Entrada2 | Saída
# ---------|----------|-------
# 0        | 0        | 0
# 0        | 1        | 1
# 1        | 0        | 1
# 1        | 1        | 0
training_data_xor = [
    ([0, 0], 0),
    ([0, 1], 1),
    ([1, 0], 1),
    ([1, 1], 0)
]

print("\nTreinando Perceptron para a porta XOR (não irá convergir):")
perceptron_xor = Perceptron(num_inputs=2, learning_rate=0.5, threshold=0.5)
perceptron_xor.train(training_data_xor, num_epochs=200) # Épocas aumentadas para mostrar a não-convergência

print("\nTestando Perceptron para a porta XOR:")
print(f"XOR(0, 0) = {perceptron_xor.predict([0, 0])}")
print(f"XOR(0, 1) = {perceptron_xor.predict([0, 1])}")
print(f"XOR(1, 0) = {perceptron_xor.predict([1, 0])}")
print(f"XOR(1, 1) = {perceptron_xor.predict([1, 1])}")