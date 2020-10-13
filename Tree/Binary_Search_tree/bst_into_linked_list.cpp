// Flatten a BST
//convert into sorted linked list
//postorder traversal
#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	node(int x){ // constructor
		data = x;
		left = NULL;
		right = NULL;
	}

};

node* Insert_into_bst(node* root, int data){

	if(root == NULL){
		root = new node(data);
		return root;
	}

	else if(data < root->data){
        root->left = Insert_into_bst(root->left,data);
	}
	else{
        root->right = Insert_into_bst(root->right,data);
	}

	return root;
}
node* Create_BST(){

	int data; // root node
	cin >> data;

	node* root = NULL;

	while(data!= -1){
		root = Insert_into_bst(root, data);
		cin >> data;
	}

	return root;
}

class LinkedList {
public:
	node* head;
	node* tail;
  
};

LinkedList flatten(node* root){
      LinkedList l;

      if(root==NULL){ //empty tree
         l.head = l.tail = NULL;
         return l;
      }

      //Leaf node
      if(root->left == NULL && root->right==NULL){
           l.head = l.tail = root;
           return l;
      }

      //Leaf is not null
      if(root->left!=NULL && root->right==NULL){
          LinkedList leftLL = flatten(root->left);
          leftLL.tail->right = root; //connect tail with root
          
          //new head and tail
          l.head = leftLL.head;
          l.tail = root;
          return l;

      }

      //Right is not null
      if(root->left==NULL && root->right!=NULL){
          LinkedList rightLL = flatten(root->right);
          root->right = rightLL.head; //connect right head with root
          
          //new head and tail
          l.head = root;
          l.tail = rightLL.tail;
          return l;

      }
      
      //Both sides are not null
      LinkedList leftLL = flatten(root->left);
      LinkedList rightLL = flatten(root->right);

      leftLL.tail->right = root;
      root->right = rightLL.head;

      l.head = leftLL.head;
      l.tail = rightLL.tail;
      return l;
}

int main(){

	node* root = Create_BST();
	LinkedList l = flatten(root);
	node*temp = l.head;

	while(temp!=NULL){
        cout<<temp->data <<"->"ws;
        temp = temp->right;
	}
	return 0;
}