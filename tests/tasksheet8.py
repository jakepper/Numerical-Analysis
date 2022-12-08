import os
import sys
import argparse
import subprocess
import numpy as np


def task_1():
    print("Task 1: Kronecker Product of Matrices")
    subprocess.run(["./src/linear_algebra/C/executables/kronecker.exe"]) # run mat_prod.exe

def task_2():
    print("Task 2: The Power Method")
    subprocess.run(["./src/linear_algebra/C/executables/power.exe"]) # run mat_prod.exe

def task_34():
    print("Task 3: Efficient Power Method (serial)")
    subprocess.run(["./src/linear_algebra/C/executables/e_power_s.exe"]) # run mat_prod.exe
    print("Task 4: Efficient Power Method (parallel)")
    subprocess.run(["./src/linear_algebra/C/executables/e_power_p.exe"]) # run mat_prod.exe

def task_5():
    print("Task 5: Jacobi Iterative Scheme for Linear Systems")
    subprocess.run(["./src/linear_algebra/C/executables/jacobi.exe"]) # run mat_prod.exe

FUNCTIONS = {
    '1': task_1,
    '2': task_2,
    '3': task_34,
    '4': task_34,
    '5': task_5
}

parser = argparse.ArgumentParser(description='Run test functions on the following')
parser.add_argument('-t', '--tasks', 
                        nargs='+', 
                        choices=FUNCTIONS, 
                        help='Tasks to be tested',
                        required=True
                    )
args = parser.parse_args(sys.argv[1:])

tasks = []
for test in args.tasks:
    if test not in tasks:
        FUNCTIONS[test]()
        tasks.append(test)
