// -----------------------------------------------------------------------------------------------------------------------------------
//								Name: Ryan Beebe
//								Project: No. 2 Part I
//								Course: CMPS 385
//								Due: 2/21/2018
//
// Purpose: This project declares a 1d array and a 2d array. The program capitalizes select elements in both arrays, gives the length
//          of selected elements in both arrays, and swaps elements of between the two events.
//------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <cstring>
using namespace std;


//--------------------------------------------------------
//function name: displayDay
//input: array x of size n
//output: array x
//--------------------------------------------------------
void displayDay(string x[], int n)
{
	for (int i = 0; i < n; i++)
		cout << x[i] << "\t";
	cout << endl;
}

//---------------------------------------------------------
//function name: displayDays
//input: array x of size n
//output: array x
//---------------------------------------------------------
void displayDays(char x[5][10], int n, int p)
{
	for (int i = 0; i<n; i++)
	{
		for(int j=0; j<p; j++)
		{
			cout << x[i][j];
		}
	}
	cout << endl;
}

//-----------------------------------------------------------
//function name: changeCase
//input: array x of size n
//output: capitalize element [0][0] in array x 
//-----------------------------------------------------------
void changeCase(string x[], int n)
{
	x[0][0] = toupper(x[0][0]);

	
	cout << "From array day: " << x[0] << endl;
}

//------------------------------------------------------------
//function name: changeCase
//input: 2d array x of size [n][p]
//output: capitalize element [2][0] in 2d array x
//------------------------------------------------------------
void changeCase(char x[5][10], int n, int p)
{
	x[2][0] = toupper(x[2][0]);


	cout << "From array days: " << x[2] << endl;
}

//-----------------------------------------------------------------------------------------------
//function name: displayLength
//input: array x of size n, 2d array y of size [m][o]
//output: display length of element 1 in array x and display length of element 1 in 2d array y
//------------------------------------------------------------------------------------------------
void displayLength(string x[], char y[5][10], int n, int m, int o)
{
	int i1 = x[1].length();
	int i2 = strlen(y[1]);

	cout << "The Tuesday in array day is length " << i1 << endl;
	cout << "The Tuesday in array days is length " << i2 << endl;
}

//--------------------------------------------------------------------------------
//function name: changeTuesday
//input: array x of size n, 2d array y of size [m][o]
//output: Modify Tue to Tuesday in array x, modify Tuesday to Tue in array y 
//--------------------------------------------------------------------------------
void changeTuesday(string x[], char y[5][10], int n, int m, int o)
{

	//Modify Tuesday to Tue in days array
	y[1][0] = x[1][0];
	y[1][1] = x[1][1];
	y[1][2] = x[1][2];
	y[1][3] = 0;
	y[1][4] = 0;
	y[1][5] = 0;
	y[1][6] = 0;
	y[1][7] = 0;
	y[1][8] = 0;
	y[1][9] = 0;

	//Modify Tue to Tuesday in day array
	x[1] = "Tuesday";
	
	//Display Day array
	for (int i = 0; i < n; i++)
		cout << x[i] << "\t";
	
	cout << endl;

	//Display days array
	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j<o; j++)
		{
			cout << y[i][j];
		}
	}
	cout << endl;
}

int main()
{
	
	//Instantiate 1d array day and 2d array days
	string day[5] = { "Monday","Tue","Wednesday","Thursday","Friday" };
	char days[5][10] = { "Monday","Tuesday","Wednesday","Thu","Friday" };
	
	//Display original array
	displayDay(day, 5);
	displayDays(days, 5, 10);

	//Change monday to Monday in day
	changeCase(day, 5);
	//Change wednesday to Wednesday in days
	changeCase(days, 5, 10);

	//Display the length of both arrays
	displayLength(day, days, 5, 5, 10);

	//Change Tue to Tuesday in day array, change Tuesday to Tue in days array
	changeTuesday(day, days, 5, 5, 10);

	system("pause");
	return 0;
}

/*-----------------------------------Output--------------------------------------------
Monday  Tue     Wednesday       Thursday        Friday
Monday    Tuesday   Wednesday Thu       Friday
From array day: Monday
From array days: Wednesday
The Tuesday in array day is length 3
The Tuesday in array days is length 7
Monday  Tuesday Wednesday       Thursday        Friday
Monday    Tue       Wednesday Thu       Friday
Press any key to continue . . .
-----------------------------------------------------------------------------------------*/