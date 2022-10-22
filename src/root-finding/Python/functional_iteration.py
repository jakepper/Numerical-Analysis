import numpy as np

def func_iter(x0, g, tol, max_iters, verbose=False):
    if verbose: 
        print('\n   {:^18s}{:^18s}{:^18s}'.format('Iteration', '\u2248Root', 'Error'))
    
    root = np.nan
    error = 10 * tol
    i = 0
    while (error > tol) and (i < max_iters):
        x1 = g(x0)
        error = np.abs(x1 - x0)
        x0 = x1
        root = x0
        if verbose: 
            print('   {:^18d}{:^18.4e}{:^18e}'.format(i + 1, x0, error))
        i += 1
    
    print('\n\tApproximate Root: {:f}'.format(root))
    return root