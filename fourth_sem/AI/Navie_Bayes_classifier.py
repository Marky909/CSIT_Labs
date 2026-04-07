import math
import random
import numpy as np
import matplotlib.pyplot as plt
from sklearn.metrics import confusion_matrix, ConfusionMatrixDisplay, precision_score, recall_score, f1_score

# -------------------------
# 1. Encode class labels
# -------------------------
def encode_class(mydata):
    classes = list(set(row[-1] for row in mydata))
    mapping = {cls: idx for idx, cls in enumerate(classes)}
    for row in mydata:
        row[-1] = mapping[row[-1]]
    return mydata, mapping

# -------------------------
# 2. Split dataset
# -------------------------
def splitting(mydata, ratio=0.7):
    train_size = int(len(mydata) * ratio)
    train = []
    test = list(mydata)

    while len(train) < train_size:
        index = random.randrange(len(test))
        train.append(test.pop(index))
    return train, test

# -------------------------
# 3. Group by class
# -------------------------
def groupUnderClass(mydata):
    grouped = {}
    for row in mydata:
        label = row[-1]
        grouped.setdefault(label, []).append(row)
    return grouped

# -------------------------
# 4. Mean & Std Dev
# -------------------------
def MeanAndStdDev(numbers):
    return np.mean(numbers), np.std(numbers)

def MeanAndStdDevForClass(mydata):
    summaries = {}
    grouped = groupUnderClass(mydata)
    for label, rows in grouped.items():
        summaries[label] = [MeanAndStdDev(col) for col in zip(*rows)]
    return summaries

# -------------------------
# 5. Gaussian Probability
# -------------------------
def calculateGaussianProbability(x, mean, stdev):
    epsilon = 1e-10  # avoid division by zero
    exponent = math.exp(-(math.pow(x - mean, 2) / (2 * math.pow(stdev + epsilon, 2))))
    return (1 / (math.sqrt(2 * math.pi) * (stdev + epsilon))) * exponent

# -------------------------
# 6. Class Probability
# -------------------------
def calculateClassProbabilities(summaries, test_row):
    probabilities = {}
    for label, class_summaries in summaries.items():
        probabilities[label] = 1
        for i in range(len(class_summaries) - 1):  # exclude label column
            mean, stdev = class_summaries[i]
            probabilities[label] *= calculateGaussianProbability(test_row[i], mean, stdev)
    return probabilities

# -------------------------
# 7. Prediction
# -------------------------
def predict(summaries, row):
    probabilities = calculateClassProbabilities(summaries, row)
    return max(probabilities, key=probabilities.get)

def getPredictions(summaries, test):
    return [predict(summaries, row) for row in test]

# -------------------------
# 8. Accuracy
# -------------------------
def accuracy_rate(test, predictions):
    correct = sum(1 for i in range(len(test)) if test[i][-1] == predictions[i])
    return correct / len(test) * 100

# -------------------------
# Main
# -------------------------
if __name__ == "__main__":
    # Example dataset: [feature1, feature2, ..., class]
    mydata = [
        [1.0, 2.1, 'A'],
        [1.3, 1.9, 'A'],
        [3.1, 3.0, 'B'],
        [3.0, 2.7, 'B'],
        [0.8, 2.5, 'A'],
        [2.9, 2.8, 'B']
    ]

    # Encode class labels
    mydata, mapping = encode_class(mydata)

    # Split dataset
    train, test = splitting(mydata, ratio=0.7)

    # Summarize by class
    summaries = MeanAndStdDevForClass(train)

    # Make predictions
    predictions = getPredictions(summaries, test)

    # True labels
    y_true = [row[-1] for row in test]

    # Calculate accuracy
    acc = accuracy_rate(test, predictions)
    print(f"Accuracy: {acc:.2f}%")

    # Precision, Recall, F1
    print("Precision:", precision_score(y_true, predictions, average='macro'))
    print("Recall:", recall_score(y_true, predictions, average='macro'))
    print("F1 Score:", f1_score(y_true, predictions, average='macro'))

    # Confusion Matrix
    cm = confusion_matrix(y_true, predictions)
    disp = ConfusionMatrixDisplay(confusion_matrix=cm)
    disp.plot(cmap=plt.cm.Blues)
    plt.title("Confusion Matrix")
    plt.show()
