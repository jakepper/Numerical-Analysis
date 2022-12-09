void action_s(int m, int n, double[m][n], double[], double[]);
void action_p(int m, int n, double[m][n], double[], double[]);

void m_add(int m, int n, double[m][n], double[m][n], double[m][n]);
void m_sub(int m, int n, double[m][n], double[m][n], double[m][n]);

void m_product_s(int m1, int n1, double[m1][n1], int m2, int n2, double[m2][n2], double[m1][n2]);
void m_product_p(int m1, int n1, double[m1][n1], int m2, int n2, double[m2][n2], double[m1][n2]);

void m_hadamard_s(int m, int n, double[m][n], double[m][n], double[m][n]);
void m_hadamard_p(int m, int n, double[m][n], double[m][n], double[m][n]);

void kronecker_s(int m1, int n1, double[m1][n1], int m2, int n2, double[m2][n2], double[m1][n1][m2][n2]);
void kronecker_p(int m1, int n1, double[m1][n1], int m2, int n2, double[m2][n2], double[m1][n1][m2][n2]);

double power_method_s(int m, int n, double[m][n], int, double[n]);
double power_method_p(int m, int n, double[m][n], int, double[n]);

void jacobi(int n, double[n][n], double[n], double[n], double[n][n], int);