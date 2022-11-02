Jake Epperson - A02307503

# Tasksheet 5 - Solutions

## Task 1

**Source Code** : Implicit Euler - [docs]()

```python
from root_finding import newton

MAX_ITERS = 25
TOL = 0.000001

def implicit_euler(f, f_prime, T, Y, step, n, verbose=False):
    if verbose:
        print("%12s%12s%12s".format("step (k)", "y", "t"))
    y = Y[0]
    for k in range(n - 1):
        approx = 0
        solve = lambda x: x - Y[k] - step * f(T[k + 1], x)
        solve_prime = lambda x: 1 - step * f_prime(x)
        Y[k + 1] = newton(approx, solve, solve_prime, TOL, MAX_ITERS, verbose=verbose, print_result=False)
        y += step * f(T[k + 1], Y[k + 1])
        Y[k + 1] = y
        if verbose:
            print("%12d%12f%12f".format(k, Y[k], T[k]))

    return y
```

**Test Function**

```python
def task_1():
    step = 0.01
    endpoint = 50
    alphas = [0.01, 0.2, 2.0]
    beta = 0.0005
    T = np.arange(0, endpoint, step)
    for alpha in alphas:
        dP_dt = lambda t, p: alpha * p - beta * p * p
        dP_dt_prime = lambda p: alpha - 2 * beta * p
        P = np.zeros(T.shape[0])
        P[0] = 10.0
        differentiation.implicit_euler(dP_dt, dP_dt_prime, T, P, step, T.shape[0])
        plt.plot(T, P)
    plt.legend(['alpha = 0.01', 'alpha = 0.2', 'alpha = 2.0'])
    plt.xlabel("t")
    plt.ylabel("P")
    plt.title("Implicit Euler method on logistic equation dP/dt = alpha * P - beta * P^2")
    plt.show()
```

To test the implicit_euler function on the logistics equation `dP/dt = alpha * P - beta * P^`,

    python tests/tasksheet5.py -t 1

from the `math4610/` directory.

**Output**

`Image of graph here`

## Task 2

**Source Code** : Analytic Solution - [docs]()

```python
def analytic_sol(F, T):
    solutions = np.zeros(T.shape[0])
    for k in range(T.shape[0]):
        solutions[k] = F(T[k])
    return solutions
```

**Test Function**

```python
def task_2():
    step = 0.01
    endpoint = 50
    alphas = [0.01, 0.2, 2.0]
    beta = 0.0005
    P0 = 10.0
    T = np.arange(0, endpoint, step)
    for alpha in alphas:
        c = (alpha - P0 * beta) / P0
        p = lambda t: alpha / (c * np.exp(-alpha * t) + beta)
        solutions = differentiation.analytic_sol(p, T)
        plt.plot(T, solutions)
    plt.legend(['alpha = 0.01', 'alpha = 0.2', 'alpha = 2.0'])
    plt.xlabel("t")
    plt.ylabel("P")
    plt.title("Analytic solution of logistic equation dP/dt = alpha * P - beta * P^2")
    plt.show()
```

To test the analytic solution derived above (from the logistics equation `dP/dt = alpha * P - beta * P^2`) we pass the derived equation for P to the function analytic_sol along with the time steps (t) we would like to evaluate P at. This can be seen above in the test function task_2.

Run the following,

    python tests/tasksheet5.py -t 2

from the `math4610/` directory to run the analytic_sol test function.

**Output**

`Image of graph here`

## Task 3

The source code for the

**Source Code** : Explicit Euler - [docs]()

```python
def explicit_euler(f, T, Y, step, n, verbose=False):
    if verbose:
        print("%12s%12s%12s".format("step (k)", "y", "t"))
    y = Y[0]
    for k in range(n - 1):
        y += step * f(T[k], Y[k])
        Y[k + 1] = y
        if verbose:
            print("%12d%12f%12f".format(k, Y[k], T[k]))
```

**Test Function**

