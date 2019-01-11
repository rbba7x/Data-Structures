// --------------------------------------------------------------------------------------------
//								Name: Ryan Beebe
//								Project: No. 3 Part II
//								Course: CMPS 385
//								Due: 2/28/2018
//
// Purpose: This accepts 10 integers then displays them all, displays the even numbers, then 
//          displays the odd numbers
//
//---------------------------------------------------------------------------------------------

#include <iostream>
using namespace std;


//Create stack class
class STACK
{
private: int a[10];
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
			counter--; return a[counter];
		}
};//end of class Stack

int main()
{
	STACK s, e, o;
	int temp;

	//Clear all stacks
	s.clearStack();
	e.clearStack();
	o.clearStack();

	//Accept 10 integer numbers and sort them into appropriate stacks
	for (int i = 0; i <= 9; i++)
	{
		cout << "Enter integer " << i+1 << ": ";
		cin >> temp;

		s.pushStack(temp);

		if (temp % 2 == 0)
			e.pushStack(temp);
		else
			o.pushStack(temp);		
	}
	
	//Display all numbers 
	cout << endl << "All numbers: ";
	while (!s.emptyStack())
	{
		cout << s.popStack()<<" ";
	}
	
	//Display all even numbers
	cout << endl << "Even Numbers: ";
	while (!e.emptyStack())
	{
		cout << e.popStack() << " ";
	}

	//Display all odd numbers
	cout << endl << "Odd numbers: ";
	while (!o.emptyStack())
	{
		cout << o.popStack() << " ";
	}

	cout << endl << endl;
	
	system("pause");
	return 0;
}

/*-----------------------Output----------------------
Enter integer 1: 1
Enter integer 2: 2
Enter integer 3: 3
Enter integer 4: 4
Enter integer 5: 5
Enter integer 6: 6
Enter integer 7: 7
Enter integer 8: 8
Enter integer 9: 9
Enter integer 10: 10

All numbers: 10 9 8 7 6 5 4 3 2 1
Even Numbers: 10 8 6 4 2
Odd numbers: 9 7 5 3 1

Press any key to continue . . .

-----------------------------------------------------*/