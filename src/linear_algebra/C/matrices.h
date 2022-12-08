void action_s(int m, int n, float[m][n], float[], float[]);
void action_p(int m, int n, float[m][n], float[], float[]);

void m_add(int m, int n, float[m][n], float[m][n], float[m][n]);
void m_sub(int m, int n, float[m][n], float[m][n], float[m][n]);

void m_product_s(int m1, int n1, float[m1][n1], int m2, int n2, float[m2][n2], float[m1][n2]);
void m_product_p(int m1, int n1, float[m1][n1], int m2, int n2, float[m2][n2], float[m1][n2]);

void m_hadamard_s(int m, int n, float[m][n], float[m][n], float[m][n]);
void m_hadamard_p(int m, int n, float[m][n], float[m][n], float[m][n]);

void kronecker_s(int m1, int n1, float[m1][n1], int m2, int n2, float[m2][n2], float[m1][n1][m2][n2]);
void kronecker_p(int m1, int n1, float[m1][n1], int m2, int n2, float[m2][n2], float[m1][n1][m2][n2]);

float power_method_s(int m, int n, float[m][n], int, float[n]);
float power_method_p(int m, int n, float[m][n], int, float[n]);

void jacobi(int n, float[n][n], float[n], float[n], float[n][n], int);