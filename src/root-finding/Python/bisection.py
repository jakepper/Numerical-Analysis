import numpy as np


def bisect(a, b, f, tol, verbose=False):
    if verbose:
        print('\n   {:^16s}{:^16s}{:^16s}{:^16s}{:^16s}{:^16s}{:^16s}'.format('Iteration','a','b','midpoint (m)','f(a)','f(b)','f(m)'))

    k = np.abs(int(-((np.log10(tol) / np.log10(b - a)) / np.log10(2)) + 1))
    root = np.nan
    i = 0
    while (i < k):
        fa = f(a)
        fb = f(b)
        if (a < b) and (fa * fb < 0):
            m = (a + b) / 2 # let m represent the midpoint between a and b
            fm = f(m)
            if verbose:
                print('   {:^16d}{:^16.4f}{:^16.4f}{:^16.4f}{:^16.4f}{:^16.4f}{:^16.4f}'.format(i + 1, a, b, m, fa, fb, fm))
            if np.abs(fm) < tol:
                root = m
                break
            elif fa * fm < 0:
                b = m
            else:
                a = m
            root = m
        i += 1

    print('\n   Approximate Root: {:f}'.format(root))
    return root