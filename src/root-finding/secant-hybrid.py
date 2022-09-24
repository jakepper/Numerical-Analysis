import sys
import numpy as np

TOLERANCE = 0.00001
MAX_ITERATIONS = 25

def f(x):
    return x * (np.e**(-x))

def g(x0, x1):
    fx1 = f(x1)
    return x1 - ((x0 - x1) / (f(x0) - fx1)) * fx1

def bisect(a, b, f, iterations, data):
    i = 0
    while (i < iterations):
        fa = f(a)
        fb = f(b)
        if (a < b) and (fa * fb < 0):
            m = (a + b) / 2 # let m represent the midpoint between a and b
            fm = f(m)
            error = np.abs(fm)
            data['iterations'].append('   {:^18d}{:^18.4e}{:^18e}{:^18s}'.format(i + 1, m, error, 'bisection'))
            if fa * fm < 0:
                b = m
            else:
                a = m
            data['root'] = m
        else:
            break
        i += 1
    return a,b

def bisect_secant(a, b, g):
    data = {
        'root': None,
        'iterations': []
    }
    data['iterations'].append('   {:^18s}{:^18s}{:^18s}{:^18s}'.format('Iteration', '~Root', 'Error', 'Type'))

    error = 10 * TOLERANCE
    i = 0
    while (error > TOLERANCE) and (i < MAX_ITERATIONS):
        x = g(a, b)
        error = np.abs(f(x))
        if (x <= a) or (x >= b): # secant method is diverging
            # perform k iterations of bisection
            k = np.abs(int((-1 * ((np.log10(TOLERANCE) / np.log10(np.abs(b - a))) / np.log10(2))) + 1))
            a,b = bisect(a, b, f, k, data)
        else: # secant method is converging
            a = b
            b = x
            data['root'] = x
            data['iterations'].append('   {:^18d}{:^18.4e}{:^18e}{:^18s}'.format(i + 1, x, error, 'secant'))
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
a = float(input('Lower Bound: '))
b = float(input('Upper Bound: '))
data = bisect_secant(a, b, g)

root_check(data['root'])
print('\n\tApproximate Root: {:f}'.format(data['root']))
if tabular:
    print()
    for line in data['iterations']:
        print(line)
print()