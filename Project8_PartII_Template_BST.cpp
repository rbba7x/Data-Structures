//--------------------------------------------------------------------------------------------------------
//				Name: Ryan Beebe
//				Project: No. 8 Part II
//				Course: CMPS 385
//				Due: 4/18/2018
//
// Purpose: This project initializes arrays of 3 different data types and puts them into a template binary 
//          tree. Then the arrays are displayed in preorder
//--------------------------------------------------------------------------------------------------------

#include  <iostream>
#include <string>
using namespace std;

template <class T, int n>
class BST
{
private:
	struct node
	{
		T info;
		node* left;
		node* right;
	};
	node *root;

public:
	BST()
	{
		root = NULL;
	}

	//Insert x into tree
	void insert(T x, node*& r)
	{
		if (r == NULL)
		{
			r = new node;
			r->info = x;
			r->left = r->right = NULL;
		}
		else
		{
			if (x < r->info)
				insert(x, r->left);
			if (x > r->info)
				insert(x, r->right);
		}
	}

	//Display BST using  inorder traversal: (LC)(P)(RC)
	void displayInorder(node* r)
	{
		if (r != NULL)
		{
			displayInorder(r->left);//(LC)
			cout << r->info << "  ";//(P)
			displayInorder(r->right);//(RC)
		}
	}


	//Display BST using  preorder traversal: (P)(LC)(RC)
	void displayPreorder(node* r)
	{
		if (r != NULL)
		{
			cout << r->info << "  ";//(P)
			displayInorder(r->left);//(LC)
			displayInorder(r->right);//(RC)
		}
	}

	void inorder(T x) { insert(x, root); }
	void displayPreorder() { displayPreorder(root); }

}; //End of BST class

int main()
{
	string months[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
	int a[7] = { 4,9,10,2,7,20,6 };
	char c[5] = { 'e','o','a','u', 'i', };
	BST <string, 12> month;
	BST <int, 7> A;
	BST <char, 5> C;

	//Insert data into binary search tree
	for (int i = 0; i < 12; i++)
		month.inorder(months[i]);

	for (int i = 0; i < 7; i++)
		A.inorder(a[i]);


	for (int i = 0; i < 5; i++)
		C.inorder(c[i]);

	//Display BST using preorder traversal
	cout << "Preorder Traversal of Months: ";
	month.displayPreorder();
	cout << endl;

	cout << "Preorder Traversal of a: ";
	A.displayPreorder();
	cout << endl;

	cout << "Preorder Traversal of c: ";
	C.displayPreorder();
	cout << endl;

	cout << endl;

	system("pause");
	return 0;
}

/*-----------------------------------Output----------------------------------------------
Preorder Traversal of Months: Jan  Apr  Aug  Dec  Feb  Jul  Jun  Mar  May  Nov  Oct  Sep
Preorder Traversal of a: 4  2  6  7  9  10  20
Preorder Traversal of c: e  a  i  o  u

Press any key to continue . . .
----------------------------------------------------------------------------------------*/
