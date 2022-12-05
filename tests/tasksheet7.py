import os
import sys
import argparse
import subprocess
import numpy as np

# Computing Products of Matrices with OpenMP
def task_1():
    print("Matrix Products in Serial/Parallel\n")
    subprocess.run(["./src/linear_algebra/C/mat_prod.exe"]) # run mat_prod.exe

# Serial/Parallel Hadamard Product of Vectors
def tasks_23():
    print("Hadamard Vector Products in Serial/Parallel\n")
    subprocess.run(["./src/linear_algebra/C/had_v.exe"]) # run had_v.exe

# Generalization of the Hadamard Product to Matrices
def task_4():
    print("Hadamard Matrix Products in Serial/Parallel\n")
    subprocess.run(["./src/linear_algebra/C/had_m.exe"]) # run had_m.exe

# Outer Products of Vectors/Matrices
def task_5():
    print("Vectir Outer Products in Serial/Parallel\n")
    subprocess.run(["./src/linear_algebra/C/outer.exe"]) # run outer.exe

FUNCTIONS = {
    '1': task_1,
    '2': tasks_23,
    '3': tasks_23,
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

args = parser.parse_args(sys.argv[1:])

for test in args.tasks:
    FUNCTIONS[test]()
