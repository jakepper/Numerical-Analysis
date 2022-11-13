import numpy as np

def add(A, B):
    if A.shape != B.shape:
        print("ERROR: matrices must have same shape")
        return None

    result = np.zeros(A.shape)
    m, n = A.shape
    for i in range(m):
        for j in range(n):
            result[i][j] = A[i][j] + B[i][j]
    return result

def sub(A, B):
    if A.shape != B.shape:
        print("ERROR: matrices must have same shape")
        return None

    result = np.zeros(A.shape)
    m, n = A.shape
    for i in range(m):
        for j in range(n):
            result[i][j] = A[i][j] - B[i][j]
    return result

def mult(A, B):
    if A.shape[1] != B.shape[0]:
        print("ERROR: number of columns in matrix A do not match number of rows in matrix B")
        return None

    result = np.zeros(A.shape)
    m, n = A.shape
    for i in range(m):
        for j in range(n):
            result[i][j] = A[i][j] * B[i][j]
    return result

def action(A, b):
    if A.shape[1] != b.shape[0]:
        print("ERROR: number of columns in matrix do not match vector size")
        return None

    m, n = A.shape
    result = np.zeros(n)
    for i in range(m):
        sum = 0
        for j in range(n):
            sum += A[i][j] * b[j]
        result[i] = sum
    return result