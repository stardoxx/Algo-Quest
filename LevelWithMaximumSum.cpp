#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node{
    Node * left;
    Node * right;
    int data;
    public:
        Node(){

        }
    Node(int d)
    {
        left = NULL;
        right = NULL;
        data = d;
    }
    friend class BinaryTree;
};

class BinaryTree{
    Node * root;
    Node * insert(int d, Node * root)
    {
        queue <Node * >q;
        if(root == NULL)
        {
            Node * temp  = new Node(d);
            root = temp;
            return root;
        }
        else{
            q.push(root);
            Node * z ;
            while(!q.empty()){
                z = q.front();
                q.pop();
                if(z->left == NULL)
                {
                    Node * temp  = new Node(d);
                    z->left = temp;
                    return root;
                }else if(z->left!=NULL)
                {
                    q.push(z->left);
                }

                if(z->right == NULL)
                {
                    Node * temp  = new Node(d);
                    z->right = temp;
                    return root;
                }else if(z->right != NULL)
                {
                    q.push(z->right);
                }                
            }
        }

    }

    void preorder(Node * root)
    {
        if(root == NULL)
        {
            return;
        }else{
            cout<<root->data<<"  ";
            preorder(root->left);
            preorder(root->right);
        }
    }
    int maximumSum(Node * root)
    {
        if(root == NULL)
        {
            return -1;
        }else{
            int level = 0 ,maxlevel;
            Node * z;
            queue <Node * > q;
            q.push(root);
            q.push(NULL);
            int currentSum = 0,max = 0;
            while(!q.empty())
            {
                z = q.front();
                q.pop();
                if(z!=NULL)
                {
                    currentSum += z->data;
                    if(z->left != NULL)
                    {
                        q.push(z->left);
                    }
                    if(z->right != NULL)
                    {
                        q.push(z->right);
                    }
                }
                if(z == NULL)
                {
                    if(!q.empty()){
                        q.push(NULL);
                    }
                    ++level;
                    if(currentSum > max)
                    {
                        max = currentSum;
                        maxlevel = level;
                    }
                    currentSum = 0;
                }
            }
            return maxlevel;
        }
    }
    public:
    BinaryTree()
    {
        root = NULL;
    }

    Node * insert(int d)
    {
        root = insert(d,root);
    }
    void preorder()
    {
        preorder(root);
        cout<<endl;
    }
    int maximumSum()
    {
        return maximumSum(root);
    }
};

int main()
{
    BinaryTree b;
    b.insert(10);
    b.insert(3);
    b.insert(400);
    b.insert(100);
    b.insert(1);
    b.insert(1);
    b.insert(1);
    //b.deletion(30);
    b.preorder();
    cout<<b.maximumSum();
}