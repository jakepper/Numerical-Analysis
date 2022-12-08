float norm(int, float[]);

void v_add(float[], float[], int, float[]);

void v_sub(float[], float[], int, float[]);

void v_mult_s(float[], float, int, float[]);
void v_mult_p(float[], float, int, float[]);

float dot(float[], float[], int);

void cross(float[], float[], int, float[]);

void triple(float[], float[], float[], int, float[]);

void v_hadamard_s(float[], float[], int, float[]);

void v_hadamard_p(float[], float[], int, float[]);

void v_outer_s(float[], float[], int n, float[n][n]);

void v_outer_p(float[], float[], int n, float[n][n]);