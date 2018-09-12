#include "LList.h"

//initialize the PrioQ
PrioQ *PQ_create(){
	//create head node;
	PrioQ *headNode = (PrioQ *)malloc(sizeof(PrioQ));
	headNode -> data = NULL;
	headNode -> next = NULL;	

	if(headNode == NULL)
		return NULL;

	return headNode;
}


//insert an element
int PQ_insert(PrioQ *PQ, double key, void *data){
	//build data into a node;
	PrioQ *thisNode = (PrioQ *)malloc(sizeof(PrioQ));
	//if there is no enough space, return NULL;
	if(thisNode == NULL)
		return 0; //how to return a NULL?
	thisNode -> data = data;
	thisNode -> key = key;

	//insert the node into PrioQ;
	PrioQ *temp;
	temp = PQ;
	while(temp -> next != NULL){
		if(thisNode -> key <= temp -> next -> key){
			//insert the node here;
			thisNode -> next = temp -> next;
			temp -> next = thisNode;
			return 1;
		}
		//check all nodes in the list;
		temp = temp -> next;
	}
	//if the function isn't return, insert the node in the tail of llist;
	temp -> next = thisNode;
	thisNode -> next = NULL;
	return 1;
}


//delete the first element;
void *PQ_delete(PrioQ *PQ, double *key){
	//if PQ is empty. return NULL;
	if(PQ -> next == NULL)
		return NULL;
	//return the data elements;float
	else{
		PrioQ *temp;
		temp = PQ -> next;
		//link the head node to the node next to the first node;
		PQ -> next = temp -> next;
		*key = temp -> key;
		return temp -> data;
	}
}

//count the num of elements
unsigned int PQ_count(PrioQ *PQ){
	int count = 0;
	PrioQ *temp;
	temp = PQ;
	while(temp -> next != NULL){
		//if the llist do not come to the end; find the next node;
		count ++;
		temp = temp -> next;
	}
	return count;
}

//release the space of PrioQ
void *PQ_free(PrioQ *PQ){
	PrioQ *temp;
	while(PQ -> next != NULL)
	{
		//use temp to locate the next element;
		temp = PQ -> next;
		//free previous element;
		free(PQ -> data);
		free(PQ);
		PQ = temp;
	}
	//when comes to the last element in the queue;
	free(PQ -> data);
	free(PQ);
	return NULL;
}