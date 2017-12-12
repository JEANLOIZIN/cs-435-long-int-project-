#include "LongInt.h"
#include "ArrayLongInt.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>  
using namespace std;
int main(){
	string values[9];
	clock_t n1,n2,n3;
	values[0] = "2222";
	values[1] = "99999999";
	values[2] = "-246813575732";
	values[3] = "180270361023456789";
	values[4] = "1423550000000010056810000054593452907711568359";
	values[5] = "-350003274594847454317890";
	values[6] = "29302390234702973402973420937420973420937420937234872349872934872893472893749287423847";
	values[7] = "-98534342983742987342987339234098230498203894209928374662342342342356723423423";
	values[8] = "84364131684386183513516846948354348943643518468434351684843516846843153846843138468131538431 3513841351384381351381313843843515345415451515151314159265454351531684861324258756151651123324617456127652167216241627412307652612";

	ArrayLongInt numbers[256];
	LongInt numbers2[256];

	int totalNumbers = 0;
	for(int i =0; i < 9; i++)
	{
		string number = values[i];
		if(!(number == "" || number=="\n"))
		{
			char sign = number.at(0);
			if(sign == '-')
			{
				number = number.substr(1);
			}
			else
			{
				sign = '+';
			}

			n1 = clock();

			//object declaration
			ArrayLongInt longInt(number);
			//calling to setSign function
			longInt.setSign(sign);

			n2 = clock();

			//object declaration
			LongInt longInt2(number);
			//calling to setSign function
			longInt2.setSign(sign);

			n3 = clock();

			cout<<"Time Taken to Initialize the Value of "<<char('A' + i)<<" : Linked List "<<n2-n1<<"   Array :"<<n3-n2<<endl;

			numbers2[totalNumbers] = longInt2;
			numbers[totalNumbers++] = longInt;
		}
	}

	for(int i = 1; i <= totalNumbers; i++)
	{
		cout<<char('A' + (i-1))<<"   "<<endl;
		cout<<"Arraylist: ";
		numbers[i-1].output();
		cout<<endl;
		cout<<"Linked List: ";
		numbers2[i-1].output();
		cout<<endl;
	}


	cout<<endl;
	cout<<"\t\t\tADITION"<<endl;
	cout<<endl;
	for(int i = 0; i < totalNumbers; i++)
	{
		for(int j = 0; j < totalNumbers; j++)
		{
			cout<<char('A' + i)<<" + "<<char('A' + j)<<" = ";

			cout<<endl<<"Arraylist : ";
			n1 = clock();
			ArrayLongInt l1 = numbers[i].add(numbers[j]);
			l1.output();
			n2 = clock();
			cout<<endl<<"Linkedlist : ";
			LongInt l2 = numbers2[i].add(numbers2[j]);
			l2.output();
			n3 = clock();

			cout<<endl<<"Time taken to add using Arraylist : "<<n2-n1<<endl;
			cout<<"Time taken to add using Linkedlist : "<<n3-n2<<endl;
		}
	}

	cout<<endl;
	cout<<"\t\t\tSUBTRACTION"<<endl;
	cout<<endl;
	for(int i = 0; i < totalNumbers; i++)
	{
		for(int j = 0; j < totalNumbers; j++)
		{
			cout<<char('A' + i)<<" - "<<char('A' + j)<<" = ";

			cout<<endl<<"Arraylist : ";
			n1 = clock();
			ArrayLongInt l1 = numbers[i].subtract(numbers[j]);
			l1.output();
			n2 = clock();
			cout<<endl<<"Linkedlist : ";
			LongInt l2 = numbers2[i].subtract(numbers2[j]);
			l2.output();
			n3 = clock();

			cout<<endl<<"Time taken to Subtract using Arraylist : "<<n2-n1<<endl;
			cout<<"Time taken to Subtract using Linkedlist : "<<n3-n2<<endl;
		}
	}

	cout<<endl;
	cout<<"\t\t\tMULTIPLICATION"<<endl;
	cout<<endl;
	for(int i = 0; i < totalNumbers; i++)
	{
		for(int j = 0; j < totalNumbers; j++)
		{
			cout<<char('A' + i)<<" * "<<char('A' + j)<<" = ";

			cout<<endl<<"Arraylist : ";
			n1 = clock();
			ArrayLongInt l1 = numbers[i].multiply(numbers[j]);
			l1.output();
			n2 = clock();
			cout<<endl<<"Linkedlist : ";
			LongInt l2 = numbers2[i].multiply(numbers2[j]);
			l2.output();
			n3 = clock();

			cout<<endl<<"Time taken to Multiply using Arraylist : "<<n2-n1<<endl;
			cout<<"Time taken to add Multiply Linkedlist : "<<n3-n2<<endl;

		}
	}

	cout<<endl;
	cout<<"\t\t\tPOWER"<<endl;
	cout<<endl;
	for(int i = 0; i < totalNumbers; i++)
	{
		cout<<char('A'+ i )<< " ^ 5"<<" = ";

		cout<<endl<<"Arraylist : ";
		n1 = clock();
		ArrayLongInt l1 = numbers[i].power(5);
		l1.output();
		n2 = clock();
		cout<<endl<<"Linkedlist : ";
		LongInt l2 = numbers2[i].power(5);
		l2.output();
		n3 = clock();

		cout<<endl<<"Time taken to raise to power of 5 using Arraylist : "<<n2-n1<<endl;
		cout<<"Time taken to raise to power of 5 using Linkedlist : "<<n3-n2<<endl;				
		cout<< "\n\n ***NOTE: I could not finish raising the A, B, C etc to power 10 and 20. \n because everytime i run this program it keeps freezing my laptop, because of the amount of operations its performing. \n Once i only allow it to only raise the power to 5 only, the amount of operations are a bit less, and it will only slow the system but do not freeze it. \n therefore i thought it would be a good ideal to leave that part out , if its not too much trouble.\n  BUT if its going to cost me deductions, i will gladly add it and resubmit this program. Thank you for your understanding." << endl<<endl;
	}

	return 0;
}
