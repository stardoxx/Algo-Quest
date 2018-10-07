#include<iostream>
using namespace std;

/* Two Trees are said to be isomorphic if
   they have same structure regardless of
   node data
*/


struct Node
{
	Node * left;
	Node * right;
	int data;
};


Node * insert(Node * root,int d)
{
	if(root == NULL)
	{
		Node * temp = new Node;
		temp->data = d;
		temp->left = NULL;
		temp->right = NULL;
	}
}

bool isIsomorphic(Node * root1,Node * root2)
{
	if(root1 == NULL && root2 == NULL)
	{
		return true;
	}
	if((!root1->left && root2->left) || (!root2->left && root1->left) || (isIsomorphic(root1->left,root2->left) == false))
	{
		return false;
	}
	if((!root1->right && root2->right) || (!root2->right && root1->right) || (isIsomorphic(root1->right,root2->right) == false))
	{
		return false;
	}
	return true;
}

int main()
{
	Node * root1;
	Node * root2;
	root1 = insert(root1,1);
	root1 = insert(root1->left,1);
	root1 = insert(root1->left->left,1);
	root1 = insert(root1->right,1);
	root1 = insert(root1->right->left,1);
	root1 = insert(root1->right->left->left,1);
	
	root2 = insert(root2,1);
	root2 = insert(root2->left,1);
	root2 = insert(root2->left->right,1);
	root2 = insert(root2->left->right->right,1);
	root2 = insert(root2->right ,2);
	root2 = insert(root2->right->left,1);
	root2 = insert(root2->right->left->left,1);
		

	cout<<isIsomorphic(root1,root2);	
}