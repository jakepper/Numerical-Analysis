import sys
import numpy as np
import matplotlib.pyplot as plt

sys.path.append("src/")
import differentiation

def task_1(verbose):
    # print('\nImplicit Euler method with dP/dt = ...')
    step = 0.2
    endpoint = 1000
    alphas = [0.2, 0.01, 2.0]
    beta = 0.0005
    T = np.arange(0, endpoint, step)
    for alpha in alphas:
        dP_dt = lambda t, p: alpha * p - beta * p * p
        dP_dt_prime = lambda p: alpha - 2 * beta * p
        P = np.zeros(T.shape[0])
        P[0] = 10.0
        differentiation.implicit_euler(dP_dt, dP_dt_prime, T, P, step, T.shape[0], verbose=False)
        plt.plot(T, P)
    plt.legend(['alpha = 0.2', 'alpha = 0.01', 'alpha = 2.0'])
    plt.title("Implicit Euler method on logistic ODE dP/dt = alpha * P - beta * P^2")
    plt.show()

def task_2(verbose):
    pass

def task_3(verbose):
    pass

task_1(False)