import numpy as np

def add(u, v):
    if u.shape != v.shape:
        print("ERROR: vector lengths don't match\n")
        return None
    
    n = u.shape[0]
    result = np.zeros(n)
    for i in range(n):
        result[i] = u[i] + v[i]
    return result

def sub(u, v):
    if u.shape != v.shape:
        print("ERROR: vector lengths don't match\n")
        return None
    
    n = u.shape[0]
    result = np.zeros(n)
    for i in range(n):
        result[i] = u[i] - v[i]
    return result

def mult(c, v):
    n = v.shape[0]
    result = np.zeros(n)
    for i in range(n):
        result[i] = c * v[i]
    return result

def norm(v, p=2):
    sum = 0.0
    for i in range(v.shape[0]):
        sum += np.abs(v[i]) ** p
    return np.power(sum, 1 / p)

def dot(u, v):
    if u.shape != v.shape:
        print("ERROR: vector lengths don't match\n")
        return None

    n = u.shape[0]
    result = 0
    for i in range(n):
        result += u[i] * v[i]
    return result

def cross(u, v):
    if u.shape[0] != 3 and v.shape[0] != 3:
        print("ERROR: Vectors u, v must be in R^3\n")
        return None
    
    result = np.zeros(3)
    result[0] = (u[1] * v[2]) - (u[2] * v[1])
    result[1] = (u[2] * v[0]) - (u[0] * v[2])
    result[2] = (u[0] * v[1]) - (u[1] * v[0])
    return result

def triple(u, v, w):
    return cross(u, cross(v, w))