import numpy as np

def analytic_sol(F, T):
    solutions = np.zeros(T.shape[0])
    for k in range(T.shape[0]):
        solutions[k] = F(T[k])
    return solutions