import numpy as np

def bisect(a, b, f, tol, verbose=False, print_result=True):
    if verbose:
        print('\n   {:^16s}{:^16s}{:^16s}{:^16s}{:^16s}{:^16s}{:^16s}{:^16s}'.format('Iteration','a','b','midpoint (m)','f(a)','f(b)','f(m)','Error'))

    k = np.abs(int(-((np.log10(tol) / np.log10(b - a)) / np.log10(2)) + 1))
    root = np.nan
    i = 0
    while (i < k):
        fa = f(a)
        fb = f(b)
        if (a < b) and (fa * fb < 0):
            m = (a + b) / 2 # let m represent the midpoint between a and b
            fm = f(m)
            error = np.abs(fm)
            if verbose:
                print('   {:^16d}{:^16f}{:^16f}{:^16f}{:^16f}{:^16f}{:^16f}{:^16e}'.format(i + 1, a, b, m, fa, fb, fm, error))
            if error < tol:
                root = m
                break
            elif fa * fm < 0:
                b = m
            else:
                a = m
            root = m
        i += 1

    if print_result: print('\n\tApproximate Root: {:f}'.format(root))
    return a, b, root