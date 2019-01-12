
	//--------------------------------------------------------------------------------------------------------
	//				Name: Ryan Beebe
	//				Project: No. 6 Part I
	//				Course: CMPS 385
	//				Due: 4/4/2018
	//
	// Purpose: This projects inserts an array into a linked list to emulate a stack using FILO. The 
	//          nodes are displayed, the total of all the nodes is displayed, and the number 
	//          of nodes in the linked list is displayed.
	//--------------------------------------------------------------------------------------------------------

#include<iostream>
using namespace std;

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
	//Display stack without pop method
	void display()
	{
		node *p = stack;
		while (p != NULL)
		{
			cout << p->info << " --> ";
			p = p->next;
		}
		cout << "NULL" << endl;
	}
	//Compute total in stack
	int computeTotal()
	{
		int total = 0;
		node *p = stack;
		while (p != NULL)
		{
			total += p->info;
			p = p->next;
		}
		return total;
	}
};


int main()
{
	//Initialize variables
	int a[7] = { 3, 6, 9, 1, 8, 5, 2 }; 
	int count = 0; 

	//Insert data from array to stack
	STACK_LIST<int> s;
	for (int i = 0; i < 7; ++i)
	{
		s.pushStack(a[i]); 
		count++; 
	}

	//display stack without removing any item from the stack
	cout << "This is the the content of the stack using display member: ";
	s.display();

	//Calculate total of data in stack
	cout << "Total of all the nodes is: " << s.computeTotal() << endl;

	//Find number of nodes are in the list
	cout << "Number of nodes in the list: " << count << endl;

	system("pause");
	return 0;
}
/*************************************************Output*************************************************

This is the the content of the stack using display member: 2 --> 5 --> 8 --> 1 --> 9 --> 6 --> 3 --> NULL
Total of all the nodes is: 34
Number of nodes in the list: 7
Press any key to continue . . .

********************************************************************************************************/
