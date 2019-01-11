//--------------------------------------------------------------------------------------------------------
//								Name: Ryan Beebe
//							  Project: No. 11 Part I
//								Course: CMPS 385
//								 Due: 5/16/2018
//
// purpose: This programs allows fractions to be read, added, subtracted, multiplied, and divided.
//    
//--------------------------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

class FRACT
{
private:
	int n, d;

public:
	void readFract()
	{
		cout << "Enter a fraction : ";
		cin >> n;
		cin.ignore();
		cin >> d;
	}

	friend FRACT operator+ (FRACT F1, FRACT F2)
	{
		FRACT r; //r.n/r.d = f1.n/f1/d + f2.n/f2.d = (f1.n*f2.d)/(f1.d*f2.d) + (f2.n*f1.d)/(f2.d*f1.d) = (f1.n*f2.d + f2.n*f1.d)/(f1.d*f2.d)

		r.n = F1.d*F2.n + F2.d*F1.n;
		r.d = F1.d*F2.d;
		return r;
	}

	FRACT operator- (FRACT F2)
	{
		//We have access to n and d of f1
		FRACT r;

		r.n = n * F2.d - d*F2.n;
		r.d = d * F2.d;

		return r;
	}

	FRACT operator* (FRACT F2)
	{
		//We have access to n and d of f1
		FRACT r;

		r.n = n * F2.n;
		r.d = d * F2.d;

		return r;
	}

	FRACT operator/ (FRACT F2)
	{
		//We have access to n and d of f1
		FRACT r;

		r.n = n * F2.d;
		r.d = d * F2.n;

		return r;
	}

	void displayFract()
	{
		cout << n << "/" << d;
	}


};

int main()
{
	FRACT f1, f2, f;

	f1.readFract();
	f2.readFract();

	f = f1 + f2; //Acts as a function call

	f1.displayFract();
	cout << " + ";
	f2.displayFract();

	cout << " = ";
	f.displayFract();
	cout << endl;

	f = f1 - f2; //Acts as a function call

	f1.displayFract();
	cout << " - ";
	f2.displayFract();

	cout << " = ";
	f.displayFract();
	cout << endl;

	f = f1 * f2; //Acts as a function call

	f1.displayFract();
	cout << " * ";
	f2.displayFract();

	cout << " = ";
	f.displayFract();
	cout << endl;

	f = f1 / f2; //Acts as a function call

	f1.displayFract();
	cout << " / ";
	f2.displayFract();

	cout << " = ";
	f.displayFract();
	cout << endl;

	system("pause");
	return 0;
}

/*-------------------------------Output----------------------------------------
Enter a fraction : 4/5
Enter a fraction : 6/7
4/5 + 6/7 = 58/35
4/5 - 6/7 = -2/35
4/5 * 6/7 = 24/35
4/5 / 6/7 = 28/30
Press any key to continue . . .
-------------------------------------------------------------------------------*/
