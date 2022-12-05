import os
import sys
import argparse
import subprocess
import numpy as np

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

args = parser.parse_args(sys.argv[1:])

for test in args.tasks:
    FUNCTIONS[test]()
