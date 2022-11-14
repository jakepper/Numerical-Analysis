# Matrix Subtraction

**Routine Name:** sub

**Author:** Jake Epperson

**Language:** Python

**Description/Purpose:** Subtracts one matrix from another

**Inputs:**

- A : numpy array (matrix)
- B : numpy array (matrix)

**Output:** A - B : numpy array (matrix)

**Usage/Example:**
 
    A = np.array([[1, 2, 3], [1, 2, 3], [1, 2, 3]])
    B = np.array([[3, 2, 1], [3, 2, 1], [3, 2, 1]])
    print(matrices.sub(A, B))

Output:

    [[-2.  0.  2.]
    [-2.  0.  2.]
    [-2.  0.  2.]]

**Implementation/Code:** [matrices.py](../../../src/linear_algebra/matrices.py)