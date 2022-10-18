import sys
import numpy as np

MAX_ITERATIONS = 25
TOLERANCE = 0.000001

# Task 1
print('\nFunctional Iteration with f(x) = x * e^(-x)\n')

def f_1(x):
    return x * (np.e**(-x))

def g1_1(x):
    return x - f_1(x)

def g2_1(x):
    return x + f_1(x)

def iterate(x0, g):
    data = {
        'root': None,
        'iterations': []
    }
    data['iterations'].append('   {:^18s}{:^18s}{:^18s}'.format('Iterations', '~Root', 'Error'))

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

# Task 2
# Use command line argument '-v' for tabular results
tabular = False
if len(sys.argv) > 1:
    if sys.argv[1] == '-v':
        tabular = True

# Output - Task 1
x0 = float(input('Enter x0: '))
g1_data = iterate(x0, g1_1)
g2_data = iterate(x0, g2_1)

root_check(g1_data['root'])
print('\n\tg1->[x - f(x)] Approximate Root: {:f}'.format(g1_data['root']))
if tabular:
    print()
    for line in g1_data['iterations']:
        print(line)
print()

root_check(g2_data['root'])
print('\tg2->[x + f(x)] Approximate Root: {:f}'.format(g2_data['root']))
if tabular:
    print()
    for line in g2_data['iterations']:
        print(line)
print()

# Task 3
print('\nFunctional Iteration with f(x) = 10.14 * e^(x^2) * cos(\u03C0/x)\n')

def f_3(x):
    return 10.14 * (np.e**(x**2)) * np.cos(np.pi / x)

def g1_3(x):
    return x - f_3(x)

def g2_3(x):
    return x + f_3(x)

# Output - Task 3
test_x0 = [-2.5, 1, 2.0, 5.0, 0.666, 0.668]

for x0 in test_x0:
    g1_data = iterate(x0, g1_3)
    g2_data = iterate(x0, g2_3)
    print(f'Testing x0 = {x0}\n')
    print('\tg1->[x - f(x)] Approximate Root: {:f}'.format(g1_data['root']))
    if tabular:
        print()
        for line in g1_data['iterations']:
            print(line)
    print()
    print('\tg2->[x + f(x)] Approximate Root: {:f}'.format(g2_data['root']))
    if tabular:
        print()
        for line in g1_data['iterations']:
            print(line)
    print()