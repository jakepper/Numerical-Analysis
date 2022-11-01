import numpy as np


def secant(x0, x1, f, tol, max_iters, verbose=False):
    if verbose:
        print('\n   {:^16s}{:^16s}{:^16s}'.format('Iteration', '~Root', 'Error'))

    root = np.nan
    error = 10 * tol
    i = 0
    while (error > tol) and (i < max_iters):
        fx1 = f(x1)
        x2 = x1 - ((x0 - x1) / (f(x0) - fx1)) * fx1
        error = np.abs(f(x2))
        x0 = x1
        x1 = x2
        root = x2
        if verbose:
            print('   {:^16d}{:^16e}{:^16e}'.format(i + 1, x2, error))
        i += 1

    print('\n\tApproximate Root: {:f}'.format(root))
    return root