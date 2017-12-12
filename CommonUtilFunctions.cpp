#include "CommonUtilFunctions.h"

int CommonUtilFunctions::CountDigitsinNumber(int n)
{
	int count =0;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return count;
}

int CommonUtilFunctions::getTotalDigits(SLLNode *startNode)
{
	int count = 0;
	SLLNode *temp = startNode;
	while (temp != NULL)
	{
		if(temp == startNode)
		{
			count = count + CountDigitsinNumber(temp->data);
		}
		else
		{
			count = count + 8;
		}
		temp = temp->next;
	}

	return count;
}

string CommonUtilFunctions::convertNumberToString(int i, bool fill0s, int nof0s)
{
	//remove negative sign from number
	if(i < 0)
	{
		i = 0 - i;
	}

	stringstream ss;
	if(fill0s)
	{
		ss <<setfill('0') << std::setw(nof0s)<<i;
	}
	else
	{
			ss<<i;
	}
	return ss.str();
}


string CommonUtilFunctions::getAllDigits(SLLNode *startNode)
{	
	string val;
	SLLNode *temp = startNode;
	while (temp != NULL)
	{
		stringstream ss;
		if(temp == startNode)
		{
			ss<<temp->data;			
		}
		else
		{
			ss<<setfill('0') << std::setw(8)<<temp->data;
		}

		val = val + ss.str();
		temp = temp ->next;
	}
	return val;
}
