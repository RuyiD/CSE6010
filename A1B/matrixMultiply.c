#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "./src/matrix.h"

int main(int argc, char const *argv[])
{
	int n1 = 4;
	int n2 = 3;
	int n3 = 5;
	//select a random seed;
	srand((unsigned)time(NULL));
	
	double **matrix1 = malloc_matrix(n1, n2);
	double **matrix2 = malloc_matrix(n2, n3);
	double **matrix3 = malloc_matrix(n1, n3);
	
	fill_matrix(n1, n2, matrix1);
	fill_matrix(n2, n3, matrix2);
	
	printf("The input Matrix 1 is:\n");
	print_matrix(n1, n2, matrix1);
	printf("\n");
	printf("The input Matrix 2 is:\n");
	print_matrix(n2, n3, matrix2);
	printf("\n");
	//multiply the matrix
	if(!matrix_multiply(n1, n2, n3, matrix1, matrix2, matrix3))
		printf("There are some errors!");
	else{
		printf("The output Matrix is:\n");
		print_matrix(n1, n3, matrix3);
	}
	
	free_matrix(n1,n2,matrix1);
	free_matrix(n2,n3,matrix2);
	free_matrix(n1,n3,matrix3);
	return 0;
}
