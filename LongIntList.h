#pragma once

class LongIntList
{
public:
	//Adds a new node with value v at front of the list
	virtual void insertFirst(int v) = 0;

	//Adds a new node with value v at the end of the list
	virtual void insertLast(int v) = 0;

	//Returns first Position of the list
	virtual void* first() = 0;

	//Returns last Position of the list
	virtual void *last() = 0;

	//Determines if Position p is the first position of the list
	virtual bool isFirst(void *p) = 0;

	//Determines if Position p is the last position of the list
	virtual bool isLast(void *p) = 0;

	//Returns the Position before Position p (error if p is first position)
	virtual void *before(void *p) = 0;

	//Returns the Position after Position p (error if p is the last position)
	virtual void *after(void *p) = 0;

	//Returns Boolean value indicating if the list has no nodes
	virtual bool isEmpty() = 0;

	//Returns the size of the list
	virtual int size() = 0;
};

