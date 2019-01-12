// --------------------------------------------------------------------------------------------
//				Name: Ryan Beebe
//				Project: No. 4 Part II
//				Course: CMPS 385
//				Due: 3/7/2018
//
// Purpose: This project accepts values for 4 variables then reads and evaluates a postfix 
//          expression
//---------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include "STACKPAC.h"
using namespace std;

int main()
{
	STACK <int, 10> p;
	char cc, resp = 'y';
	int x, r, y;
	int a, b, c, d;

	

	while (resp == 'y' || resp == 'Y') {
		

		cout << "What is a, b, c, and d?" << endl;
		cin >> a;
		cin >> b;
		cin >> c;
		cin >> d;

		cout << "Enter a postfix expression : ";
		p.clearStack();
		while (cc = cin.get(), cc != '$')
		{
			if (isalpha(cc))
			{
				switch (cc)
				{
				case 'a': p.pushStack(a); break;
				case 'b': p.pushStack(b); break;
				case 'c': p.pushStack(c); break;
				case 'd': p.pushStack(d); break;
				}
			}
			else {
				switch (cc)
				{
				case '*': x = p.popStack(); y = p.popStack(); r = y*x; p.pushStack(r); break;
				case ' - ': x = p.popStack(); y = p.popStack(); r = y - x; p.pushStack(r); break;
				}
			}

		}

	cout << "Result = " << p.popStack() << endl;
	cout << "Would you like to continue? (y/n)" << endl;
	cin >> resp;
}
	system("pause");
	return 0;
}

/*-----------------------------------------------Output----------------------------------------------
3
4
5
6
Enter a postfix expression : ab*c+d-$
Result = 6
Would you like to continue? (y/n)
y
What is a, b, c, and d?
4
5
6
7
Enter a postfix expression : aa+b*c-d+$
Result = 7
Would you like to continue? (y/n)
n
Press any key to continue . . .
---------------------------------------------------------------------------------------------------*/
