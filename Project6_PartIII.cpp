//--------------------------------------------------------------------------------------------------------
//								Name: Ryan Beebe
//							  Project: No. 6 Part III
//								Course: CMPS 385
//								 Due: 4/4/2018
//
// Purpose: Insert data in array C into an ordered linked list then display all the nodes
//          The program then finds and displays the average of all even numbers in the list.
//---------------------------------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std;

//create the template of class T
template<class T>
//create class OrderedLinked List
class OrderedLinkedList
{
private:
	
	struct node
	{
		T info;
		node *next;
	};
	
	node *list;
	
public:
	OrderedLinkedList()
	{
		list = NULL;
	}
	
	void insert(T x)
	{
		
		node *p = list;
		node *q = list;
		node *r = new (node);
		r->info = x;
		r->next = NULL;
		//find the insertion place
		while (p != NULL && x > p->info)
		{
			q = p;
			p = p->next;
		}
		if (p == list) //x is the first
		{
			list = r;
			r->next = p;
		}
		else if (p == NULL) //x is the last
		{
			q->next = r;
		}
		else //x is not first or last
		{
			r->next = p;
			q->next = r;
		}
	}

	//Display data
	void display()
	{
		node *p = list;
		while (p != NULL)
		{
			cout << p->info << " --> ";
			p = p->next;
		}
		cout << "NULL" << endl;
	}
};


int main()
{
	//Initialize variables
	int c[6] = { 100, 500, 800, 300, 200, 900 };
	int count = 0;
	int total = 0;
	double average = 0;

	OrderedLinkedList<int> setA;
	OrderedLinkedList<int> setB;

	for (int i = 0; i < 6; i++)
	{
		//Insert all values to set A
		setA.insert(c[i]);

		if (i % 2 == 0)
		{
			//Calculate even numbers and insert into SetB
			setB.insert(c[i]);
			count++;
			total += c[i];
			//Find average
			average = (double)total / count;
		}
	}

	//Display content of all nodes
	cout << "The content of the ordered linked list: ";
	setA.display();

	//Display the average
	cout << "average of EVEN numbers in list: " << average << endl;

	system("pause");
	return 0;
}

/*************************************************Output*************************************************

The content of the ordered linked list: 100 --> 200 --> 300 --> 500 --> 800 --> 900 --> NULL
average of EVEN numbers in list: 366.667
Press any key to continue . . .

********************************************************************************************************/