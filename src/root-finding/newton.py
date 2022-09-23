import sys
import numpy as np

TOLERANCE = 0.00001
MAX_ITERATIONS = 25

def f(x):
    return x * (np.e**(-x))

def f_prime(x):
    return (1 - x) * (np.e**(-x))

def g(x):
    return x - (f(x) / f_prime(x))

def iterate(x0, g):
    data = {
        'root': None,
        'iterations': []
    }
    data['iterations'].append('   {:^18s}{:^18s}{:^18s}'.format('Iteration', '~Root', 'Error'))

    error = 10 * TOLERANCE
    i = 0
    while (error > TOLERANCE) and (i < MAX_ITERATIONS):
        x1 = g(x0)
        error = np.abs(x1 - x0)
        x0 = x1
        data['root'] = x0
        data['iterations'].append('   {:^18d}{:^18.4e}{:^18e}'.format(i + 1, x0, error))
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

# Output - Task 1
x0 = float(input('Enter x0: '))
data = iterate(x0, g)

root_check(data['root'])
print('\n\tApproximate Root: {:f}'.format(data['root']))
if tabular:
    print()
    for line in data['iterations']:
        print(line)
print()