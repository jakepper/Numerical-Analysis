import numpy as np

from bisection import bisect

def newton_hybrid(a, b, f, f_prime, tol, max_iters, verbose=False):
    if verbose:
        print('\n   {:^16s}{:^16s}{:^16s}'.format('Iteration', '~Root', 'Error'))

    root = np.nan
    error = 10 * tol
    prev_error = error * 10
    i = 0
    x0 = (a + b) / 2 # initialize x0 to midpoint of bounds (a, b)
    while (error > tol) and (i < max_iters):
        # try newtons
        x1 = x0 - (f(x0) / f_prime(x0))
        error = np.abs(x1 - x0)
        if verbose:
            print('   {:^16d}{:^16f}{:^16e}'.format(i + 1, x1, error))
        if (x1 <= a) or (x1 >= b) or (error > prev_error): # newtons method is diverging
            # perform k iterations of bisection (calculated in bisect)
            a,b,x0 = bisect(a, b, f, tol, verbose=verbose, print_result=False) # bisect and update bounds
            error = np.abs(x1 - x0)
            root = x0
            if verbose:
                print('   {:^16s}{:^16s}{:^16s}'.format('Iteration', '~Root', 'Error'))
        else: # newtons method is converging
            x0 = x1
            root = x1
        prev_error = error
        i += 1

    print('\n   Approximate Root: {:f}'.format(root))
    return root