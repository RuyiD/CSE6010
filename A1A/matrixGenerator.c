#include <stdio.h>
#include <stdlib.h>
//add time as a seed of the random function;
#include <time.h>

//define the matrix size;
//generate a matrix with m rows and n columns; 
#define m 30
#define n 20
//p is the possibility of 1
#define p 0.01

//define a 2-dimensional matrix generating funciton;
void Generate_2D_Matrix(int *mat);


//define a function of modifing the matrix
void Modify_the_Random_Matrix(int *M, int *mat);


int main(){
	int i, j;
	//add time(0) as a random seed;
	srand(time(0));
	//allocate a memory space for the random matrix;
	int *mat = (int *)malloc(n * m * sizeof(int));
	Generate_2D_Matrix(mat);
	//print original matrix
	printf("the original matrix is:\n");
	for(i = 0; i < n; ++i){
		for(j = 0; j < m; ++j){
			printf(" %d", mat[i * m + j]);
		}
		printf("\n");
	}
	printf("\n");
	//allocate a memory space for output matrix;
	int *Mat = (int *)malloc(n * m * sizeof(int));
	Modify_the_Random_Matrix(mat, Mat);
	printf("the output matrix is:\n");
	//print output matrix
	for(i = 0; i < n; ++i){
		for(j = 0; j < m; ++j){
			printf(" %d", Mat[i * m + j]);
		}
		printf("\n");
	}
	return 0;
}


//Generate a 2-dimensional matrix
void Generate_2D_Matrix(int *mat){
	//define offset to simulate certain point of the matrix;
	int offset;
	//i, j are the serial number of M[i, j];
	int i, j;
	//Traverse every point in the matrix M[i, j];
	for(i = 0; i < n; ++i){
		for(j = 0; j < m; ++j){
			//mat[offset] correspond to M[i, j];
			offset = i * m + j;
			if(rand() % 100 < 100 * p){
				mat[offset] = 1;
			}
			else{
				mat[offset] = 0;
			}
		}
	}
}


//Modify the random matrix generated in the previous steps;
void Modify_the_Random_Matrix(int *M, int *mat){
	//i, j are the serial number of M[i, j];
	int i, j;
	//r, c are the serial number of mat[r, c];
	int r, c; 
	//initialize the answer matrix
	for (r = 0; r < n; ++r)
		for(c = 0; c < m; ++c)
			mat[r * m + c] = 0;
	
	//traversing the whole matrix
	//if M[i, j] is 1, the mat[r, *] and mat[*, c] is 1;
	for(i = 0; i < n; ++i){
		for(j = 0; j < m; ++j){
			if(M[i * m + j] == 1){
				r = i;
				for(c = 0; c < m; ++c)
					mat[r * m + c] = 1;
				c = j;
				for(r = 0; r < n; ++r)
					mat[r * m + c] = 1;
			}
		}
	}
}