# Shifted Inverse Power Method

**Routine Name**

serial: inverse_power_shift

parallel: inverse_power_shift_p

**Author:** Jake Epperson

**Language:** C

**Description/Purpose:** Uses the shifted inverse power method to approximate an eigenvalue corresponding to the matrix A and its corresponding eigenvector

**Inputs:**

- n : int - rows/cols
- A : double[m][n]
- approx : double[m] - initial eigenvector approximation
- shift : double - approximate eigenvalue
- max_iters : int

**Output:** 

- eigenvector : stored in `approx`

- eigenvalue : returned

**Usage/Example:**

Output:
```
```

**Implementation/Code:** [matrices.c](../../../../src/linear_algebra/C/matrices.c)