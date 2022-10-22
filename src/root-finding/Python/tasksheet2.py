import sys
import argparse
import warnings
import random
import numpy as np

from newton import newton
from secant import secant
from newton_hybrid import newton_hybrid
from secant_hybrid import secant_hybrid


TOLERANCE = 0.000001
MAX_ITERS = 25

warnings.filterwarnings("ignore")

def test_task_1(verbose):
    print('\nNewtons method with f(x) = x * e^(-x)')
    x0 = 0.54321
    f = lambda x: x * np.exp(-x)
    f_prime = lambda x: (1 - x) * np.exp(-x)
    newton(x0, f, f_prime, TOLERANCE, MAX_ITERS, verbose=verbose)
    print()

def test_task_2(verbose):
    print('\nSecant method with f(x) = x * e^(-x)')
    a = -0.4567
    b = 0.7654
    f = lambda x: x * np.exp(-x)
    secant(a, b, f, TOLERANCE, MAX_ITERS, verbose=verbose)
    print()
    
def test_task_4(verbose):
    print('\nNewton Hybrid method with f(x) = x * e^(-x)')
    f = lambda x: 10.14 * np.exp(x*x) * np.cos(np.pi/x)
    f_prime = lambda x: ((1014 * np.cos(np.pi/x) * x*x*x) + (507 * np.pi * np.sin(np.pi/x))) * (np.exp(x*x)) / (50 * x*x)
    intervals = [0.1, 0.11, 0.125, 0.14, 0.17, 0.21, 0.26, 0.31, 0.6, 1, 2.8] # testing on 10 roots
    for i in range(len(intervals) - 1):
        a = intervals[i]
        b = intervals[i + 1]
        print(f'\nInterval [{a}, {b}]:')
        newton_hybrid(a, b, f, f_prime, TOLERANCE, MAX_ITERS, verbose=verbose)
    print()

def test_task_5(verbose):
    print('\nSecant Hybrid method with f(x) = x * e^(-x)')
    f = lambda x: 10.14 * np.exp(x*x) * np.cos(np.pi/x)
    intervals = [0.1, 0.11, 0.125, 0.14, 0.17, 0.21, 0.26, 0.31, 0.6, 1, 2.8] # testing on 10 roots
    for i in range(len(intervals) - 1):
        a = intervals[i]
        b = intervals[i + 1]
        print(f'\nInterval [{a}, {b}]:')
        secant_hybrid(a, b, f, TOLERANCE, MAX_ITERS, verbose=verbose)
    print()

FUNCTIONS = {
    '1': test_task_1,
    '2': test_task_2,
    '3': random.choice([test_task_2, test_task_1]),
    '4': test_task_4,
    '5': test_task_5,
}

parser = argparse.ArgumentParser(description='Tasksheet 2 task tests/outputs')
parser.add_argument('-t', '--tasks', 
                        nargs='+', 
                        choices=FUNCTIONS,
                        help='Task/s to be tested',
                        required=True
                    )
parser.add_argument('-v', '--verbose', 
                        action='store_true', 
                        default=False,
                        help="Verbose mode - Tabular results"
                    )

args = parser.parse_args(sys.argv[1:])

for test in args.tasks:
    FUNCTIONS[test](args.verbose)
