import pandas as pd
import numpy as np
from sklearn.model_selection import KFold
from sklearn.preprocessing import StandardScaler
from sklearn.impute import SimpleImputer
from sklearn.decomposition import PCA
from sklearn.neural_network import MLPClassifier
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score, roc_auc_score, cohen_kappa_score, confusion_matrix
import matplotlib.pyplot as plt
import seaborn as sns

# Carregar os dados (substitua 'caminho_para_o_arquivo' pelo caminho real do arquivo de dados)
# Especificando o separador decimal e tratamento de vírgulas em números
df = pd.read_csv('global-data-on-sustainable-energy.csv', decimal=',')

# Remover colunas não numéricas que não serão utilizadas para o treinamento do modelo
df_numeric = df.drop(columns=['Entity', 'Year', 'Latitude', 'Longitude'])

# Verificar e tratar valores NaN
if df_numeric.isnull().values.any():
    # Preencher valores NaN com a média
    imputer = SimpleImputer(strategy='mean')
    df_numeric = pd.DataFrame(imputer.fit_transform(
        df_numeric), columns=df_numeric.columns)

# Separar as características e o rótulo
X = df_numeric.drop(
    columns=['Renewable energy share in the total final energy consumption (%)'])
y = df_numeric['Renewable energy share in the total final energy consumption (%)']

# Definir classes para transformar em um problema de classificação
# Exemplo: categorizar em baixa, média e alta participação de energia renovável
# Aqui, você precisa ajustar os limites de acordo com seus dados e objetivos


def categorize_renewable_share(share):
    if share < 30:
        return 'Baixa'
    elif share < 60:
        return 'Média'
    else:
        return 'Alta'


# Aplicar a função de categorização aos rótulos
y_classification = y.apply(categorize_renewable_share)

# Normalização
scaler = StandardScaler()
X_normalized = scaler.fit_transform(X)

# PCA com tratamento de valores NaN
pca = PCA()
X_pca = pca.fit_transform(X_normalized)

# Função para Avaliação do Modelo

def evaluate_model(X, y, n_splits, hidden_layers):
    kf = KFold(n_splits=n_splits, shuffle=True, random_state=42)

    accuracy, precision, recall, f1, auc, kappa = [], [], [], [], [], []
    confusion_matrices = []

    for train_index, test_index in kf.split(X):
        X_train, X_test = X[train_index], X[test_index]
        y_train, y_test = y[train_index], y[test_index]

        mlp = MLPClassifier(hidden_layer_sizes=hidden_layers,
                            max_iter=1000, random_state=42)
        mlp.fit(X_train, y_train)
        y_pred = mlp.predict(X_test)
        y_prob = mlp.predict_proba(X_test)

        accuracy.append(accuracy_score(y_test, y_pred))
        precision.append(precision_score(y_test, y_pred, average='weighted'))
        recall.append(recall_score(y_test, y_pred, average='weighted'))
        f1.append(f1_score(y_test, y_pred, average='weighted'))
        auc.append(roc_auc_score(y_test, y_prob, multi_class='ovr'))
        kappa.append(cohen_kappa_score(y_test, y_pred))

        # Calculate confusion matrix
        cm = confusion_matrix(y_test, y_pred)
        confusion_matrices.append(cm)

    return {
        'accuracy': np.mean(accuracy),
        'precision': np.mean(precision),
        'recall': np.mean(recall),
        'f1': np.mean(f1),
        'auc': np.mean(auc),
        'kappa': np.mean(kappa),
        'confusion_matrices': confusion_matrices
    }


# Execução dos Experimentos
results = {}

# Configurações dos experimentos
layer_settings = [
    ((10, 5), '2 Layers'),
    ((50, 30, 10), 'Many Layers')
]

kf_settings = [
    (5, '5 Folds'),
    (50, '50 Folds')
]

# Executar os experimentos
for hidden_layers, layer_label in layer_settings:
    for n_splits, kf_label in kf_settings:
        key = f'{kf_label}_{layer_label}'
        results[key] = evaluate_model(
            X_normalized, y_classification, n_splits=n_splits, hidden_layers=hidden_layers)

# Exibe resultados
for key, value in results.items():
    print(f'{key}: {value}')

# Visualização dos Resultados
# Converte os resultados em um DataFrame para visualização
results_df = pd.DataFrame(results).T

# Plotar os resultados
plt.figure(figsize=(14, 8))
sns.barplot(data=results_df)
plt.xticks(rotation=45)
plt.title('Comparação de Desempenho do MLP')
plt.show()
