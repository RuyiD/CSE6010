#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "matrix.h"

//allocate memory space for a n1*n2 matrix
double **malloc_matrix(int n1, int n2){
	//define an index for iteration;
	int index = 0; 
	//allocate memory space for n1 pointers which points at n2 pointers;
	double** Matrix = (double**)malloc(n1 * sizeof(double*)); 
	//Trasver the Matrix sequence, allocate the memory space for each row;
	for(index = 0; index < n1; ++index){
		//allocate memory space for each row;
		Matrix[index] = (double *)malloc(n2 * sizeof(double)); 
		//if there are no space for a row, return NULL;
		if(Matrix[index] == NULL)
			return NULL;
	}
	return Matrix;
}


//free the matrix memory space;
void free_matrix(int n1, int n2, double **a){
	int index;
	//free the space of each row;
	for(index = 0; index < n1; ++index){
		free(a[index]);
	}
	//free the head pointer;
	free(a);
}


//fill the matrix with random number (0.0, 10.0)
void fill_matrix(int n1, int n2, double **a){
	int i, j;
	//the seed should be select in the main function 
	for(i = 0; i < n1; ++i){
		for(j = 0; j < n2; ++j){
			a[i][j] = rand() % 100 / (double)10;
		}
	}
}


//print the matrix
void print_matrix(int n1, int n2, double **a){
	int i, j;
	for(i = 0; i < n1; ++i){
		for(j = 0; j < n2; ++j){
			//print and keep one decimal;
			printf("%.1f ", a[i][j]);
		}
		printf("\n");
	}
}


//multiply the matrix
int matrix_multiply(int n1, int n2, int n3, double **a, double **b, double **c){
	int i, j, k;
	double sum = 0;
	if(n1 < 0 || n2 < 0 || n3 < 0 || a == NULL || b == NULL || c == NULL)
		return 0;
	//multiply, the time complexity of this algorithm is O(n^3);
	for(i = 0; i < n1; ++i){
		for(k = 0; k < n3; ++k){
			for(j = 0; j < n2; ++j){
				sum += a[i][j] * b[j][k];
			}
			c[i][k] = sum;
			//reset sum;
			sum = 0;
		}
	}
	return 1;
}