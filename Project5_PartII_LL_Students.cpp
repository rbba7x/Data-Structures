// -----------------------------------------------------------------------------------------------------------------------------------
//				Name: Ryan Beebe
//				Project: No. 5 Part II
//				Course: CMPS 385
//				Due: 3/14/2018
//
// Purpose: This project asks the user to enter in names, ages, and gpa's which are input into  a linked list. The oldest person's 
//          name and age is displayed. The average gpa is displayed.
//------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

struct node
{
	string name;
	int age;
	float gpa;
	node *next;

};

int main()
{
	node *list;
	node *p;
	list = new(node);
	p = list;

	//Create the linked list
	for (int i = 0; i <= 4; i++)
	{
		cout << "Enter a name: ";
		cin >> p->name;
		cout << "Enter the age: ";
		cin >> p->age;
		cout << "Enter the gpa: ";
		cin >> p->gpa;
		p->next = new(node);
		p = p->next;
	}

	cout << "Enter a name: ";
	cin >> p->name;
	cout << "Enter the age: ";
	cin >> p->age;
	cout << "Enter the gpa: ";
	cin >> p->gpa;
	p->next = NULL;

	cout << endl;

	//Display the linked list
	p = list;
	while (p != NULL)
	{
		cout << p->name << "   " << p->age << "   " << p->gpa << "\n";
		p = p->next;
	}
	cout << endl;

	//Find the largest age in List
	p = list;
	int max = p->age;
	p = p->next;

	while (p != NULL)
	{
		if (p->age>max)
			max = p->age;
		p = p->next;
	}

	cout << "Max Age: " << max << endl;

	//Find the oldest person in  list
	p = list;
	string oldest;

	while (p->age != max)
	{
		p = p->next;
		oldest = p->name;
		
	}
	cout << "Oldest Person: " << oldest << endl;
	
	//Find the average gpa
	p = list;
	float total = 0;
	int counter = 0;

	while (p != NULL)
	{
		total += p->gpa;
		counter++;
		p = p->next;		
	}
	cout << "Average GPA: " << total / counter << endl << endl;

	system("pause");
	return 0;
}

/*-----------------------------Output---------------------------------------
Enter a name: Tom
Enter the age: 21
Enter the gpa: 2.1
Enter a name: Bill
Enter the age: 33
Enter the gpa: 3.3
Enter a name: Jack
Enter the age: 44
Enter the gpa: 2.4
Enter a name: Bin
Enter the age: 15
Enter the gpa: 2.5
Enter a name: Donald
Enter the age: 32
Enter the gpa: 3.2
Enter a name: Mary
Enter the age: 18
Enter the gpa: 3.1

Tom   21   2.1
Bill   33   3.3
Jack   44   2.4
Bin   15   2.5
Donald   32   3.2
Mary   18   3.1

Max Age: 44
Oldest Person: Jack
Average GPA: 2.76667

Press any key to continue . . .
----------------------------------------------------------------------------*/
