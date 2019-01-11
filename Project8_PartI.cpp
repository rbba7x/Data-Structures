//--------------------------------------------------------------------------------------------------------
//								Name: Ryan Beebe
//							  Project: No. 8 Part I
//								Course: CMPS 385
//								 Due: 4/18/2018
//
// Purpose: This project initializes an array of characters then displays the preorder traversal, postorder 
//          traversal, and inorder traversal.
//--------------------------------------------------------------------------------------------------------

#include  <iostream>
using namespace std;

class BST
{
private:
	struct node
	{
		char info;
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
	void insert(char x, node*& r)
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
		char letter;
		if (r != NULL)
		{
			displayInorder(r->left);//(LC)
			cout << r->info << "  ";//(P)
			displayInorder(r->right);//(RC)
		}
	}

	//Display BST using  postorder traversal: (LC)(RC)(P)
	void displayPostorder(node* r)
	{
		if (r != NULL)
		{
			displayPostorder(r->left);//(LC)
			displayPostorder(r->right);//(RC)
			cout << r->info << "  ";//(P)
		}
	}

	//Display BST using  preorder traversal: (P)(LC)(RC)
	void displayPreorder(node* r)
	{
		char letter;
		if (r != NULL)
		{
			cout << r->info << "  ";//(P)
			displayInorder(r->left);//(LC)
			displayInorder(r->right);//(RC)
						
		}
	}



	void inorder(char x) { insert(x, root); }
	void displayInorder() { displayInorder(root); }
	void displayPostorder() { displayPostorder(root); }
	void displayPreorder() { displayPreorder(root); }

}; //End of BST class

int main()
{
	char a[7] = { 'L', 'A', 'V', 'E', 'R', 'N', 'E' };
	BST b;

	//Insert data into binary search tree
	for (int i = 0; i < 7; i++)
		b.inorder(a[i]);

	//Display BST using preorder traversal
	cout << "Preorder Traversal: ";
	b.displayPreorder();
	cout << endl;

	//Display BST using postorder traversal
	cout << "Postorder Traversal: ";
	b.displayPostorder();
	cout << endl;
	
	//Display BST using inorder traversal
	cout << "Inorder Traversal: ";
	b.displayInorder();
	cout << endl;

	cout << endl;
	system("pause");
	return 0;
}

/*-----------------------------------Output-----------------------------
Preorder Traversal: L  A  E  N  R  V
Postorder Traversal: E  A  N  R  V  L
Inorder Traversal: A  E  L  N  R  V

Press any key to continue . . .
----------------------------------------------------------------------*/