// --------------------------------------------------------------------------------------------
//								Name: Ryan Beebe
//								Project: No. 2 Part II
//								Course: CMPS 385
//								Due: 2/21/2018
//
// Purpose: This project runs 3 recursive functions and displays the clock time for part B
//          
//---------------------------------------------------------------------------------------------


#include <iostream>
#include <ctime>
#include  <cmath>
using namespace std;

//-----------------------------------------------------------
//function name: sum
//input: integer n, integer m
//output: m 
//-----------------------------------------------------------
int sum(int n, int m)
{
	if (n == m)
		cout << m;
	else
		return n + sum(n + 1, m);
}

//----------------------------------------------------------
//function name: g
//input: integer n
//output: n + g(n - 1) + g(n - 2)
//-----------------------------------------------------------
int g(int n)
{
	if (n <= 3)
		return 2;
	else
		return n + g(n - 1) + g(n - 2);
}

//-----------------------------------------------------------
//function name: f
//input: integer n
//output: pow(3, n + i)
//-----------------------------------------------------------
int f(int n)
{
	if (n == 0)
		return 1;
	else
		for (int i = 0; i < n; i++)
			return pow(3, n + i);
}

int main()
{

	//Declare variables
	double start, finish, time;
	
	//Call sum function
	cout << "Part A:" << endl;
	cout << sum(3, 8) << endl << endl;

	//Call g function
	cout << "Part B: " << endl;
	start = clock();
	cout << g(41)<<endl;
	finish = clock();
	cout << "The time is:" << (finish - start) / 1000 << endl << endl;

	//Call f function
	cout << "Part C: " << endl;
	cout << f(10) << endl << endl;

	system("pause");
	return 0;
}

/*----------------------------------------Output--------------------------------------
Part A:
81343597481

Part B:
779585027
The time is:25.076

Part C:
59049

Press any key to continue . . .
-------------------------------------------------------------------------------------*/