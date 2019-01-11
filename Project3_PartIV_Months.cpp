// --------------------------------------------------------------------------------------------
//					Name: Ryan Beebe
//					Project: No. 3 Part IV
//					Course: CMPS 385
//					Due: 2/28/2018
//
// Purpose: This accepts 10 integers, 10 capital letters to select months then 
//          displays the data in 3 column format
//---------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Create stack class
template <class T, int n>
class STACK
{
private: T a[n];
		 int counter;

public: void clearStack() { counter = 0; }
		bool emptyStack() { return (counter == 0) ? true : false; }
		bool fullStack() { return (counter == n) ? true : false; }
		void pushStack(T x) { a[counter] = x; counter++; }
		T popStack() { counter--; return a[counter]; }
};//end Stack class


int main()
{
	//Create stacks
	STACK <int, 10> NUM;
	STACK <char, 10> ALPHA;
	STACK <string, 10> MONTHS;

	//Clear Stacks
	NUM.clearStack();
	ALPHA.clearStack();
	MONTHS.clearStack();

	int response;
	
	//Input 10 integers below 30 and store them in NUM stack
	for (int i = 0; i < 10; i++)
	{
		cout << "Enter integer " << i+1 << ": ";
		cin >> response;

		if (response > 30)
			cout << "Invalid; integer must be less than 30" << endl;
		else
			NUM.pushStack(response);
	}

	

	cout << endl;

	char letter;
	int ascii;

	//Accept 10 capital letters and store them into ALPHA stack
	for (int i = 0; i < 10; i++)
	{
		cout << "Enter capital letter " << i + 1 << ": ";
		cin >> letter;

		//Convert response into ASCII value
		ascii = static_cast<int>(letter);

		//If ASCII value indicates a capital, push ALPHA stack
		if (ascii > 64 && ascii < 91)
			ALPHA.pushStack(letter);
		else
			cout << "Invalid -- Character must be capital" << endl;
	}

	cout << endl; 

	//Displays a menu of months and allows the user to select 10
	//Selections push proper month string into MONTHS stack
	int month;
	cout << "Select 10 months: " << endl;
	cout << "1. January\n2.February\n3.March\n4. April\n5.May\n6.June\7. July\n8.August\n9.September\n10. October\n11.November\n12.December\n";
	for (int i = 0; i < 10; i++)
	{
		cin >> month;

		if (month > 12)
			cout << "Invalid -- select a valid month" << endl;
		else
			switch (month)
			{
			case 1: MONTHS.pushStack("January");
				break;
			case 2: MONTHS.pushStack("February");
				break;
			case 3: MONTHS.pushStack("March");
				break;
			case 4: MONTHS.pushStack("April");
				break;
			case 5: MONTHS.pushStack("May");
				break;
			case 6: MONTHS.pushStack("June");
				break;
			case 7: MONTHS.pushStack("July");
				break;
			case 8: MONTHS.pushStack("August");
				break;
			case 9: MONTHS.pushStack("September");
				break;
			case 10: MONTHS.pushStack("October");
				break;
			case 11: MONTHS.pushStack("November");
				break;
			case 12: MONTHS.pushStack("December");
				break;

			}
	}

	cout << endl;

	//Display NUM, ALPHA, and MONTHS stacks in 3 column format
	cout << "Numbers:	Uppercase Letters:	Months:" << endl;
	while (!NUM.emptyStack() && !ALPHA.emptyStack() && !MONTHS.emptyStack())
	{
		cout << NUM.popStack() << "\t\t\t" << ALPHA.popStack() << "\t\t" << MONTHS.popStack() << endl;
	}

	system("pause");
	return 0;
}

/*----------------------------Output------------------------------------------------------------------
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

Enter capital letter 1: A
Enter capital letter 2: B
Enter capital letter 3: C
Enter capital letter 4: D
Enter capital letter 5: E
Enter capital letter 6: F
Enter capital letter 7: G
Enter capital letter 8: H
Enter capital letter 9: I
Enter capital letter 10: J

Select 10 months:
1. January
2.February
3.March
4. April
5.May
6.June. July
8.August
9.September
10. October
11.November
12.December
1
2
3
4
5
6
7
8
9
10

Numbers:        Uppercase Letters:      Months:
10                      J               October
9                       I               September
8                       H               August
7                       G               July
6                       F               June
5                       E               May
4                       D               April
3                       C               March
2                       B               February
1                       A               January
Press any key to continue . . .
---------------------------------------------------------------------------------------------*/
