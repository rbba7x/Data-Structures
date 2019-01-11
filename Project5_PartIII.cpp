// -----------------------------------------------------------------------------------------------------------------------------------
//								Name: Ryan Beebe
//								Project: No. 5 Part III
//								Course: CMPS 385
//								Due: 3/14/2018
//
// Purpose: This project generates 10 random integers and stores them in an array. The array is then pushed into a linked list. The
//			data is read off of the linked list and all odd and even numbers are pushed into appropriate stacks to be displayed. The 
//			program also calculates the average of all numbers.
//------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include "STACKPAC.h"
using namespace std;

struct node
{
	int num;
	node *next;

};

int main()
{
	//Declares nodes and variables
	node *list;
	node *p;
	list = new(node);
	p = list;

	int a[10];

	//Create stacks
	STACK <int, 10> even;
	STACK <int, 10> odd;

	//Clear stacks
	even.clearStack();
	odd.clearStack();

	//Generate 10 random integers
	for (int i = 0; i < 10; i++)
	{
		a[i] = rand() % 20;
	}

	//Create the linked list
	for (int i = 0; i < 10; i++)
	{
		p->num = a[i];
		p->next = new(node);
		p = p->next;
	}
	a[9] = p->num;
	p->next = NULL;

	//Display the linked list
	cout << "Full list: ";
	p = list;
	while (p->next != NULL)
	{
		cout << p->num<<" ";
		p = p->next;
	}
	cout << endl;

	//Find which numbers are even and odd
	p = list;
	int temp;
	while (p->next != NULL)
	{
		temp = p->num;
		if (temp % 2 == 0)
			even.pushStack(temp);
		else
			odd.pushStack(temp);

		p = p->next;
	}

	//Display even and odd numbers
	cout << "Even numbers: ";
	while (!even.emptyStack())
	{
		cout << even.popStack() << " ";
	}
	cout << endl;

	cout << "Odd numbers: ";
	while (!odd.emptyStack())
	{
		cout << odd.popStack() << " ";
	}
	cout << endl;

	//Compute and display average
	p = list;
	double total = 0;
	int counter = 0;

	while (p->next != NULL)
	{
		total += p->num;
		counter++;
		p = p->next;
	}
	cout << "Average: " << total / counter << endl << endl;

	system("pause");
	return 0;
}

/*------------------------------Output------------------------------------
Full list: 1 7 14 0 9 4 18 18 2 4
Even numbers: 4 2 18 18 4 0 14
Odd numbers: 9 7 1
Average: 7.7

Press any key to continue . . .
-------------------------------------------------------------------------*/