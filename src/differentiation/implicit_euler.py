from root_finding import newton

MAX_ITERS = 25
TOL = 0.000001

def implicit_euler(f, f_prime, T, Y, step, n, verbose=False):
    if verbose:
        print("%12s%12s%12s".format("step (k)", "y", "t"))
    y = Y[0]
    for k in range(n - 1):
        approx = 0 # ???????????????????????????
        solve = lambda x: x - Y[k] - step * f(T[k + 1], x)
        solve_prime = lambda x: 1 - step * f_prime(x)
        Y[k + 1] = newton(approx, solve, solve_prime, TOL, MAX_ITERS, verbose=verbose, print_result=False)
        y += step * f(T[k + 1], Y[k + 1])
        Y[k + 1] = y
        if verbose:
            print("%12d%12f%12f".format(k, Y[k], T[k]))

    return y