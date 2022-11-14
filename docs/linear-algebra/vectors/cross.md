# Vector Cross Product

**Routine Name:** cross

**Author:** Jake Epperson

**Language:** Python

**Description/Purpose:** Computes the cross product of two vectors

Important: Only works for vectors $u,v \epsilon R^3$

**Inputs:**

- u : numpy array of size 3 (vector)
- v : numpy array of size 3 (vector)

**Output:** u x v : numpy array (vector)

**Usage/Example:**
 
    u = np.array([2, 3, 4])
    v = np.array([5, 6, 7])
    print(vectors.cross(u, v))

Output:

    [-3. 6. -3.]

**Implementation/Code:** [vectors.py](../../../src/linear_algebra/vectors.py)