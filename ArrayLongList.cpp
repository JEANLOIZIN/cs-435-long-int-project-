#include "ArrayLongList.h"

ArrayLongList::ArrayLongList(void)
{
	numberofNodes = 0;
}


//Adds a new node with value v at front of the list
void ArrayLongList::insertFirst(int v)
{
	SLLNode node;
	node.data = v;
	for(int i = 0; i < numberofNodes;i++)
		nodes[numberofNodes - i] = nodes[numberofNodes - i - 1];
	nodes[0] = node;
	numberofNodes = numberofNodes + 1;
}

//Adds a new node with value v at the end of the list
void ArrayLongList::insertLast(int v)
{
	SLLNode node;
	node.data = v;
	nodes[numberofNodes] = node;
	numberofNodes = numberofNodes + 1;
}

//Returns first Position of the list
void* ArrayLongList::first()
{
	if(isEmpty())
		return NULL;
	else
		return &nodes[0];
}

//Returns last Position of the list
void *ArrayLongList::last()
{
	if(isEmpty())
		return NULL;
	else
		return &nodes[numberofNodes-1];
}

//Determines if Position p is the first position of the list
bool ArrayLongList::isFirst(void *p)
{
	if(isEmpty())
		return false;
	else
	{
		if((SLLNode *)p == &nodes[0])
			return true;
		else
			return false;
	}
}

//Determines if Position p is the last position of the list
bool ArrayLongList::isLast(void *p)
{
	if(isEmpty())
		return false;
	else
	{
		if((SLLNode *)p == &nodes[numberofNodes-1])
			return true;
		else
			return false;
	}
}

//Returns the Position before Position p (error if p is first position)
void * ArrayLongList::before(void *p)
{
	for(int i =0 ; i < numberofNodes ; i++)
	{
		if((SLLNode *)p == &nodes[i])
		{
			if(i == 0)
				return NULL;
			else
				return &nodes[i-1];
		}
	}

	return NULL;
}

//Returns the Position after Position p (error if p is the last position)
void *ArrayLongList::after(void *p)
{
	for(int i =0 ; i < numberofNodes ; i++)
	{
		if((SLLNode *)p == &nodes[i])
		{
			if(i == numberofNodes-1)
				return NULL;
			else
				return &nodes[i+1];
		}
	}

	return NULL;
}

//Returns Boolean value indicating if the list has no nodes
bool ArrayLongList::isEmpty()
{
	if(numberofNodes == 0)
		return true;
	else
		return false;
}

//Returns the size of the list
int ArrayLongList::size()
{
	return numberofNodes;
}

