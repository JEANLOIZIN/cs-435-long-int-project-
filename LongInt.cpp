#include "LongInt.h"

LongInt::LongInt(string s)
{
	s.erase(0, s.find_first_not_of('0'));
	if(s=="")
	{
		longIntList.insertFirst(0);
		return;
	}
	isPositive = true;
	totalDigits = s.length();
	string val = "";
	for (int i = 1; i <= s.length(); i++)
	{
		val = s[totalDigits - i] + val;
		if(val.length() >=8)
		{	
			int number = atoi(val.c_str());
			longIntList.insertFirst(number);
			val = "";
		}
	}

	if(val != "")
	{
		int number = atoi(val.c_str());
		if(number != 0)
		{
			longIntList.insertFirst(number);
		}
		val = "";
	}
}

//function to get the output 
void LongInt::output()
{
	if(!isPositive)
		cout<<"-";
	SLLNode *node = (SLLNode *)longIntList.first();
	while (node != NULL)
	{
		if(longIntList.isFirst(node))
		{
			cout<<node->data;
		}
		else
		{
			cout<<commonFunctions.convertNumberToString(node->data,true,8);
		}

		node = node->next;
	}
}

//function to get the digit count of the value
int LongInt::getDigitCount()
{
	return totalDigits;
}

//function to get sign of the value
char LongInt::getSign()
{
	if(isPositive)
		return '+';

	return '-';
}

//function to set sign of the value
void LongInt::setSign(char c)
{
	//if sign is + then number is positive else number is negative
	isPositive = c=='+';
}

//function to  check value is equalTo or not
bool LongInt::equalTo(LongInt i)
{
	if(getDigitCount() != i.getDigitCount())
	{
		return false;
	}

	if(getSign() != i.getSign())
	{
		return false;
	}

	SLLNode *node = (SLLNode *)longIntList.first();
	SLLNode *snode =  (SLLNode *)i.longIntList.first();
	while (node != NULL)
	{
		if(node->data != snode->data)
		{
			return false;
		}

		snode = snode->next;
		node = node->next;
	}

	return true;
}

//function to check value is less than or not
bool LongInt::lessThan(LongInt num2)
{
	//if both number sign is same and digits not equal then we can decide whether it is less than or greater than
	if(getSign() == num2.getSign() && totalDigits != num2.totalDigits)
	{
		if(isPositive)
			return getDigitCount() < num2.getDigitCount();
		else
			return getDigitCount() > num2.getDigitCount();
	}

	if(getSign() != num2.getSign())
	{
		//if first number is negative then number is less then num2
		return getSign()=='-';
	}

	SLLNode *node = (SLLNode *)longIntList.first();
	SLLNode *snode =  (SLLNode *)num2.longIntList.first();
	while (node != NULL)
	{
		if(node==NULL || snode==NULL)
			break;

		if(node->data > snode->data)
		{
			return false;
		}

		snode = snode->next;
		node = node->next;
	}

	return true;
}


//function to check value is greater than or not
bool LongInt::greaterThan(LongInt num2)
{
	if(equalTo(num2))
	{
		return false;
	}
	else if(lessThan(num2))
	{
		return false;
	}
	else
	{
		return true;
	}
}

//Add the number into current number and return the number
LongInt LongInt::add(LongInt l)
{
		LongInt n1(*this);
	LongInt n2(l);

	//if sign is not equal then it will be subtraction
	if(getSign() != l.getSign())
	{
		if(isPositive)
		{
			n1.setSign('+');
			n2.setSign('+');
			return n1.subtract(n2);
		}
		else
		{
			n1.setSign('+');
			n2.setSign('+');
			return n2.subtract(n1);
		}
	}
	else
	{
		//sign are same then add the number and set the sign
		LongInt l2 = add(longIntList, l.longIntList);
		l2.setSign(getSign());
		return l2;
	}
}

//this performs the actual addition of two number. this will be called by addition or subtraction function based on condition
LongInt LongInt::add(SLLLongIntList  l1, SLLLongIntList  l2)
{
	LongInt result;
	//get the numbers from right to left
	SLLNode *node = (SLLNode *)l1.last();
	SLLNode *snode =  (SLLNode *)l2.last();
	int carry = 0;
	while (node != NULL)
	{
		if(node==NULL || snode==NULL)
			break;
		//do the addition and calculate the carry bit and actual 8 digit number
		int v = node->data + snode->data + carry;
		carry = commonFunctions.overflow(v);
		v = commonFunctions.underflow(v);
		result.longIntList.insertFirst(v);
		snode = (SLLNode*)l2.before(snode);
		node = (SLLNode*)l1.before(node);
	}

	//if more number remaining in first list the process them
	while (node != NULL)
	{
		int v = node->data + carry;
		carry = commonFunctions.overflow(v);
		v = commonFunctions.underflow(v);
		result.longIntList.insertFirst(v);
		node = (SLLNode*)l1.before(node);
	}
	//if more number remaining in second list the process them
	while (snode != NULL)
	{
		int v = snode->data + carry;
		carry = commonFunctions.overflow(v);
		v = commonFunctions.underflow(v);
		result.longIntList.insertFirst(v);
		snode = (SLLNode*)l2.before(snode);
	}

	if(carry > 0)
	{
		result.longIntList.insertFirst(carry);
	}

	return result;
}

