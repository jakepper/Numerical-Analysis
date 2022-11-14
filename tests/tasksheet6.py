import os
import sys
import argparse
import subprocess
import numpy as np

cwd = os.getcwd()

sys.path.append("src/")
from linear_algebra import vectors
from linear_algebra import matrices

def task_2():
    subprocess.run(["./src/integration/C/pi.exe"])
    print()

def task_3():
    task_2()

def task_4():
    subprocess.run(["./src/integration/C/e.exe"])
    print()

def task_5():
    print("Linear Algebra")
    print("\nVector operations with,\n")
    u = np.array([2, 3, 4])
    v = np.array([5, 6, 7])
    print("\t u =", u, " v =", v, "\n")

    print("Operations\n")
    print("u + v:", vectors.add(u, v))
    print("u - v:", vectors.sub(u, v))
    print("2 * v:", vectors.mult(2, u))
    print("u . v:", vectors.dot(u, v))
    print("u x v:", vectors.cross(u, v))
    print("u x v x u:", vectors.triple(u, v, u))

    print("\nMatrix operations with,\n")
    A = np.array([[1, 2, 3], [1, 2, 3], [1, 2, 3]])
    B = np.array([[3, 2, 1], [3, 2, 1], [3, 2, 1]])
    b = np.array([2, 2, 2])
    print("A =")
    print(A, '\n')
    print("B =")
    print(B, '\n')
    print("b =", b, '\n')

    print("Operations\n")
    print("A + B:")
    print(matrices.add(A, B), '\n')
    print("A - B:")
    print(matrices.sub(A, B), '\n')
    print("A * B:")
    print(matrices.mult(A, B), '\n')
    print("A * b:")
    print(matrices.action(A, b), '\n')

FUNCTIONS = {
    '2': task_2,
    '3': task_2,
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
