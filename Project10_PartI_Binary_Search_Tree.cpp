//---------------------------------------------------------------------------------------
//			Name: Ryan Beebe
//	                Project: No. 8 Part II
//			Course: CMPS 385
//		   	Due: 5/2/2018
//
// Purpose: This project accepts input of an ID, name, and account balance and places the 
//          information in 2 binary search trees: 1 based on name, 1 based on I.D. The 
//          user can search for nodes in the tree, alter the information, or display the
//          trees.
//---------------------------------------------------------------------------------------


#include <iostream>
#include <string>
using namespace std;

class BST
{
private:
	struct node
	{
		int id;
		string name;
		float balance;
		node* left, *right;
	};
	node *root;

public:
	BST()
	{
		root = NULL;
	}

	//Insert x into treebased on I.D.
	void insert1(int id, float balance, string name, node*& r)
	{
		if (r == NULL)
		{
			r = new node;
			r->id = id;
			r->name = name;
			r->balance = balance;
			r->left = r->right = NULL;
		}
		else
		{
			if (id < r->id)
				insert1(id, balance, name, r->left);
			if (id > r->id)
				insert1(id, balance, name, r->right);
		}
	}

	//Insert x into treebased on name
	void insert2(int id, float balance, string name, node*& r)
	{
		if (r == NULL)
		{
			r = new node;
			r->id = id;
			r->name = name;
			r->balance = balance;
			r->left = r->right = NULL;
		}
		else
		{
			if (name < r->name)
				insert2(id, balance, name, r->left);
			if (name > r->name)
				insert2(id, balance, name, r->right);
		}
	}

	//Search for person based on name
	void searchName(node* r, string x)
	{
		if (r == NULL) { cout << "This item is not found"; return; }
		else if (r->name == x) { cout << x << " has a balance of: $" << r->balance << endl; return; }

		else
		{
			if (x < r->name)
				searchName(r->left, x);
				if (x > r->name)
					searchName(r->right, x);
			}
		}

	//Search for person based on name
	void searchId(node* r, int x)
	{
		if (r == NULL) { cout << "This item is not found"; return; }
		else if (r->id == x) { cout << x << " has a balance of: $" << r->balance << endl; return; }

		else
		{
			if (x < r->id)
				searchId(r->left, x);
			if (x > r->id)
				searchId(r->right, x);
		}
	}

	void deposit(int id, float x, node* r)
	{
		if (r == NULL) { cout << "This item is not found"; return; }
		else
		r->balance += x;
		if (r->id == id) { cout << id << " now has a balance of: $" << r->balance; return; }

		else
		{
			if (id < r->id)
				deposit(id, x, r->left);
			if (id > r->id)
				deposit(id, x, r->right);
		}
	}

	void withdrawl(string name, float x, node* r)
	{
		if (r == NULL) { cout << "This item is not found"; return; }
		else
			r->balance -= x;
		if (r->name == name) { cout << x << "now has a balance of: $" << r->balance; return; }

		else
		{
			if (name < r->name)
				withdrawl(name, x, r->left);
			if (name > r->name)
				withdrawl(name, x, r->right);
		}
	}

	//Display BST using  inorder traversal: (LC)(P)(RC)
	void displayInorder(node* r)
	{
		if (r != NULL)
		{
			displayInorder(r->left);//(LC)
			cout << "Id: " << r->id << "|  Name: " << r->name << "| Balance: " << r->balance << " ";//(P)
			displayInorder(r->right);//(RC)
		}
	}

	void insert1(int n, float balance, string x) { insert1(n, balance, x, root); }
	void insert2(int n, float balance, string x) { insert2(n, balance, x, root); }
	void searchName(string x) { searchName(root, x); }
	void searchId(int x) { searchId(root, x); }
	void deposit(int num, float y) { deposit(num, y, root); }
	void withdrawl(string name, float y) { withdrawl(name, y, root); }
	void displayInorder() { displayInorder(root); }

}; //End of BST 

