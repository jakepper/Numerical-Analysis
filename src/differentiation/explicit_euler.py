
def explicit_euler(f, T, Y, step, n, verbose=False):
    if verbose:
        print("%12s%12s%12s".format("step (k)", "y", "t"))
    y = Y[0]
    for k in range(n - 1):
        y += step * f(T[k], Y[k])
        Y[k + 1] = y
        if verbose:
            print("%12d%12f%12f".format(k, Y[k], T[k]))