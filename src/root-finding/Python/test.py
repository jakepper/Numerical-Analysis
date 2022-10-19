import sys
import argparse

def test_task_1(verbose=False):
    print(f"task 1 - {verbose}")

def test_task_2(verbose=False):
    print(f"task 2  - {verbose}")

def test_task_3(verbose=False):
    print(f"task 3  - {verbose}")

def test_task_4(verbose=False):
    print(f"task 4  - {verbose}")

FUNCTIONS = {
    '1': test_task_1,
    '2': test_task_2,
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
                        nargs=0,
                        default=True,
                        action=None, 
                        help="Test Task 1" 
                    )

args = parser.parse_args(sys.argv[1:])

for test in args['tasks']:
    test(args['verbose'])
