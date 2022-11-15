# Vector Normalization

**Routine Name:** dot

**Author:** Jake Epperson

**Language:** Python

**Description/Purpose:** Computes the p-norm of a vector using the following formula,

$ |v|_p = ( \sum |v_i|^p )^{1/p} $

**Inputs:**

- v : numpy array (vector)
- p : specifies norm to compute

**Output:** u $\cdot$ p-norm : number

**Usage/Example:**
 
    v = np.array([1, 2, 3])
    print(vectors.norm(v, 2))

Output:

    3.741657

**Implementation/Code:** [vectors.py](../../../src/linear_algebra/vectors.py)