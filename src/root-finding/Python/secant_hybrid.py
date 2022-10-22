import sys
import numpy as np

from bisection import bisect


def secant_hybrid(x0, x1, f, tol, max_iters, verbose=False):
    if verbose:
        print('\n   {:^16s}{:^16s}{:^16s}'.format('Iteration', '~Root', 'Error'))

    root = np.nan
    error = 10 * tol
    prev_error = error * 10
    i = 0
    while (error > tol) and (i < max_iters):
        # try secant
        fx1 = f(x1)
        x2 = x1 - ((x0 - x1) / (f(x0) - fx1)) * fx1
        error = np.abs(f(x2))
        if verbose:
            print('   {:^16d}{:^16e}{:^16e}'.format(i + 1, x2, error))
        if (x2 <= x0) or (x2 >= x1) or (error > prev_error): # secant method is diverging
            if error < tol: break # handles edge case where x0 > x1
            # perform k iterations of bisection (calculated in bisect)
            x0,x1,root = bisect(x0, x1, f, tol, verbose=verbose, print_result=False)
            error = np.abs(f(root))
            if verbose:
                print('   {:^16s}{:^16s}{:^16s}'.format('Iteration', '~Root', 'Error'))
        else: # secant method is converging
            x0 = x1
            x1 = x2
            root = x2
        prev_error = error
        i += 1
    
    print('\n\tApproximate Root: {:f}'.format(root))
    return root