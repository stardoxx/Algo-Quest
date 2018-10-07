#include<iostream>
#include<queue>
#include<map>
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
    void verticalSumUtill(Node * root,map<int,int> &Map,int hd)
    {
        if(root == NULL)
        {
            return;
        }
        verticalSumUtill(root->left,Map , hd - 1);
        Map[hd] += root->data;

        verticalSumUtill(root->right,Map,hd + 1);
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
    void verticalSum()
    {
        map <int,int> Map;
        map <int,int>::iterator it;
        verticalSumUtill(root,Map,0);
        for(it = Map.begin();it!=Map.end();it++)
        {
            cout<<it->first<<" : "<<it->second<<endl;
        }
    }
};

int main()
{
    BinaryTree b;
    b.insert(1);
    b.insert(2);
    b.insert(3);
    b.insert(4);
    b.insert(5);
    b.insert(6);
    b.insert(7);
    b.insert(8);
    b.insert(9);
    b.insert(10);
    b.insert(11);
    b.insert(12);
    b.insert(13);
    b.insert(14);
    b.insert(15);
    b.verticalSum();
}