int main()
{
	BST Id, Name;
	string name;
	int id, resp;
	float balance, deposit, withdrawl;
	char ans = 'y';

	for (int i = 1; i <=5; i++)
	{
		cout << "What is the id, balance, and, name of person " << i << " ?" << endl;
		cin >> id;
		cin >> balance;
		cin >> name;
		Id.insert1(id, balance, name);
		Name.insert2(id, balance, name);
	}

	cout << "------ULV Bank------" << endl;
	cout << "1: Show balance when I.D. is given\n2:Show balance when name is given\n3:Deposit when I.D. is given\n4:Withdrawl when name is given\n5: Display both trees\n";

	while (ans == 'y' || ans == 'Y')
	{
		cout << "Make a selection: ";
		cin >> resp;

		switch (resp)
		{
		case 1:
			cout << "Enter and Id to search for: ";
			cin >> id;
			Id.searchId(id);
			break;

		case 2:
			cout << "Enter a name to search for: ";
			cin >> name;
			Name.searchName(name);
			break;

		case 3:
			cout << "Enter and Id to deposit to: ";
			cin >> id;
			cout << "Enter amount to deposit: ";
			cin >> deposit;
			Id.deposit(id, deposit);
			cout << endl;
			break;

		case 4:
			cout << "Enter a name to withdrawl from: ";
			cin >> name;
			cout << "Enter amount to withdrawl: ";
			cin >> withdrawl;
			Name.withdrawl(name, withdrawl);
			cout << endl;
			break;
		
		case 5:
			cout << "I.D. tree ------ ";
			Id.displayInorder();
			cout << endl;
			cout << "Name tree ------ ";
			Name.displayInorder();
			cout << endl;
			break;
			

		}

		cout << "Continue(y/n)?" << endl;
		cin >> ans;
	}

	system("pause");
	return 0;
}

/*----------------------Output---------------------------
What is the id, balance, and, name of person 1 ?
11
111.11
Mejia,Arnold
What is the id, balance, and, name of person 2 ?
33
33.33
Garcia,Kevin
What is the id, balance, and, name of person 3 ?
55
55.55
Nguyen,Duc
What is the id, balance, and, name of person 4 ?
44
444.44
Ehara,Jordan
What is the id, balance, and, name of person 5 ?
66
66.66
Li,Yan
------ULV Bank------
1: Show balance when I.D. is given
2:Show balance when name is given
3:Deposit when I.D. is given
4:Withdrawl when name is given
5: Display both trees
Make a selection: 1
Enter and Id to search for: 55
55 has a balance of: $55.55
Continue(y/n)?
y
Make a selection: 2
Enter a name to search for: Mejia,Arnold
Mejia,Arnold has a balance of: $111.11
Continue(y/n)?
y
Make a selection: 3
Enter and Id to deposit to: 11
Enter amount to deposit: 10
11 now has a balance of: $121.11
Continue(y/n)?
y
Make a selection: 4
Enter a name to withdrawl from: Li,Yan
Enter amount to withdrawl: 60
60now has a balance of: $6.66
Continue(y/n)?
y
Make a selection: 5
I.D. tree ------ Id: 11|  Name: Mejia,Arnold| Balance: 121.11 Id: 33|  Name: Garcia,Kevin| Balance: 33.33 Id: 44|  Name: Ehara,Jordan| Balance: 444.44 Id: 55|  Name: Nguyen,Duc| Balance: 55.55 Id: 66|  Name: Li,Yan| Balance: 66.66
Name tree ------ Id: 44|  Name: Ehara,Jordan| Balance: 444.44 Id: 33|  Name: Garcia,Kevin| Balance: -26.67 Id: 66|  Name: Li,Yan| Balance: 6.66 Id: 11|  Name: Mejia,Arnold| Balance: 51.11 Id: 55|  Name: Nguyen,Duc| Balance: 55.55
Continue(y/n)?
-----------------------------------------------------------------------------------------*/
