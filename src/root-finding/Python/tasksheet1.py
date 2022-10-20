import sys
import argparse
import warnings
import numpy as np

from functional_iteration import func_iter
from bisection import bisect

TOLERANCE = 0.000001
MAX_ITERS = 25

warnings.filterwarnings("ignore")

def test_task_1(verbose):
    print('\nFunctional Iteration with f(x) = x * e^(-x)')
    x0 = 1.23456
    print('\n   g -> x - f(x)')
    g = lambda x: x - x * np.exp(-x)
    func_iter(x0, g, TOLERANCE, MAX_ITERS, verbose=verbose)
    g = lambda x: x + x * np.exp(-x)
    print('\n   g -> x + f(x)')
    func_iter(x0, g, TOLERANCE, MAX_ITERS, verbose=verbose)
    print()  

def test_task_3(verbose):
    print('\nFunctional Iteration with f(x) = 10.14 * e^(x^2) * cos(\u03C0/x)')
    n = 40
    x0 = -3.0
    dx = 10.0 / n
    g = lambda x: x - 10.14 * (np.exp(x*x)) * np.cos(np.pi / x)
    # without epsilon
    print('\n   g -> x - f(x)')
    for x in range(n):
        if x0 != 0:
            func_iter(x0, g, TOLERANCE, MAX_ITERS, verbose=verbose)
        x0 += dx
    # with epsilon = 0.0001
    x0 = 3.0
    epsilon = 0.0001
    g = lambda x: x - epsilon * (10.14 * (np.exp(x*x)) * np.cos(np.pi / x))
    print(f'\n   g -> x - \u03B5f(x), \u03B5 = {epsilon}')
    for x in range(n):
        if x0 != 0:
            func_iter(x0, g, TOLERANCE, MAX_ITERS, verbose=verbose)
        x0 += dx
    print()
    
def test_task_4(verbose):
    print('\nBisection with f(x) = x * e^(-x)')
    a = -1.234
    b = 2.654
    f = lambda x: x * np.exp(-x)
    bisect(a, b, f, TOLERANCE, verbose=verbose)
    print('\nBisection with f(x) = 10.14 * e^(x^2) * cos(\u03C0/x)')
    ab = [(0.18, 0.185), (0.215, 0.225), (0.275, 0.29), (0.37, 0.42), (0.6, 0.7)] # bounds containing roots
    f = lambda x: 10.14 * (np.exp(x*x)) * np.cos(np.pi / x)
    for bounds in ab:
        bisect(bounds[0], bounds[1], f, TOLERANCE, verbose=verbose)

FUNCTIONS = {
    '1': test_task_1,
    '2': test_task_1,
    '3': test_task_3,
    '4': test_task_4,
}

parser = argparse.ArgumentParser(description='Run test functions on the following')
parser.add_argument('-t', '--tasks', 
                        nargs='+', 
                        choices=FUNCTIONS, 
                        help='Tasks to be tested',
                        required=True
                    )
parser.add_argument('-v', '--verbose', 
                        action='store_true', 
                        default=False,
                        help="Test Task 1" 
                    )

args = parser.parse_args(sys.argv[1:])

for test in args.tasks:
    FUNCTIONS[test](args.verbose)
