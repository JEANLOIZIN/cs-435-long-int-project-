#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "SLLNode.h"

using namespace std;

class CommonUtilFunctions
{
public:
	CommonUtilFunctions(){}
	int CountDigitsinNumber(int n);
	int getTotalDigits(SLLNode *startNode);
	string convertNumberToString(int i, bool fill0s = false, int nof0s = 8);
	string getAllDigits(SLLNode *startNode);
	//methods to append 0s in the last
	string append(string v, int n){
		for(int i =0; i < n ;i++){
			v = v + "0";
		}
		return v;
	}

	int overflow(int t) 
	{
		int size = t / 100000000;	
		return size;
	}

	int underflow(int t) {
		int rem = t % 100000000;
		return rem;
	}

	int upperHalf(int t) {
		return t / 10000;
	}

	int lowerHalf(int t) {
		return t % 10000;
	}
};

