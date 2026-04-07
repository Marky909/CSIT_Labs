import numpy as np
import matplotlib.pyplot as plt

# ----------------------------
# 1. Step Function (Binary Step)
# ----------------------------
def step(x):
    return np.where(x >= 0, 1, 0)

# ----------------------------
# 2. Sigmoid Function
# ----------------------------
def sigmoid(x):
    return 1 / (1 + np.exp(-x))

# ----------------------------
# 3. Tanh Function
# ----------------------------
def tanh(x):
    return np.tanh(x)

# ----------------------------
# 4. ReLU (Rectified Linear Unit)
# ----------------------------
def relu(x):
    return np.maximum(0, x)

# ----------------------------
# 5. Leaky ReLU
# ----------------------------
def leaky_relu(x, alpha=0.01):
    return np.where(x > 0, x, alpha * x)

# ----------------------------
# Test & Plot
# ----------------------------
x = np.linspace(-10, 10, 500)

plt.figure(figsize=(10, 6))
plt.plot(x, step(x), label='Step')
plt.plot(x, sigmoid(x), label='Sigmoid')
plt.plot(x, tanh(x), label='Tanh')
plt.plot(x, relu(x), label='ReLU')
plt.plot(x, leaky_relu(x), label='Leaky ReLU')
plt.title('Activation Functions')
plt.xlabel('x')
plt.ylabel('f(x)')
plt.legend()
plt.grid(True)
plt.show()
