#include<iostream>
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
    int find(int inorder[],int inS,int inE,int k)
    {
        for(int i = inS;i<=inE;i++)
        {
            if(inorder[i] == k)
            {
                return i;
            }
        }
    }
    Node * BuildTree(int inorder[],int preorder[],int inS,int inE,int preS,int preE)
    {
        if(inS>inE)
        {
            return NULL;
        }
        int data = preorder[preS];
        Node * root = new Node(data);
        if(inS == inE)
        {
            return root;
        }
        int index = find(inorder,inS,inE,data);

        root->left = BuildTree(inorder,preorder,inS,index-1,preS+1,preS+index-inS);
        root->right = BuildTree(inorder,preorder,index+1,inE,preS+index-inS+1,preE);

        return root;
    }
    void inorder(Node * root)
    {
        if(root ==NULL){
            return ;
        }
        else{
            inorder(root->left);
            cout<<root->data<<"  ";
            inorder(root->right);
        }
    }

    void preorder(Node * root)
    {
        if(root ==NULL){
            return ;
        }
        else{
            cout<<root->data<<"  ";
            preorder(root->left);
            preorder(root->right);
        }
    }

public:
    BinaryTree(){
        root = NULL;
    }
    void BuildTree(int inorder[],int preorder[],int size)
    {
        root = BuildTree(inorder,preorder,0,size-1,0,size-1);
    }
    void inorder()
    {
        inorder(root);
        cout<<endl;
    }
    void preorder()
    {
        preorder(root);
        cout<<endl;
    }
};

int main(){
    int inorder[9] = {4,2,5,1,8,6,9,3,7};
    int preorder[9] = {1,2,4,5,3,6,8,9,7};
    BinaryTree b;
    b.BuildTree(inorder,preorder,9);

    b.inorder();
    b.preorder();

}