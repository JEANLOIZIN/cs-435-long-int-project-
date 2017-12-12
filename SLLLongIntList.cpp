#include "SLLLongIntList.h"
#include "SLLNode.h"
#include <iomanip>

SLLLongIntList ::SLLLongIntList()
{
	startNode = NULL;
	lastNode = NULL;
}

//function to insert a new node with value v in the starting of the list
void SLLLongIntList ::insertFirst(int v)
{
	SLLNode *newNode = new SLLNode();
	newNode->data = v;
	newNode->next = NULL;
	//if last node is empty then start and last node will be one node and that will be this new node
	if(startNode == NULL)
	{
		startNode = newNode;
		lastNode = newNode;
	}
	else
	{
		newNode->next = startNode;
		startNode = newNode;
	}
}

//function to insert a new node with value v in the last of the list
void SLLLongIntList ::insertLast(int v)
{
	SLLNode *newNode = new SLLNode();
	newNode->data = v;
	newNode->next = NULL;
	if(startNode == NULL)
	{
		startNode = newNode;
		lastNode = newNode;
	}
	else
	{
		lastNode->next = newNode;
		lastNode = newNode;
	}
}

//function to Returns first Position of the list
void* SLLLongIntList ::first()
{
	return startNode;
}

//function to Returns last Position of the list
void* SLLLongIntList ::last()
{
	return lastNode;
}

//function to Determines if Position p is the first position of the list
bool SLLLongIntList ::isFirst(void *p)
{
	return startNode==p;
}

//function to Determines if Position p is the last position of the list
bool SLLLongIntList ::isLast(void *p)
{
	return lastNode==p;
}

//function to Returns Boolean value indicating if the list has no nodes
bool SLLLongIntList ::isEmpty()
{
	return startNode==NULL;
}

//function to Returns the Position before Position p (error if p is first position)
void *SLLLongIntList ::before(void *p)
{
	SLLNode* temp = startNode;

	while( temp->next != NULL )
	{
		if(temp->next == p)
		{
			return temp;
		}

		temp = temp->next;
	}

	return NULL;
}

//function to get the node after the given node
void *SLLLongIntList ::after(void *p)
{
	SLLNode* temp = startNode;

	while( temp->next != NULL )
	{
		if(temp == p)
		{
			return temp->next;
		}

		temp = temp->next;
	}

	return NULL;
}

//function to get the total number of node from the linked list
int SLLLongIntList ::size()
{
	int count = 0;
	SLLNode *temp = startNode;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}

	return count;
}
