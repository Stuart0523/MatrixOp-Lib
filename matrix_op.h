#ifndef MATRIX_OP_H
#define MATRIX_OP_H

#define SIZE 3

void mat_add(double A[SIZE][SIZE], double B[SIZE][SIZE], double C[SIZE][SIZE]);
void mat_sub(double A[SIZE][SIZE], double B[SIZE][SIZE], double C[SIZE][SIZE]);
void mat_elem_mul(double A[SIZE][SIZE], double B[SIZE][SIZE], double C[SIZE][SIZE]);


void mat_mul(double A[SIZE][SIZE], double B[SIZE][SIZE], double C[SIZE][SIZE]);
void mat_transpose(double A[SIZE][SIZE], double T[SIZE][SIZE]);

double mat_det(double A[SIZE][SIZE]);
void mat_adj(double A[SIZE][SIZE], double adj[SIZE][SIZE]);
int mat_inverse(double A[SIZE][SIZE], double inv[SIZE][SIZE]);

#endif
