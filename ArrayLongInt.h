#include <iostream>
#include <string>
#include <stdlib.h>
#include "CommonUtilFunctions.h"
#include "ArrayLongList.h"
#include "SLLNode.h"
#include <sstream>
#include <iomanip>

using namespace std;

class ArrayLongInt
{

private:
	int totalDigits;
	bool isPositive;
	CommonUtilFunctions *commonFunctions;
	ArrayLongInt add(ArrayLongList *l1, ArrayLongList *l2);
	ArrayLongInt subtract(ArrayLongList *l1, ArrayLongList *l2);
	ArrayLongInt multiply(ArrayLongList *l1, ArrayLongList *l2);
	ArrayLongInt Karatsuba(int c1, int c2, int d1,int d2);
	ArrayLongInt powerBySquaring(ArrayLongInt x, int n);

public:
	ArrayLongList *longIntList;
	
	ArrayLongInt()
	{
		longIntList = new ArrayLongList();
	}

	//parameterised constructor
	ArrayLongInt(string s);

	// get the output 
	void output();

	//get sign of the value
	char getSign();

	//set sign to the value
	void setSign(char c);

	//get the digit count of the value
	int getDigitCount();

	//determine the value  equalTo or not
	bool equalTo(ArrayLongInt i);

	//determine the value is lessThan or not
	bool lessThan(ArrayLongInt i);

	//determine the value is greaterThan or not
	bool greaterThan(ArrayLongInt i);

	ArrayLongInt add(ArrayLongInt l);

	ArrayLongInt subtract(ArrayLongInt l);

	ArrayLongInt multiply(ArrayLongInt l);

	ArrayLongInt power(int l);

};

