#include <iostream>
#include <string>
using namespace std;

class sHASH
{
private:
	struct data
	{
		string months;
		int days;

	};
	struct node
	{
		data info;

		node *next;
	};
	node *H[4];
	data MN[12] = { { "Jan", 31 },{ "Feb", 30 },{ "Mar", 31 },{ "Apr", 30 },{ "May", 31 },{ "Jun", 30 },{ "Jul", 31 },
					{ "Aug", 31 },{ "Sep", 30 },{ "Oct", 31 },{ "Nov", 30 },{ "Dec", 31 } };

public:

	void initializeHtable()
	{
		for (int i = 0; i < 4; ++i)
			H[i] = NULL;
	}
	int hashFun(string x)
	{
		return (int(x[0]) + int(x[1])) % 4;
	}
	void insert()
	{
		for (int j = 0; j < 12; ++j)
		{
			int i = hashFun(MN[j].months);
			//insert x in linked list pointed by H[i]
			node *p = new node;
			p->info.months = MN[j].months;
			p->info.days = MN[j].days;
			p->next = H[i];
			H[i] = p;
		}
	}
	void search(string x)
	{
		int i = hashFun(x);
		//search for x in Linked List pointed by H[i]
		node *p = H[i];
		while (p != NULL)
		{
			if (p->info.months == x) break;
			p = p->next;
		}
		if (p != NULL)
			cout << "There are " << p->info.days <<" days in this month" << endl;
		else
			cout << x << " does not exist\n";


	}
	void display()
	{
		for (int i = 0; i <4; ++i)
		{
			cout << "H[" << i << "] -> ";
			node * p = H[i];
			while (p != NULL)
			{
				cout << p->info.months << "  " << p->info.days << " --> ";
				p = p->next;
			}
			cout << "NULL" << endl;
		}
	}
};

int main()
{

	sHASH s;
	s.initializeHtable();
	s.insert();
	s.display();
	string mName;
	
	
	char resp = 'y';

	while (resp == 'y' || resp == 'Y')
	{
		cout << endl << "Enter a month: ";
		cin >> mName;

		//Find days
		s.search(mName);
		cout << endl;
		cout << "Continue? : ";
		cin >> resp;
	}

	system("pause");
	return 0;
}

/*-----------------------Output--------------------------------------
H[0] -> Sep  30 --> NULL
H[1] -> Dec  31 --> Nov  30 --> Apr  30 --> NULL
H[2] -> Oct  31 --> Aug  31 --> May  31 --> Mar  31 --> NULL
H[3] -> Jul  31 --> Jun  30 --> Feb  30 --> Jan  31 --> NULL

Enter a month: Jan
There are 31 days in this month

Continue? : y

Enter a month: Feb
There are 30 days in this month

Continue? : n
Press any key to continue . . .
---------------------------------------------------------------------*/