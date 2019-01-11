// --------------------------------------------------------------------------------------------
//								Name: Ryan Beebe
//								Project: No. 3 Part I
//								Course: CMPS 385
//								Due: 2/28/2018
//
// Purpose: This accepts an integer value then displays the integer in binary (base 2), octal
//          (base 8), and hexadecimal (base 16)
//
//---------------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

//Create stack class
class STACK
{
private: int a[1000];
	int counter;

public: void clearStack() {
		counter = 0;
		}
		 
		bool fullStack() 
		{
			 if (counter == 5) return true;
			 else return false;
		 }
	
		bool emptyStack()
		{
			if (counter == 0)return true;
			else return false;
		}
		
		void pushStack(int x)
		 {
			 a[counter] = x;
			 counter++;
		 }

		int popStack()
		 {
			 counter --; return a[counter];
		 }
};//end of class Stack

int main()
{
	int input;
	STACK s, o, h;

	//Get input
	cout << "Enter an integer number: ";
	cin >> input;

	//Create copies of input to be manipulated for each stack
	int temp1 = input, temp2 = input;
	
	//Display the input in binary
	s.clearStack();
	cout << "Binary: ";
	
	while (input != 0)
	{
		if ((input % 2) == 0)
			s.pushStack(0);
		else s.pushStack(1);

		input = input/2;
	}
	
	while(!s.emptyStack())
	{
		cout << s.popStack();
	}

	cout << endl;

	//Display the input in octal
	o.clearStack();
	cout << "Octal: ";

	while (temp1 != 0)
	{
		int remainder;

		remainder = temp1 % 8;
		o.pushStack(remainder);

		temp1 = temp1 / 8;
	}

	while (!o.emptyStack())
	{
		cout << o.popStack();
	}

	cout << endl;

	//Display the input in hexadecimal
	h.clearStack();
	cout << "Hexadecimal: ";

	while (temp2 != 0)
	{
		int remainder;

		remainder = temp2 % 16;
		
		if(remainder == 10)
			h.pushStack('A');
		else 
			if (remainder == 11)
				h.pushStack('B');
			else
				if (remainder == 12)
					h.pushStack('C');
				else
					if (remainder == 13)
						h.pushStack('D');
					else
						if (remainder == 14)
							h.pushStack('E');
						else
							if (remainder == 15)
								h.pushStack('F');
							else
							h.pushStack(remainder);
		temp2 = temp2 / 16;
	}

	int val;
	while (!h.emptyStack())
	{
		val = h.popStack();
		
		if (val == 65)
			cout << "A";
		else
			if (val == 66)
				cout << "B";
			else
				if (val == 67)
					cout << "C";
				else
					if (val == 68)
						cout << "D";
					else
						if (val == 69)
							cout << "E";
						else
							if (val == 70)
								cout << "F";
							else
								cout << val;
	}
	cout << endl;
	system("pause");
	return 0;
}

/*-------------Output---------------
Enter an integer number: 163
Binary: 10100011
Octal: 243
Hexadecimal: A3
Press any key to continue . . .
-----------------------------------*/
