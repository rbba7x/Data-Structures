// --------------------------------------------------------------------------------------------
//				Name: Ryan Beebe
//				Project: No. 4 Part III
//				Course: CMPS 385
//				Due: 3/7/2018
//
// Purpose: This accepts a sentence and displays whether or not it is a palindrome
//---------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include "STACKPAC.h"
using namespace std;

int main()
{

	//Declare variables
	STACK RL, LR, TEMP;
	char c1, c2, resp = 'y';
	string sentence; 

	while (resp == 'y' || resp == 'Y')
	{
		char c;		
		//Input data
		cout << "Enter a sentence : ";
		cin >> sentence;
		RL.clearStack();
		LR.clearStack();
		TEMP.clearStack();
		while (c = cin.get(), c != '\n')
		{
			RL.pushStack(c);
		}

		//Push backwards sentence into TEMP and LR stacks
		char t;
		while (!RL.emptyStack())
		{
			t = RL.popStack();
			TEMP.pushStack(t);
			LR.pushStack(t);
		}

		//Put original data back into RL
		while (!TEMP.emptyStack())
		{
			RL.pushStack(TEMP.popStack());
		}

		//Determine whether the sentence is a palindrone by comparing the letters left to right and right to left
		while (!RL.emptyStack())
		{
			c1 = RL.popStack();
			c2 = LR.popStack();

			c1 = tolower(c1);
			c2 = tolower(c2);

			if (c1 != c2) break;
		}

		if (RL.emptyStack() == true)
			cout << "This is a palindrome" << endl;
		else
			cout << "This is not a palindrome" << endl;

		cout << "Would you like to continue? (y/n)" << endl;
		cin >> resp;
	}
	system("pause");
	return 0;
}

/*------------------------Output-----------------------------------------------------------------
Enter a sentence : ToobadIhidaboot
This is a palindrome
Would you like to continue? (y/n)
y
Enter a sentence : Dogeeseseegod
This is a palindrome
Would you like to continue? (y/n)
y
Enter a sentence : That's all
This is not a palindrome
Would you like to continue? (y/n)
n
Press any key to continue . . .
------------------------------------------------------------------------------------------------*/
