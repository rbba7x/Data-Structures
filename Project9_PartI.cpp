#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class BST
{
private:
	struct node
	{
		string monthName;
		int noDays;
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
	void insert(int days, string month, node*& r)
	{
		if (r == NULL)
		{
			r = new node;
			r->noDays = days;
			r->monthName = month;
			r->left = r->right = NULL;
		}
		else
		{
			if (days < r->noDays)
				insert(days, month, r->left);
			if (days > r->noDays)
				insert(days, month, r->right);
		}
	}

	void search(node* r, string x)
	{
		if (r == NULL) { cout << "X is not found"; return; }
		else if (r->monthName == x) { cout << x <<" is found"; return; }

		else
		{
			if (x < r->monthName) {
				search(r->left, x);
				if (x > r->monthName) {
					search(r->right, x);
				}
			}
		}
	}
			

	void insert(int n, string x) { insert(n, x, root); }
	void search(string x) { search(root, x); }

}; //End of BST class


int main()
{
	BST A;

	ifstream inStream;
	ofstream outStream;
	
	inStream.open("Infile.txt"); 
	
	//Insert data into binary search tree
	


	system("pause");
	return 0;
}


