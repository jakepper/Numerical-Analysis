import sys
import argparse
import subprocess


def task_1():
    print("Task 1: Kronecker Product of Matrices (serial/parallel)\n")
    subprocess.run(["./src/linear_algebra/C/executables/kronecker.exe"]) # run kronecker.exe

def task_2():
    print("Task 2: Inefficient Power Method (serial)\n")
    subprocess.run(["./src/linear_algebra/C/executables/powerx.exe"]) # run powerx.exe

def task_34():
    print("Tasks 3 and 4: Efficient Power Method (serial/parallel)\n")
    subprocess.run(["./src/linear_algebra/C/executables/power.exe"]) # run power.exe
    subprocess.run(["./src/linear_algebra/C/executables/power64.exe"]) # run power64.exe
    subprocess.run(["./src/linear_algebra/C/executables/power128.exe"]) # run power128.exe
    subprocess.run(["./src/linear_algebra/C/executables/power256.exe"]) # run power256.exe

def task_5():
    print("Task 5: Jacobi Iterative Scheme for Linear Systems (serial/parallel)\n")
    subprocess.run(["./src/linear_algebra/C/executables/jacobi.exe"]) # run jacobi.exe

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
