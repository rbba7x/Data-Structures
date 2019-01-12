// -----------------------------------------------------------------------------------------------------------------------------------
//				Name: Ryan Beebe
//				Project: No. 5 Part I
//				Course: CMPS 385
//				Due: 3/14/2018
//
// Purpose: This project declares and initializes an array. The array is made into a linked list where the contents are displayed,
//          summed, and the  number of  nodes is displayed.
//------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

struct node
{
	int info;
	node *next;
};

node *list;

void display(node *r)
{
	while (r != NULL)
	{
		cout << r->info << " ";
		r = r->next;
	}
	cout << endl;
}

int main()
{
	int i;
	node *p;
	node *list = new(node);
	p = list;
	int a[5] = { 9,8,5,7 };

	//Display list
	for (i = 0; i < 3; i++)
	{
		p->info = a[i];
		p->next = new(node);
		p = p->next;
	}
	p->info = a[i];
	p->next = NULL;
	cout << "The original list: ";
	display(list);

	//Display the total of all nodes
	int total = 0;
	for (i = 0; i < 4; i++)
	{
		p->info = a[i];
		p->next = new(node);
		total += p->info;
		p = p->next;
	}
	p->info = a[i];
	p->next = NULL;
	cout << "The total is: " << total << endl;

	//Find how many nodes are in the list
	int c = 0;
	p = list;

	while (p!= NULL)
	{
		c++;
		p = p->next;
	}
	cout << "Number of nodes : " << c/2;
	cout << endl;

	system("pause");
	return  0;
}

/*------------------------------Output---------------------------------
The original list: 9 8 5 7
The total is: 29
Number of nodes : 4
Press any key to continue . . .
----------------------------------------------------------------------*/
