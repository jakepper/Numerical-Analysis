import numpy as np

def simpson(f, a, b, n):
    h = (b - a) / n
    X = np.linspace(a, b, n)
    Y = np.array([f(x) for x in X])
    sum1 = 2 * sum(Y[2:n-2:2])
    sum2 = 4 * sum(Y[1:n-1:2])

    return (h / 3) * (f(a) + sum1 + sum2 + f(b))