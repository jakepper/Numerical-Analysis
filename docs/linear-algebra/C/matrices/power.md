# Power Method

**Routine Name:** 

serial: power_method_s

parallel: power_method_p

**Author:** Jake Epperson

**Language:** C

**Description/Purpose:** Uses the power method to approximate the max eigenvalue corresponding to the matrix A

**Inputs:**

- m : int - rows
- n : int - columns
- A : float[m][n]
- max_iters : int
- approx : float[m] - initial eigenvector approximation

**Output:** 

- eigenvector : stored in `approx`

- eigenvalue : returned

**Usage/Example:**

Output:
```
```

**Implementation/Code:** [matrices.c](../../../../src/linear_algebra/C/matrices.c)