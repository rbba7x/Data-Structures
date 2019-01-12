//--------------------------------------------------------------------------------------------------------
//				Name: Ryan Beebe
//				Project: No. 6 Part II
//				Course: CMPS 385
//				Due: 4/4/2018
//
// Purpose: Insert array b in linked list to emulate a queue using FIFO and display the contents of
//          all nodes. The program then finds the min and max in the queue.
//--------------------------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

//create template class T
template<class T>
//create class QUEUE_LIST
class QUEUE_LIST
{
private:
	struct node
	{
		T info;
		node *next;
	};
	node *front;
	node *rear;
	//create QUEUE_LIST methods
public:
	QUEUE_LIST()
	{
		front = NULL;
		rear = NULL;
	}
	//add a node at the rear of the queue
	void pushq(T x)
	{
		node * p = new (node);
		p->info = x;
		p->next = NULL;
		if (front == NULL)
		{
			front = p;
			rear = p;
		}
		else
		{
			rear->next = p;
			rear = p;
		}
	}
	//test if queue is empty
	bool emptyq()
	{
		if (front == NULL)
			return true;
		else
			return false;
	}
	//do not use pop
	T popq()
	{
		node *p = front;
		T x;
		x = front->info;
		front = front->next;
		delete p;
		return x;
	}
	//display first node without popping
	void display()
	{
		node *p = front;
		while (p != NULL)
		{
			cout << p->info << " --> ";
			p = p->next;
		}
		cout << "NULL" << endl;
	}
	//Calculate max and min in queue
	void findMaxMin(int &max, int& min)
	{
		node *p = front;
		max = min = p->info;
		p = p->next; //start from next node
		while (p != NULL)
		{
			//Find max
			if (p->info > max)
				max = p->info;
			//Find min
			if (p->info < min)
				min = p->info;
			p = p->next;
		}
	}
};


int main()
{
	//Initialize variables
	int b[5] = { 10, 50, 70, 20, 40 };

	QUEUE_LIST<int> Q;

	//Push elements into queue 
	for (int i = 0; i < 5; ++i)
	{
		Q.pushq(b[i]);
	}

	//Display nodes
	cout << "The content of the list is: ";
	Q.display();

	//Find max and min in max
	int max;
	int min;
	Q.findMaxMin(max, min); //Find max and min
	cout << "Maximum = " << max << "  Minimum = " << min << endl;

	system("pause");
	return 0;
}

/*************************************************Output*************************************************

The content of the list is: 10 --> 50 --> 70 --> 20 --> 40 --> NULL
Maximum = 70  Minimum = 10
Press any key to continue . . .

********************************************************************************************************/
