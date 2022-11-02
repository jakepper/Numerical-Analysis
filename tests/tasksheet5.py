import sys
import numpy as np
import argparse
import matplotlib.pyplot as plt

sys.path.append("src/")
import differentiation
import integration
import fitting


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

def task_4():
    print("Trapezoid rule with f(x) = e^(-x^2)\n")
    f = lambda x: np.exp(-x ** 2)
    a = 0
    b = np.pi / 4
    values = [2, 4, 8, 16, 32, 64]
    for n in values:
        print(f"\tn = {n}: {integration.trapezoid(f, a, b, n)}")
    print()

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

FUNCTIONS = {
    '1': task_1,
    '2': task_2,
    '3': task_3,
    '4': task_4,
    '5': task_5
}

parser = argparse.ArgumentParser(description='Run test functions on the following')
parser.add_argument('-t', '--tasks', 
                        nargs='+', 
                        choices=FUNCTIONS, 
                        help='Tasks to be tested',
                        required=True
                    )
# parser.add_argument('-v', '--verbose', 
#                         action='store_true', 
#                         default=False,
#                         help="Verbose mode - Tabular results"
#                     )

args = parser.parse_args(sys.argv[1:])

for test in args.tasks:
    FUNCTIONS[test]()
