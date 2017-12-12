#include <iostream>
#include <string>
#include <stdlib.h>
#include "CommonUtilFunctions.h"
#include "SLLLongIntList.h"
#include "SLLNode.h"
#include <sstream>
#include <iomanip>
using namespace std;

class LongInt
{

private:
	int totalDigits;
	bool isPositive;
	CommonUtilFunctions commonFunctions;
	LongInt add(SLLLongIntList  l1, SLLLongIntList  l2);
	LongInt subtract(SLLLongIntList  l1, SLLLongIntList  l2);
	LongInt multiply(SLLLongIntList  l1, SLLLongIntList  l2);
	LongInt Karatsuba(int c1, int c2, int d1,int d2);
	LongInt powerBySquaring(LongInt x, int n);

public:
	SLLLongIntList longIntList;
	
	LongInt(){}

	//parameterised constructor
	LongInt(string s);

	// get the output 
	void output();

	//get sign of the value
	char getSign();

	//set sign to the value
	void setSign(char c);

	//get the digit count of the value
	int getDigitCount();

	//determine the value  equalTo or not
	bool equalTo(LongInt i);

	//determine the value is lessThan or not
	bool lessThan(LongInt i);

	//determine the value is greaterThan or not
	bool greaterThan(LongInt i);

	LongInt add(LongInt l);

	LongInt subtract(LongInt l);

	LongInt multiply(LongInt l);

	LongInt power(int l);

};

