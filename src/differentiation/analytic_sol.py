import numpy as np

def analytic_sol(F, T):
    Y = np.zeros(T.shape[0])
    for k in range(T.shape[0]):
        Y[k] = F(T[k])
    return Y