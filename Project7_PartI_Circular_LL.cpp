//--------------------------------------------------------------------------------------------------------
//				Name: Ryan Beebe
//				Project: No. 7 Part I
//				Course: CMPS 385
//				Due: 4/11/2018
//
// Purpose: This project generates 10 random integers <50 and puts them into a circular linked list. The
//          circular link list is then displayed
//--------------------------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

struct node
{
	int info;
	struct node *next;
}

*last;



//create template of class T
template <class T>
//create class STACK_LIST
class STACK_LIST
{
private:
	//create struct node
	struct node
	{
		T info;
		node * next;
	};

	node * stack;

public:

	void circularList()
	{
		node *p = stack;

		while (p->next != NULL)
		{
			p = p->next;
		}
		
		p->next = stack;
		p = stack;
		do

		{

			cout << p->info << " -> ";

			p = p->next;

		} while (p != stack);

	   // node *p = stack;
		while (p->next != stack)
		{

			cout << p->info << " -> ";
			p = p->next;
		}

		cout << p->info << endl;

	}

	STACK_LIST()
	{
		stack = NULL;
	}
	//add a node at the front of the list
	void pushStack(T x)
	{
		node * p = new (node);
		p->info = x;
		p->next = stack;
		stack = p;
	}
	bool emptyStack()
	{
		return(stack == NULL) ? true : false;
	}
	T popStack()
	{
		node *p = stack;
		T x;
		x = stack->info;
		stack = stack->next;
		delete p;
		return x;
	}
};


int main()
{
	//Initialize variables
	int a[10];
	int count = 0;

	//Generate 10 random integers <50 and put into array
	for (int i = 0; i < 10; i++)
	{
		a[i] = rand() % 50;
	}

	//Insert data from array to stack
	STACK_LIST<int> s;
	for (int i = 0; i < 10; i++)
	{
		s.pushStack(a[i]);
		count++;
	}

	//Display circular linked list
	cout << "Circular Linked List: ";
	s.circularList();

	system("pause");
	return 0;
}

/*------------------------------------Output--------------------------------------------------------------------------------------------
Circular Linked List: 14 -> 12 -> 8 -> 28 -> 24 -> 19 -> 0 -> 34 -> 17 -> 41 -> 14 -> 12 -> 8 -> 28 -> 24 -> 19 -> 0 -> 34 -> 17 -> 41
Press any key to continue . . .
---------------------------------------------------------------------------------------------------------------------------------------*/
