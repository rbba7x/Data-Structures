// --------------------------------------------------------------------------------------------
//								Name: Ryan Beebe
//								Project: No. 3 Part III
//								Course: CMPS 385
//								Due: 2/28/2018
//
// Purpose: This accepts a user-entered string and displays the capitals, lower case, and vowels 
//          
//
//---------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Create stack class
template <class T, int n>
class STACK
{
private: char a[25];
		 int counter;
public: void clearStack() { counter = 0; }
		bool emptyStack() { return (counter == 0) ? true : false; }
		bool fullStack() { return (counter == 20) ? true : false; }
		void pushStack(char x) { a[counter] = x; counter++; }
		char popStack() { counter--; return a[counter]; }
};


int main()
{
	STACK <char, 25> upper, lower, vowel;
	
	// assigning value to character array
	char char_array[25];
	cout << "Enter a sentence: ";
	cin >> char_array;


	//declare array to store ascii values
	int ascii[15];

	//fill ascii array with ascii values of char_array elements
	for (int i = 0; i < 15; i++)
	{
		ascii[i] = static_cast<int>(char_array[i]); // casting char to ascii value
	}
	

	upper.clearStack();
	lower.clearStack();
	vowel.clearStack();

	//filter elements to appropriate stacks
	for (int i = 0; i < 15; i++)
	{
		//if vowel, push to vowel stack
		if (char_array[i] == 'A' || char_array[i] == 'a' ||
			char_array[i] == 'E' || char_array[i] == 'e' ||
			char_array[i] == 'I' || char_array[i] == 'i' ||
			char_array[i] == 'O' || char_array[i] == 'o' ||
			char_array[i] == 'U' || char_array[i] == 'u')
			vowel.pushStack(char_array[i]);

		//if ascii value indicates capital letter, push to upper case stack
		 if (ascii[i] > 64 && ascii[i] < 91)
			upper.pushStack(ascii[i]);
		 //if ascii value indicates lower case letter, push to lower case stack
		else if (ascii[i] > 96 && ascii[i] < 123)
			lower.pushStack(ascii[i]);
		 //else do nothing
		else
		{
		}
	} // end for loop


	//Print all upper case
	cout << "Upper: ";
	while (!upper.emptyStack())
	{
		cout << upper.popStack();
	}

	cout << endl;

	//Print all lower case
	cout << "Lower: ";
	while (!lower.emptyStack())
	{
		cout << lower.popStack();
	}

	cout << endl;

	//Print all vowels
	cout << "Vowels: ";
	while (!vowel.emptyStack())
	{
		cout << vowel.popStack();
	}

	cout << endl;

	system("pause");
	return 0;
}

/*-------------------Output-----------------------------------
Enter a sentence: TodayIsMonday
Upper: MIT
Lower: yadnosyado
Vowels: aoIao
Press any key to continue . . .
----------------------------------------------------------*/