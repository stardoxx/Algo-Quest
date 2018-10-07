#include<iostream>
using namespace std;
#include<vector>
#include"bnode.h"
#include<queue>
#include<algorithm>
#include<stack>
//to count no. of nodes in a binary tree
int countNodes(binary* root){
  if(root == NULL){
    return 0;
  }
  int sum = countNodes(root->left);
  sum += countNodes(root->right);
  return 1+sum;
}
//mirror a binary tree left subtree becomes right subtree
void mirror(binary * root){
  if(root == NULL){
    return ;
  }
  mirror(root->left);
  mirror(root->right);
  binary * temp  =  root->left;
  root->left = root->right;
  root->right = temp;
  }

//construct a binary tree from inorder and preorder information of tree
/*binary* buildTree(vector<int> pre,vector<int>in){
  if(pre.size() == 1 && in.size() == 1){
    binary* newroot = new binary(pre[0]);
    return newroot;
  }
  int rootdata = pre[0];
  binary* root = new binary(rootdata);
  vector<int> inA;
  vector<int> preA;
  vector<int> inB;
  vector<int> preB;
  int i =0;
  while(in[i] != rootdata){
    inA.push_back(in[i]);
    i++;
  }
  while()

}*/

//iterative version of inorder
void nonRecurInorder(binary* root){
 if(root == NULL){
   return ;
 }
 stack<binary *> s;
 s.push(root);
  binary* temp = s.top();
 while(!s.empty() || temp){

   s.pop();
   cout<<temp->data<<endl;
   if(temp->right != NULL){
     s.push(root->right);
   }
   if(temp->left != NULL){
     s.push(root->left);
   }
 }
}

int maxInBinary(binary* root){
  if(root == NULL){
    return 0;
  }
  int l =  maxInBinary(root->left);
  int r = maxInBinary(root->right);
  int maximum = max(l,r);
  if(root->data > maximum){
    return root->data;
  }
  else{
    return maximum;
  }
}
//searching in binary tree
bool search(binary* root,int data){
  if(root == NULL){
    return false;
  }
  if(root->data == data){
    return true;
  }
  bool out = search(root->left,data)||search(root->right,data);
}
//size of a binary tree
int size(binary* root){
  if(root == NULL){
    return 0;
  }
  return size(root->left)+size(root->right)+1;
}
//reverse level order printing of a tree
void printReverseLevel(binary* root){
  if(root == NULL){
    return ;
  }
  stack<binary *> s;
  queue<binary *> q;
  q.push(root);
  while(q.size() != 0){
    binary* node = q.front();
    q.pop();
    if(node->right){
      q.push(node->right);
    }
    if(node->left){
      q.push(node->left);
    }
    s.push(node);
  }
  while(s.size() != 0){
    binary* node = s.top();
    s.pop();
    cout<<node->data<<" ";
  }
}
//deleting node in a binary tree
void deleteTree(binary* root){
  if(root == NULL){
    return ;
  }
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}
//height of binary tree
int height(binary* root){
  if(root == NULL){
    return 0;
  }
  return 1+height(root->left)+height(root->right);
}
//node at deepest node of a binary tree
binary* deepestNode(binary* root){
  if(root == NULL){
    return root;
  }
  queue<binary *>q;
  q.push(root);
    binary* temp;
  while(q.size() != 0){
     temp = q.front();
    q.pop();
    if(temp->left){
      q.push(temp->left);
    }
    if(temp->right){
      q.push(temp->right);
    }

  }
  return temp;
}
//find function for a node
binary* find(binary * root,int data){
  if(root == NULL){
    return root;
  }
}
// is structures are identical ?
bool identical(binary* root1,binary* root2){
  if(root1 == NULL && root2 == NULL){
    return true;
  }
  if(root1 == NULL || root2 == NULL){
    return false;
  }
  if(root1->data != root2->data){
    return false;
  }
  bool output1 = identical(root1->left,root2->left);
  bool output2 = identical(root1->right,root2->right);
  return output1 && output2;
}
//print vector
void printV(vector <int> v){
  for(int i = 0;i<v.size();i++){
    cout<<v[i]<<" ";
  }
}
//root to leaf path
void leafPath(binary* root,vector<int> v){
  if(root == NULL){
    return ;
  }
  v.push_back(root->data);
  if(root->left == NULL && root->right == NULL){
    printV(v);
    cout<<endl;
  //  return ;
  }
  else{
    leafPath(root->left,v);
    leafPath(root->right,v);
  }
}
//checking path with a given sum
bool leafSumPath(binary* root,int sum){
  if(root == NULL && sum == 0){
    return true;
  }
  if(root == NULL || sum == 0){
    return false;
  }
  bool output1 = leafSumPath(root->left,(sum-(root->data)));
  bool output2 = leafSumPath(root->right,(sum-(root->data)));
  return output1 || output2;
}
//total sum of elements
int sumOfNodes(binary* root){
  if(root == NULL){
    return 0;
  }
  int sum = root->data;
  sum += sumOfNodes(root->left);
  sum += sumOfNodes(root->right);
  return sum;
}
//checking whether two trees are mirror
bool checkMirror(binary* root1,binary *root2){
  if(root1 == NULL && root2 == NULL){
    return true;
  }
  if(root1 == NULL || root2 == NULL){
    return false;
  }
  if(root1->data != root2->data){
    return false;
  }
  return checkMirror(root1->left,root2->right) && checkMirror(root1->right,root2->left);

}
//lowest common ancestor of two nodes
   ///******important****///
int lca(binary* root,int a,int b){
  if(root == NULL){
    return 0;
  }
  if(root->data == a || root->data == b){
    return root->data;
  }
  int left,right;
  left = lca(root->left,a,b);
  right = lca(root->right,a,b);
  if(left && right){
    return root->data;
  }
  else{
    return (left?left:right);
  }
}
//all ancestor of a given node
int nodeAncestor(binary* root,int data){
  if(root == NULL){
    return 0;
  }
  if(root->left->data == data || root->right->data == data || nodeAncestor(root->left,data)|| nodeAncestor(root->right,data)){
      cout<<root->data<<endl;
      return 1;
  }
  return 0;
}
//depth first search for above question
bool dfsAncestor(binary* root,int data){
  if(root == NULL){
    return false;
  }
  bool left = dfsAncestor(root->left,data);
  bool right = dfsAncestor(root->right,data);
  if(left || right){
    cout<<root->data<<endl;
    return true;
  }
  if(root->data == data){
  //  cout<<root->data<<endl;
    return true;
  }
  return false;
}

int main(){
  //tree1
 binary* root = new binary(10);
 root->left = new binary(8);
 root->right = new binary(2);
 root->left->left = new binary(3);
 root->left->right = new binary(5);
 root->right->left = new binary(13);
  //tree2
  /*
  binary* root1 = new binary(10);
   root1->left = new binary(8);
   root1->right = new binary(2);
   root1->left->left = new binary(3);
  root1->left->right = new binary(5);
  root1->right->left = new binary(12);
  */nonRecurInorder(root);/*
  //cout<<maxInBinary(root)<<endl;
//  cout<<search(root,2)<<" "<<search(root,18)<<endl;
//  cout<<"size of binary tree: "<<size(root)<<endl;
//  deleteTree(root);
//  printReverseLevel(root);
// binary * temp = deepestNode(root);
 //cout<<temp->data<<endl;
 cout<<identical(root,root1)<<endl;*/
  //vector<int> v;
  //leafPath(root,v);
//  cout<<leafSumPath(root,10)<<endl;
//  cout<<lca(root,3,5)<<endl;
// int x = dfsAncestor(root,5);
}
