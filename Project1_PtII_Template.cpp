// ----------------------------------------------------------------------------------------------------------------------
//					Name: Ryan Beebe
//					Project: No. 1 part II
//					Course: CMPS 385
//					Due: 2/14/2018
//
// Purpose: This project instantiates arrays of three different data types and sorts them using one function template
//-----------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//Funtion's prototype
template <class T> void Show(T x[], int n);

//-------------------------------------------------------------------------------------------------------
//function name: Show
//input: Array x of size n
//output: Sorts and displays array x
//-------------------------------------------------------------------------------------------------------
template <class T>
void Show(T x[], int n)
{
	sort(x, x + n);
 
	for (int i = 0; i < n; i++)
		cout << x[i] << " ";
	cout << endl;
}

int main()
{
	//Instantiate 3 arrays of different data types
	int a[5] = { 9, 7, 1, 8, 6 };
	string s[4] = { "winners", "never", "quit" };
	char c[5] = { 'e', 'o', 'u', 'a', 'i' };

	//Call Show function for each array
	Show(a, 5);
	Show(s, 4);
	Show(c, 5);

	system("pause");
	return 0;
}

/*
-------------------------Output-------------------------------------------
1 6 7 8 9
never quit winners
a e i o u
Press any key to continue . . .
--------------------------------------------------------------------------
*/
