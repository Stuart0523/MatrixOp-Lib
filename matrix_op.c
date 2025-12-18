#include "matrix_op.h"

void mat_elem_mul(double A[SIZE][SIZE], double B[SIZE][SIZE], double C[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = A[i][j] * B[i][j];
        }
    }
}

void mat_mul(double A[SIZE][SIZE], double B[SIZE][SIZE], double C[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void mat_transpose(double A[SIZE][SIZE], double T[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            T[j][i] = A[i][j];
        }
    }
}
double mat_det(double A[SIZE][SIZE]) {
    return
        A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1])
      - A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0])
      + A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);
}

void mat_adj(double A[SIZE][SIZE], double adj[SIZE][SIZE]) {
    // Cofactor matrix (not transposed yet)
    double c00 =  (A[1][1]*A[2][2] - A[1][2]*A[2][1]);
    double c01 = -(A[1][0]*A[2][2] - A[1][2]*A[2][0]);
    double c02 =  (A[1][0]*A[2][1] - A[1][1]*A[2][0]);

    double c10 = -(A[0][1]*A[2][2] - A[0][2]*A[2][1]);
    double c11 =  (A[0][0]*A[2][2] - A[0][2]*A[2][0]);
    double c12 = -(A[0][0]*A[2][1] - A[0][1]*A[2][0]);

    double c20 =  (A[0][1]*A[1][2] - A[0][2]*A[1][1]);
    double c21 = -(A[0][0]*A[1][2] - A[0][2]*A[1][0]);
    double c22 =  (A[0][0]*A[1][1] - A[0][1]*A[1][0]);

    // adj(A) = transpose(cofactor(A))
    adj[0][0] = c00; adj[0][1] = c10; adj[0][2] = c20;
    adj[1][0] = c01; adj[1][1] = c11; adj[1][2] = c21;
    adj[2][0] = c02; adj[2][1] = c12; adj[2][2] = c22;
}
