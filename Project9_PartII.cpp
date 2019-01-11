#include <iostream>
#include <string>
using namespace std;


class BST
{
private:
	struct node
	{
		int info;
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
	void insert(int x, node*& r)
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
			displayPreorder(r->left);//(LC)
			displayPreorder(r->right);//(RC)
		}
	}

	void displayPostorder(node* r)
	{
		if (r != NULL)
		{
			displayPostorder(r->left);//(LC)
			displayPostorder(r->right);//(RC)
			cout << r->info << "  ";//(P)		

		}
	}


	void displayLeaves(node* r)
	{
		if (r != NULL)
		{
			//preorder
			if (r->left == NULL && r->right == NULL)
				cout << r->info << " ";
			displayLeaves(r->left);
			displayLeaves(r->right);
		}
	}

	void computeTotal(node* r, int &total)
	{
		if (r != NULL)
		{
			//postorder (lc rc p) 
			computeTotal(r->left, total);
			computeTotal(r->right, total);
			total += r->info;
		}
	}

	void countNodes(node* r, int& c)
	{
		//preorder (p lc rc)
		if (r != NULL)
		{
			c++; //p
			countNodes(r->left, c);
			countNodes(r->right, c);
		}

	}

	//Display nodes  with 2 children
	void displayTwoChildrenNodes(node *r)
	{
		if (r->left &&r->right)
		{
			cout << r->info << " ";

			if (r->left != NULL && r->right != NULL)
				displayTwoChildrenNodes(r->right);
			return;
		}
	}


	void countNodes(int& c) { countNodes(root, c); }
	void computeTotal(int &total) { computeTotal(root, total); }
	void insert(int n) { insert(n, root); }
	void inorder(int x) { displayInorder(root); }
	void displayPreorder() { displayPreorder(root); }
	void displayInorder() { displayInorder(root); }
	void displayPostorder() { displayPostorder(root); }
	void displayLeaves() { displayLeaves(root); }
	void displayTwoChildrenNodes() { displayTwoChildrenNodes(root); }
}; //End of BST class

int main()
{
	int a[6] = { 25,36,9,2,17,40 };
	BST A;

	//Insert data into binary search tree
	for (int i = 0; i < 6; i++)
		A.insert(a[i]);

	//Display BST using preorder traversal
	cout << "Preorder Traversal: ";
	A.displayPreorder();
	cout << endl;

	//Display BST using inorder traversal
	cout << "Inorder Traversal: ";
	A.displayInorder();
	cout << endl;

	//Display BST using postorder traversal
	cout << "Postorder Traversal: ";
	A.displayPostorder();
	cout << endl;

	int c = 0;
	A.countNodes(c);
	cout << "Number of nodes: " << c << endl;
		
	int total = 0;
	A.computeTotal(total);
	cout << "Total=" << total << endl;
	

	cout << "All leaves: ";
	A.displayLeaves();
	cout << endl;

	cout << "Nodes with 2 children: ";
	A.displayTwoChildrenNodes();
	cout << endl;

	system("pause");
	return 0;
}


