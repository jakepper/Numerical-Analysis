import sys
import numpy as np

TOLERANCE = 0.00001
MAX_ITERATIONS = 25

def f(x):
    return x * (np.e**(-x))

def g(x0, x1):
    fx1 = f(x1)
    return x1 - ((x0 - x1) / (f(x0) - fx1)) * fx1

def iterate(x0, x1):
    data = {
        'root': None,
        'iterations': []
    }
    data['iterations'].append('   {:^18s}{:^18s}{:^18s}'.format('Iteration', '~Root', 'Error'))

    error = 10 * TOLERANCE
    i = 0
    while (error > TOLERANCE) and (i < MAX_ITERATIONS):
        x2 = g(x0, x1)
        error = np.abs(f(x2))
        x0 = x1
        x1 = x2
        data['root'] = x2
        data['iterations'].append('   {:^18d}{:^18.4e}{:^18e}'.format(i + 1, x2, error))
        i += 1
    return data

def root_check(root):
    if root == None:
        print('ERROR: Could not find approximate root')
        return False
    return True

# Tabulation - Task 3
tabular = False
if len(sys.argv) > 1:
    if sys.argv[1] == '-v':
        tabular = True

# Output - Task 2
x0 = float(input('Lower Bound (x0): '))
x1 = float(input('Upper Bound (x1): '))
data = iterate(x0, x1)

root_check(data['root'])
print('\n\tApproximate Root: {:f}'.format(data['root']))
if tabular:
    print()
    for line in data['iterations']:
        print(line)
print()