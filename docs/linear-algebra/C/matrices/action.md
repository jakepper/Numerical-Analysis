# Action of Matrix on Vector

**Routine Name:** action

**Author:** Jake Epperson

**Language:** Python

**Description/Purpose:** Computes the action of matrix A applied to vector b

**Inputs:**

- A : numpy array (matrix)
- b : numpy array (vector)

**Output:** A * b : numpy array (vector)

**Usage/Example:**
 
    A = np.array([[1, 2, 3], [1, 2, 3], [1, 2, 3]])
    b = np.array([2, 2, 2])
    print(matrices.action(A, b))

Output:

    [12. 12. 12.]

**Implementation/Code:** [matrices.py](../../../src/linear_algebra/matrices.py)