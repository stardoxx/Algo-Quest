#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node{
    Node * left;
    Node * right;
    int data;
    public:
    Node(int n)
    {
        data = n;
        left = NULL;
        right = NULL;
    }
    friend class BST;
};
class BST{
    Node * root;
    int findindex(int inorder[],int key,int inS,int inE)
    {
    	int s = -1;
        for(int i=inS;i<=inE;i++)
        {
                if(inorder[i] == key){
                    s = i;
                    break;
                }
        }
        return s;
    }
    Node * createTree(Node * root ,int levelorder[],int inorder[],int currentIndex,int lE,int inS,int inE )
    {
    	if(currentIndex<=lE || inS<=inE)
    	{
    		int index = findindex(inorder ,levelorder[currentIndex],inS,inE );
    		if(index!=-1)
    		{
    			Node * temp = new Node(levelorder[currentIndex]);
    			++currentIndex;
    			root = temp;
    			root->left = createTree(root->left , levelorder,inorder,currentIndex,lE,inS,index-1);
    			root->right = createTree(root->right , levelorder,inorder,currentIndex,lE,index+1,inE);
    			return root;
    		}
    		else{
    			++currentIndex;
    			root = createTree(root,levelorder,inorder,currentIndex,lE,inS,inE);
    			return root;
    		}
    	}else{
    		return NULL;
    	}
    }
    void inOrder(Node *root) 
	{ 
    	if(root != NULL) 
    	{ 
        	inOrder(root->left); 
        	cout<< root->data<<" "; 
        	inOrder(root->right); 
    	}	 
	}
	void preOrder(Node *root) 
	{ 
    	if(root != NULL) 
    	{ 
        	cout<< root->data<<" "; 
        	preOrder(root->left); 
        	preOrder(root->right); 
    	}	 
	}	
    public:
    BST()
    {
        root = NULL;
    }

    void createTree(int levelorder[],int inorder[],int currentIndex,int lE,int inS,int inE )
    {
        root = createTree(root,levelorder,inorder,currentIndex,lE,inS,inE);
    }
    void prin()
    {
    	cout<<"INORDER >>"<<endl;
    	inOrder(root);
    	cout<<endl<<"preOrder >>"<<endl;
    	preOrder(root);
    	cout<<endl;
    }
};


int main()
{
	int levelorder[9] = {40,30,20,100,62,70,44,80,90};
	int inorder[9] = {100,44,30,40,62,80,20,90,70};
	BST b;
	b.createTree(levelorder,inorder , 0,8,0,8);
	b.prin();
}