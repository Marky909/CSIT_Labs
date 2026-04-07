import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import make_regression

# Step 1: Generate dataset
X, y = make_regression(n_samples=100, n_features=1, noise=15, random_state=42)
y = y.reshape(-1, 1)
m = X.shape[0]

# Add bias term (X_b = [1, x])
X_b = np.c_[np.ones((m, 1)), X]

# Step 2: Initialize parameters
theta = np.random.randn(2, 1)  # random start

# Hyperparameters
learning_rate = 0.01
n_iterations = 1000

# To track cost
cost_history = []

# Step 3: Gradient Descent
for i in range(n_iterations):
    gradients = (2/m) * X_b.T.dot(X_b.dot(theta) - y)
    theta -= learning_rate * gradients

    # Compute Mean Squared Error cost
    cost = (1/m) * np.sum((X_b.dot(theta) - y) ** 2)
    cost_history.append(cost)

print("Final parameters (theta):")
print(theta)

# Step 4: Plot cost function decrease
plt.figure(figsize=(10, 4))
plt.plot(range(n_iterations), cost_history, "b-")
plt.xlabel("Iteration")
plt.ylabel("Cost (MSE)")
plt.title("Cost Function Convergence")
plt.show()

# Step 5: Plot regression line vs actual data
plt.figure(figsize=(10, 5))
plt.scatter(X, y, color="blue", label="Actual Data")

# Sort X for a smooth line
X_sorted = np.sort(X, axis=0)
X_b_sorted = np.c_[np.ones((X_sorted.shape[0], 1)), X_sorted]
y_pred = X_b_sorted.dot(theta)

plt.plot(X_sorted, y_pred, color="red", label="Learned Line (GD)")
plt.xlabel("Feature")
plt.ylabel("Target")
plt.title("Linear Regression using Gradient Descent")
plt.legend()
plt.show()
