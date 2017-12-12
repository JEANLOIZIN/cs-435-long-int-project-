#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdlib.h>
#include "SLLNode.h"
#include "LongIntList.h"

using namespace std;

class SLLLongIntList : public LongIntList
{
private:
	SLLNode *startNode;
	SLLNode *lastNode;

public:
	SLLLongIntList ();

	//Adds a new node with value v at front of the list
	void insertFirst(int v);

	//Adds a new node with value v at the end of the list
	void insertLast(int v);

	//Returns first Position of the list
	void* first();

	//Returns last Position of the list
	void *last();

	//Determines if Position p is the first position of the list
	bool isFirst(void *p);

	//Determines if Position p is the last position of the list
	bool isLast(void *p);

	//Returns the Position before Position p (error if p is first position)
	void *before(void *p);

	//Returns the Position after Position p (error if p is the last position)
	void *after(void *p);

	//Returns Boolean value indicating if the list has no nodes
	bool isEmpty();

	//Returns the size of the list
	int size();

};

