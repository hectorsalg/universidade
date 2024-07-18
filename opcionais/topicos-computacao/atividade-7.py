import numpy as np
from sklearn.datasets import load_breast_cancer
from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import cross_val_score, train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import classification_report, accuracy_score, precision_score, recall_score, f1_score

# Carregamento dos dados
data = load_breast_cancer()
X = data.data
y = data.target
feature_names = data.feature_names

# Divisão dos cenários
# Cenário 1: Dados não normalizados
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42)

# Cenário 2: Dados normalizados
scaler = StandardScaler()
X_normalized = scaler.fit_transform(X)
X_train_norm, X_test_norm, y_train_norm, y_test_norm = train_test_split(
    X_normalized, y, test_size=0.2, random_state=42)

# Função para aplicar o algoritmo ID3 (Decision Tree) e avaliar o desempenho


def evaluate_model(X_train, X_test, y_train, y_test):
    # Instanciação do modelo
    clf = DecisionTreeClassifier(criterion='entropy', random_state=42)

    # Validação cruzada com K=5
    cv_scores = cross_val_score(clf, X_train, y_train, cv=5)

    # Treinamento e predição
    clf.fit(X_train, y_train)
    y_pred = clf.predict(X_test)

    # Avaliação do desempenho
    accuracy = accuracy_score(y_test, y_pred)
    precision = precision_score(y_test, y_pred)
    recall = recall_score(y_test, y_pred)
    f1 = f1_score(y_test, y_pred)
    report = classification_report(y_test, y_pred)

    return cv_scores, accuracy, precision, recall, f1, report


# Cenário 1: Dados não normalizados
cv_scores_non_norm, accuracy_non_norm, precision_non_norm, recall_non_norm, f1_non_norm, report_non_norm = evaluate_model(
    X_train, X_test, y_train, y_test)

# Cenário 2: Dados normalizados
cv_scores_norm, accuracy_norm, precision_norm, recall_norm, f1_norm, report_norm = evaluate_model(
    X_train_norm, X_test_norm, y_train_norm, y_test_norm)

# Resultados
print("Cenário 1: Dados não normalizados")
print("Cross-validation scores:", cv_scores_non_norm)
print("Mean CV score:", np.mean(cv_scores_non_norm))
print("Test set accuracy:", accuracy_non_norm)
print("Test set precision:", precision_non_norm)
print("Test set recall:", recall_non_norm)
print("Test set F1-score:", f1_non_norm)
print("Classification report:\n", report_non_norm)

print("\nCenário 2: Dados normalizados")
print("Cross-validation scores:", cv_scores_norm)
print("Mean CV score:", np.mean(cv_scores_norm))
print("Test set accuracy:", accuracy_norm)
print("Test set precision:", precision_norm)
print("Test set recall:", recall_norm)
print("Test set F1-score:", f1_norm)
print("Classification report:\n", report_norm)
