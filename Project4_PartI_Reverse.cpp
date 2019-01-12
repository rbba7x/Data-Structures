// --------------------------------------------------------------------------------------------
//				Name: Ryan Beebe
//				Project: No. 4 Part I
//				Course: CMPS 385
//				Due: 3/7/2018
//
// Purpose: This project creates 3 arrays of varying data types and displays the arrays in
//          reverse order
//---------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include "STACKPAC.h"
using namespace std;

int main()
{

	//Declare and initialize arrays
	int a[7] = { 5,9,7,6,2,3,10 };
	char c[5] = { 'e','o','a','i','u' };
	string month[12] = { "Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dec" };

	//Create stacks
	STACK <int, 7> integers;
	STACK <char, 5> letters;
	STACK <string, 12> months;

	//Clear the stacks
	integers.clearStack();
	letters.clearStack();
	months.clearStack();

	//Input data into proper stacks
	for (int i = 0; i < 12; i++)
	{
		if (i < 5)
		{
			integers.pushStack(a[i]);
			letters.pushStack(c[i]);
			months.pushStack(month[i]);
		}
		else if (i < 7)
		{
			integers.pushStack(a[i]);
			months.pushStack(month[i]);
		}
		else 
			months.pushStack(month[i]);
	}

	//Display integer stack
	while (!integers.emptyStack())
	{
		cout << integers.popStack() << " ";
	}
	cout << endl;

	//Display chracter stack
	while (!letters.emptyStack())
	{
		cout << letters.popStack() << " ";
	}
	cout << endl;

	//Display string stack
	while (!months.emptyStack())
	{
		cout << months.popStack() << " ";
	}
	cout << endl << endl;


	system("pause");
	return 0;
}

/*----------------------------Output---------------------------------
10 3 2 6 7 9 5
u i a o e
Dec Nov Oct Sept Aug July June May Apr Mar Feb Jan

Press any key to continue . . .
--------------------------------------------------------------------*/
