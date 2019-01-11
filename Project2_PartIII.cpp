// --------------------------------------------------------------------------------------------
//								Name: Ryan Beebe
//								Project: No. 2 Part III
//								Course: CMPS 385
//								Due: 2/21/2018
//
// Purpose: This project runs 2 recursive functions and displays the clock time for part B
//          
//---------------------------------------------------------------------------------------------


#include <iostream>
#include <ctime>
#include  <cmath>
using namespace std;

//-----------------------------------------------------------
//function name: F
//input: integer n
//output: n
//-----------------------------------------------------------
void F(int n)
{
	if (n >= 1)
	{
		F(n - 2);
		F(n - 1);
		cout << n;
	}
}

//----------------------------------------------------------
//function name: G
//input: integer n
//output: 3+n*G(n-1)
//-----------------------------------------------------------
int G(int n)
{
	if (n <= 2)
		return 3;
	else
		return 3 + n*G(n - 1);
}

int main()
{

	//Declare variables
	double start, finish, time;

	//Call F function
	cout << "Part A: " << endl;
	F(6);
	cout << endl << endl;
	
	//Call G function
	start = clock();
	cout << "Part B: " << endl;
	cout << G(5) << endl << endl;
	finish = clock();
	cout << "The time is:" << finish/1000 << endl << endl;

	system("pause");
	return 0;
}

/*----------------------------------------Output--------------------------------------
Part A:
12112341123121123456

Part B:
258

The time is:0.019

Press any key to continue . . .

-------------------------------------------------------------------------------------*/