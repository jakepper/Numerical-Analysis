import sys
import numpy as np

TOLERANCE = 0.000001

def f1(x):
    return x * (np.e**(-x))

def f2(x): 
    return 10.14 * (np.e**(x**2)) * np.cos(np.pi / x)

def test_bounds(a, b):
    if a > b: 
        print('ERROR: Lower bound must be less than Upper bound')
        sys.exit()

def root_check(root):
    if root == None:
        print('ERROR: Could not find approximate root')
        return False
    return True

def bisect(a, b, f, iterations):
    data = {
        'root': None,
        'iterations': []
    }
    data['iterations'].append('{:^16s}{:^16s}{:^16s}{:^16s}{:^16s}{:^16s}{:^16s}'.format('Iteration','a','b','midpoint (m)','f(a)','f(b)','f(m)'))

    i = 0
    while (i < iterations):
        fa = f(a)
        fb = f(b)
        if (a < b) and (fa * fb < 0):
            m = (a + b) / 2 # let m represent the midpoint between a and b
            fm = f(m)
            data['iterations'].append('{:^16d}{:^16.4f}{:^16.4f}{:^16.4f}{:^16.4f}{:^16.4f}{:^16.4f}'.format(i + 1, a, b, m, fa, fb, fm))
            if np.abs(fm) < TOLERANCE:
                data['root'] = m
                break
            elif fa * fm < 0:
                b = m
            else:
                a = m
            data['root'] = m
        i += 1
    return data

tabular = False
if len(sys.argv) > 1:
    if sys.argv[1] == '-v':
        tabular = True


print('Bisection with f(x) = x * e^(-x)\n')
a = float(input('Lower Bound: '))
b = float(input('Upper Bound: '))
test_bounds(a, b)
iterations = np.abs(int(-((np.log10(TOLERANCE) / np.log10(b - a)) / np.log10(2)) + 1))
print(f'\nIterations: {iterations}')
data = bisect(a, b, f1, iterations)
if root_check(data['root']): print('Approximate Root: {:f}'.format(data['root']))
if tabular:
    for line in data['iterations']:
        print(line)
    print()

print('Bisection with f(x) = 10.14 * e^(x^2) * cos(\u03C0/x)\n')
a = float(input('Lower Bound: '))
b = float(input('Upper Bound: '))
test_bounds(a, b)
iterations = np.abs(int(-((np.log10(TOLERANCE) / np.log10(b - a)) / np.log10(2)) + 1))
print(f'\nIterations: {iterations}')
data = bisect(a, b, f2, iterations)
if root_check(data['root']): print('Approximate root: {:f}'.format(data['root']))
if tabular:
    for line in data['iterations']:
        print(line)
    print()