//subtract the number from the current number
LongInt LongInt::subtract(LongInt l)
{
	//if sign is not equal then it will be addition of number
	if(getSign() != l.getSign())
	{
		LongInt l2 = add(longIntList, l.longIntList);
		if(l.getSign()=='-')
			l2.setSign('+');
		else
			l2.setSign('-');
		return l2;
	}

	//if number are equal then result will be 0
	if(equalTo(l))
	{
		return LongInt("0");
	}

	//find the greater number and put that as first argument so it become easy to subtract
	if((greaterThan(l)&& isPositive )|| lessThan(l) && !isPositive)
	{
		LongInt l2 = subtract(longIntList, l.longIntList);
		l2.setSign('+');
		return l2;
	}
	else
	{
		LongInt l2 = subtract(l.longIntList, longIntList);
		l2.setSign('-');
		return l2;
	}
}

//this performs the actual subtraction of two number. this will be called by addition or subtraction function based on condition
LongInt LongInt::subtract(SLLLongIntList  l1, SLLLongIntList  l2)
{
	SLLNode *node = (SLLNode *)l1.last();
	SLLNode *snode =  (SLLNode *)l2.last();
	int borrow = 0;

	//the resultant string
	string val = "";
	//process each node data and calculate the result
	while (node != NULL)
	{
		if(node==NULL || snode==NULL)
			break;

		int digit = 0;
		//if data is larger then subtract it
		if(node->data >= snode->data)
		{
			digit = node->data - snode->data - borrow; 
			borrow = 0;
		}
		else
		{
			//number is lower so borrow 1 from the previous number 
			digit = node->data - snode->data - borrow;
			digit = digit + 100000000;
			borrow = 1;
		}

		val = commonFunctions.convertNumberToString(digit, true, 8) + val;
		snode = (SLLNode*)l2.before(snode);
		node = (SLLNode*)l1.before(node);
	}

	//process the remaining node 
	while (node != NULL)
	{	
		int digit = 0;
		if(borrow == 1)
		{
			digit = node->data - borrow; 
			borrow = 0;
		}
		else
		{
			digit = node->data; 
		}

		val = commonFunctions.convertNumberToString(digit, true, 8) + val;
		node = (SLLNode*)l1.before(node);
	}

	LongInt l = LongInt(val);
	return l;
}



LongInt LongInt::multiply(LongInt l)
{
	//calculate the multiplication of the numbers 
	LongInt l2("1");
	l2 = multiply(longIntList,l.longIntList);
	//process the sign of number.
	//if sign are equal then the resultant sign will be + else the sign will be '-'
	//'-' * '-' = '+' = '+' * '+'
	//'-' * '+' = '-' = '+' * '-'
	if(l.getSign() == getSign())
	{
		l2.setSign('+');
	}
	else
	{
		l2.setSign('-');
	}

	return l2;
}

//calculate the multiplication using Karatsuba algorithm
LongInt LongInt::Karatsuba(int c1, int c2, int d1,int d2)
{
	int z1=c1*d1;
	int z3=c2*d2;
	int z2=(c1 + c2) * (d1 + d2) -z3 -z1;
	LongInt l1(commonFunctions.append(commonFunctions.convertNumberToString(z1),8));
	LongInt l2(commonFunctions.append(commonFunctions.convertNumberToString(z2),4));
	LongInt l3(commonFunctions.convertNumberToString(z3));

	LongInt l = l1.add(l2).add(l3);
	return l;
}

//multiply the numbers
LongInt LongInt::multiply(SLLLongIntList  l1, SLLLongIntList  l2)
{
	LongInt finalVal;
	SLLNode *temp = (SLLNode*)l2.last();
	int multiplier = 0;
	int count = 1;

	//in this loop we will calculate the multiplication by multiplying the 8 digit number at a time and adding them into previous result
	//it is some what similar to above algo of multiplication
	while (temp != NULL)
	{
		SLLNode *temp2 = (SLLNode*)l1.last();
		while (temp2 != NULL)
		{
			LongInt val = Karatsuba(commonFunctions.upperHalf(temp->data),commonFunctions.lowerHalf(temp->data),commonFunctions.upperHalf(temp2->data),commonFunctions.lowerHalf(temp2->data));
			if(multiplier > 0)
			{
				//multiplying the number by 10^multiplie.
				for(int i =0; i < multiplier; i++){
					val.longIntList.insertLast(0);
				}

				finalVal = finalVal.add(LongInt(val));
			}
			else
			{
				finalVal = LongInt(val);
			}

			multiplier++;
			temp2 = (SLLNode*)l1.before(temp2);
		}
		if(l1.size() > 1)
		{
			multiplier = count;
			count++;
		}
		temp = (SLLNode*)l2.before(temp);
	}

	return finalVal;
}

//function to calculate the power of number
LongInt LongInt::power(int num)
{
	//resultant number
	LongInt val = *this;

	//calculate the power using optimized algo of power calculation
	return powerBySquaring(val, num);
}

/** Function for repeated squaring algp for power calculation**/
LongInt LongInt::powerBySquaring(LongInt x, int n)
{
	if (n == 0)
		return LongInt("1");
	else if (n == 1)
		return x;
	else if (n % 2 == 0)
		return powerBySquaring(x.multiply(x), n / 2);
	else 
		return x.multiply(powerBySquaring(x.multiply(x), (n - 1)/2));    
}
