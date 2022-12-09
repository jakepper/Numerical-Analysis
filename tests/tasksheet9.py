import sys
import argparse
import subprocess


def task_1():
    print("Task 1: Inverse Power Methdod (serial)\n")
    subprocess.run(["./src/linear_algebra/C/executables/inverse_power_test.exe"]) # run inverse_power_test.exe

def task_2():
    print("Task 2: Shifted Inverse Power Methdod (serial)\n")
    subprocess.run(["./src/linear_algebra/C/executables/inverse_power_shift.exe"]) # run inverse_power_shift.exe

def task_3():
    print("Task 3: Finding More Eigenvalues\n")
    subprocess.run(["./src/linear_algebra/C/executables/more_values.exe"]) # run more_values.exe

def task_4():
    print("Task 4: Shifted Inverse Power Method (parallel)\n")
    subprocess.run(["./src/linear_algebra/C/executables/inverser_power_shift_comparison16.exe"]) # run inverse_power_shift_comparison.exe

def task_5():
    print("Task 5: Shifted Inverse Power Methdod\n")
    print("Missing")

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

args = parser.parse_args(sys.argv[1:])

tasks = []
for test in args.tasks:
    if test not in tasks:
        FUNCTIONS[test]()
        tasks.append(test) 