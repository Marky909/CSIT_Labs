import numpy as np

# --------------------------
# Sigmoid Activation & Derivative
# --------------------------
def sigmoid(x):
    return 1 / (1 + np.exp(-x))

def sigmoid_derivative(x):
    return x * (1 - x)

# --------------------------
# Training Data for XOR
# --------------------------
X = np.array([
    [0, 0],
    [0, 1],
    [1, 0],
    [1, 1]
])

y = np.array([
    [0],
    [1],
    [1],
    [0]
])

# --------------------------
# Initialize weights & biases
# --------------------------
np.random.seed(42)  # reproducibility
input_layer_neurons = 2
hidden_layer_neurons = 2
output_neurons = 1

W1 = np.random.uniform(size=(input_layer_neurons, hidden_layer_neurons))
b1 = np.random.uniform(size=(1, hidden_layer_neurons))
W2 = np.random.uniform(size=(hidden_layer_neurons, output_neurons))
b2 = np.random.uniform(size=(1, output_neurons))

# --------------------------
# Training with Backpropagation
# --------------------------
lr = 0.5  # learning rate
epochs = 10000

for epoch in range(epochs):
    # Forward pass
    hidden_input = np.dot(X, W1) + b1
    hidden_output = sigmoid(hidden_input)

    final_input = np.dot(hidden_output, W2) + b2
    final_output = sigmoid(final_input)

    # Backpropagation
    error = y - final_output
    d_output = error * sigmoid_derivative(final_output)

    error_hidden = d_output.dot(W2.T)
    d_hidden = error_hidden * sigmoid_derivative(hidden_output)

    # Update weights and biases
    W2 += hidden_output.T.dot(d_output) * lr
    b2 += np.sum(d_output, axis=0, keepdims=True) * lr
    W1 += X.T.dot(d_hidden) * lr
    b1 += np.sum(d_hidden, axis=0, keepdims=True) * lr

    # Print loss occasionally
    if epoch % 2000 == 0:
        loss = np.mean(np.square(error))
        print(f"Epoch {epoch}, Loss: {loss:.4f}")

# --------------------------
# Testing
# --------------------------
print("\nFinal Predictions:")
for i in range(len(X)):
    print(f"Input: {X[i]} => Predicted: {final_output[i][0]:.4f}, Expected: {y[i][0]}")
