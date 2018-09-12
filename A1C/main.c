#include "./src/LList.h"
#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	/* test code of LList */
	int i, count;
	double key;
	double *Key;
	int *data;
	PrioQ *Test, *temp;
	srand(time(0));
	Test = PQ_create();
	data = (int *)malloc(20 * sizeof(int));
	for(i = 0; i < 20; ++i){
		key = rand();
		data[i] = i;
		PQ_insert(Test, key, &data[i]);
	}
	//remember first element is Test -> next;
	temp = Test -> next;
	for(i = 0; i < 20; ++i){
		printf("[%d] the key is %1f, the data is %d;\n", i, temp -> key, *((int*)temp -> data));
		temp = temp -> next;
	}
	// test the queue counter;
	count = PQ_count(Test);
	printf("the length of the queue is: %d.\n", count);
	//delete the element one after another;
	Key = (double *)malloc(sizeof(double));
	for(i =0; i < 20; ++i){
		PQ_delete(Test, Key);
		printf("[%d] the key deleted is %1f\n", i, *Key);
	}
	// test the queue counter;
	count = PQ_count(Test);
	printf("the length of the queue is: %d.\n", count);
	//free the queue
	PQ_free(Test);
	return 0;
}