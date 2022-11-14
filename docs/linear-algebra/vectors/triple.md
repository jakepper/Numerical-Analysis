# Triple Vector Product

**Routine Name:** triple

**Author:** Jake Epperson

**Language:** Python

**Description/Purpose:** Computes the product of three vectors u, v, and w.

Important: Only works for vectors $u,v,w \epsilon R^3$

**Inputs:**

- u : numpy array of size 3 (vector)
- v : numpy array of size 3 (vector)
- w : numpy array of size 3 (vector)

**Output:** u x v x w : numpy array (vector)

**Usage/Example:**
 
    u = np.array([2, 3, 4])
    v = np.array([5, 6, 7])
    print(vectors.cross(u, v, u))

Output:

    [33. 6. -21.]

**Implementation/Code:** [vectors.py](../../../src/linear_algebra/vectors.py)