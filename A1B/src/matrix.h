#ifndef MATRIX_H
#define MATRIX_H

//allocate a memory space for n1*n2 matrix;
double **malloc_matrix(int n1, int n2);

//free the memory space for the matrix;
void free_matrix (int n1, int n2, double **a);

//fill the matrix with random number;
void fill_matrix(int n1, int n2, double **a); 

//print the matrix;
void print_matrix(int n1, int n2, double **a); 

//multiply the matrix a and b;
int matrix_multiply(int n1, int n2, int n3, double **a, double **b, double **c);
#endif