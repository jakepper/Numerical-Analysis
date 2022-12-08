# Kronecker Product

**Routine Name:** 

serial: m_kronecker_s

parallel: m_kronecker_p

**Author:** Jake Epperson

**Language:** C

**Description/Purpose:** Computes the Kronecker product of matrices A and B

**Inputs:**

- m1 : int - rows
- n1 : int - columns
- A : float[m1][n1]
- m2 : int - rows
- n2 : int - columns
- B : float[m2][n2]
- result : float[m1][n1][m2][n2]

**Output:** A kronecker B : stored in `result`

**Usage/Example:**

Output:
```
```

**Implementation/Code:** [matrices.c](../../../../src/linear_algebra/C/matrices.c)