```python
def task_3():
    step = 0.01
    endpoint = 50
    alphas = [0.01, 0.2, 2.0]
    beta = 0.0005
    P0 = 10.0
    T = np.arange(0, endpoint, step)

    # Implicit Solutions
    f1 = plt.figure("Implicit Euler's Solution")
    for alpha in alphas:
        dP_dt = lambda t, p: alpha * p - beta * p * p
        dP_dt_prime = lambda p: alpha - 2 * beta * p
        P = np.zeros(T.shape[0])
        P[0] = P0
        differentiation.implicit_euler(dP_dt, dP_dt_prime, T, P, step, T.shape[0])
        plt.plot(T, P)
    plt.legend(['Implicit: alpha=0.01', 'Implicit: alpha=0.2', 'Implicit: alpha=2.0'])
    plt.xlabel("t")
    plt.ylabel("P")

    # Explicit Solutions
    f2 = plt.figure("Explicit Euler's Solutoin")
    for alpha in alphas:
        dP_dt = lambda t, p: alpha * p - beta * p * p
        P = np.zeros(T.shape[0])
        P[0] = P0
        differentiation.explicit_euler(dP_dt, T, P, step, T.shape[0])
        plt.plot(T, P)
    plt.legend(['Explicit: alpha=0.01', 'Explicit: alpha=0.2', 'Explicit: alpha=2.0'])
    plt.xlabel("t")
    plt.ylabel("P")

    # Analytic Solutions
    f3 = plt.figure("Analytic Solution")
    for alpha in alphas:
        c = (alpha - P0 * beta) / P0
        p = lambda t: alpha / (c * np.exp(-alpha * t) + beta)
        solutions = differentiation.analytic_sol(p, T)
        plt.plot(T, solutions)
    plt.legend(['Analytic: alpha=0.01', 'Analytic: alpha=0.2', 'Analytic: alpha=2.0'])
    plt.xlabel("t")
    plt.ylabel("P")
    plt.show()
```

Run the following,

    python tests/tasksheet5.py -t 3

from the `math4610/` directory to compare the output the three different ways of computing the solution to the logistic equation `dP/dt = alpha * P - beta * P^2` produce.

**Output**

`Image of graphs here`

## Task 4

**Source Code** : Integration with Trapezoid Rule - [docs]()

```python
def trapezoid(f, a , b, n):
    h = (b - a) / n
    integral = 0.0
    integral += f(a) / 2
    for k in range(1, n):
        integral  += f(a + k * h)
    integral += f(b) / 2

    return integral * h
```

**Test Function**

```python
def task_4():
    print("Trapezoid rule with f(x) = e^(-x^2)\n")
    f = lambda x: np.exp(-x ** 2)
    a = 0
    b = np.pi / 4
    values = [2, 4, 8, 16, 32, 64]
    for n in values:
        print(f"\tn = {n}: {integration.trapezoid(f, a, b, n)}")
    print()
```

To test trapezoid on the integral of `e^(-x^2)` on the interval [0, pi/4] run,

    python tests/tasksheet5.py -t 5

from the `math4610/` directory.

**Output**

```
Trapezoid rule with f(x) = e^(-x^2)

	n = 2: 0.6388862805734845
	n = 4: 0.6471507696813964
	n = 8: 0.6491991053630145
	n = 16: 0.6497100964398593
	n = 32: 0.6498377761980952
	n = 64: 0.6498696918915156
```

## Task 5

**Source Code** : Integration with Simposon's Rule - [docs]()

```python
def simpson(f, a, b, n):
    h = (b - a) / n
    X = np.linspace(a, b, n)
    Y = np.array([f(x) for x in X])
    sum1 = 2 * sum(Y[:n-2:2])
    sum2 = 4 * sum(Y[1:n-1:2])

    return (h / 3) * (f(a) + sum1 + sum2 + f(b))
```

**Test Function**

```python
def task_5():
    print("Simpson rule with f(x) = e^(-x^2)\n")
    f = lambda x: np.exp(-x ** 2)
    a = 0
    b = np.pi / 4
    values = [2, 4, 8, 16, 32, 64]
    for n in values:
        print(f"\tn = {n}: {integration.simpson(f, a, b, n)}")
    print()

    actual = 0.64988
    N = np.array([4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048])
    errors = []
    for n in N:
        errors.append(np.abs(actual - integration.simpson(f, a, b, n)))
    plt.loglog(N, errors, base=2)
    intercept, slope = fitting.simple_linear_regression(np.log2(N), np.log2(np.array(errors)))
    print(f"Convergence rate of Simpsons: {np.abs(slope)}")
    plt.legend([f'O(h^{np.abs(slope)})'])
    plt.xlabel("log2(n)")
    plt.ylabel("log2(error)")
    plt.title('log-log plot of Simpson error terms')
    plt.show()
```

To test simpson on the integral of `e^(-x^2)` on the interval [0, pi/4] run,

    python tests/tasksheet5.py -t 5

from the `math4610/` directory.

**Output**

```
Simpson rule with f(x) = e^(-x^2)

	n = 2: 0.2015385992084397
	n = 4: 0.47612603537049214
	n = 8: 0.5732762348216929
	n = 16: 0.6136734914869292
	n = 32: 0.6322487864804811
	n = 64: 0.6411765609165246

Convergence rate of Simpsons: -1.0279100982692857
```

`image here`
