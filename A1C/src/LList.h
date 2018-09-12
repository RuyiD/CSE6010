#ifndef LLIST_H
#define LLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Llist PrioQ;

struct Llist
{
	//the key of a Node
	double key;
	//the pointer to the next element;
	PrioQ *next;
	//A void pointer to the data
	void* data;
};

//operations of PrioQ
//initialize the PrioQ
PrioQ *PQ_create(); 
//inserta element
int PQ_insert(PrioQ *PQ, double key, void *data); 
//delete element
void *PQ_delete(PrioQ *PQ, double *key); 
//count the num of elements
unsigned int PQ_count(PrioQ *PQ); 
//release the space of PrioQ
void *PQ_free(PrioQ *PQ); 

#endif