import sys
import numpy as np

TOLERANCE = 0.00001
MAX_ITERATIONS = 25

def f(x):
    return 10.14 * np.e**(x**2) * np.cos(np.pi/x)

def f_prime(x):
    return ((1014 * np.cos(np.pi/x) * x**3) + (507 * np.pi * np.sin(np.pi/x))) * (np.e**(x**2)) / (50 * x**2)

def g(x):
    return x - (f(x) / f_prime(x))

def bisect(a, b, iterations, data):
    i = 0
    while (i < iterations):
        fa = f(a)
        fb = f(b)
        if (a < b) and (fa * fb < 0):
            m = (a + b) / 2 # let m represent the midpoint between a and b
            fm = f(m)
            error = np.abs(fm)
            data['iterations'].append('   {:^18d}{:^18.4e}{:^18e}{:^18s}'.format(i + 1, m, error, 'bisection'))
            if np.abs(fm) < TOLERANCE:
                data['root'] = m
                break
            elif fa * fm < 0:
                b = m
            else:
                a = m
            data['root'] = m
        i += 1
    return a,b,data['root']

def bisect_newtons(a, b):
    data = {
        'root': (a + b) / 2,
        'iterations': []
    }
    data['iterations'].append('   {:^18s}{:^18s}{:^18s}{:^18s}'.format('Iteration', '~Root', 'Error', 'Type'))

    error = 10 * TOLERANCE
    prev_error = error * 10
    i = 0
    x0 = data['root'] # initialize x0 to midpoint of bounds (a, b)
    while (error > TOLERANCE) and (i < MAX_ITERATIONS):
        x1 = g(x0)
        error = np.abs(x1 - x0)
        data['iterations'].append('   {:^18d}{:^18.4e}{:^18e}{:^18s}'.format(i + 1, x1, error, 'newton'))
        if (x1 <= a) or (x1 >= b) or (error > prev_error): # newtons method is diverging
            # perform k iterations of bisection
            k = np.abs(int((-1 * ((np.log10(TOLERANCE) / np.log10(np.abs(b - a))) / np.log10(2))) + 1))
            a,b,x0 = bisect(a, b, k, data) # bisect and update bounds
        else: # newtons method is converging
            x0 = x1
            data['root'] = x1
        prev_error = error
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

# Output - Task 4
# intervals = [-16, -1, 15]
intervals = [0.1, 0.11, 0.125, 0.14, 0.17, 0.21, 0.26, 0.31, 0.6, 1, 2.8] # testing on 10 roots

i = 0
while i < len(intervals) - 1:
    print(f'Interval: ({intervals[i]}, {intervals[i + 1]})')
    data = bisect_newtons(intervals[i], intervals[i + 1])
    if root_check(data['root']):
        print('\n\tApproximate Root: {:f}'.format(data['root']))
        if tabular:
            print()
            for line in data['iterations']:
                print(line)
        print()
    i += 1
