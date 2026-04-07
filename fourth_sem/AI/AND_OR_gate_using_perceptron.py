# importing Python library
import numpy as np

# define Unit Step Function
def unitStep(v):
    return 1 if v >= 0 else 0

# design Perceptron Model
def perceptronModel(x, w, b):
    v = np.dot(w, x) + b
    y = unitStep(v)
    return y

# ----------------------------
# AND Logic Function
# ----------------------------
def AND_logicFunction(x):
    w = np.array([1, 1])
    b = -1.5
    return perceptronModel(x, w, b)

# ----------------------------
# OR Logic Function
# ----------------------------
def OR_logicFunction(x):
    w = np.array([1, 1])
    b = -0.5
    return perceptronModel(x, w, b)

# ----------------------------
# Testing the Perceptron Model
# ----------------------------
test_cases = [
    np.array([0, 0]),
    np.array([0, 1]),
    np.array([1, 0]),
    np.array([1, 1])
]

print("AND Gate Results:")
for t in test_cases:
    print(f"AND({t[0]}, {t[1]}) = {AND_logicFunction(t)}")

print("\nOR Gate Results:")
for t in test_cases:
    print(f"OR({t[0]}, {t[1]}) = {OR_logicFunction(t)}")
