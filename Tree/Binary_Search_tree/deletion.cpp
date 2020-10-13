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

	
bool search(node* root, int key){

	if(root == NULL)
		return false;

	if(root->data == key)
		return true;

	else if(root->data > key){
		search(root->left, key);
	}
	else{
		search(root->right, key);
	}
}

node* deleteinBST(node* root, int data){
     if(root==NULL){
          return NULL;
     }

     else if(data < root->data){
        root->left = deleteinBST(root->left, data);
        return root;
     }

     else if(data == root->data){
        //found the node to delete 3 cases
        //1. Node with 0 children - leaf node
        if(root->left == NULL && root->right==NULL){
             delete root;
             return NULL;
        }

        //2. Case only 1 child
        if(root->left!=NULL && root->right==NULL){
        	node* temp = root->left;
        	delete root;
        	return temp;
        }
        if(root->right!=NULL && root->left==NULL){
        	node* temp = root->right;
        	delete root;
        	return temp;
        }

        //3. Case with 2 children
        node* replace = root->right;

        while(replace->left!=NULL){ //find the inorder successor
            replace = replace->left;
        }
        root->data = replace->data; //replace root data with inorder successor
        
          //delete the node from right sub tree
        root->right = deleteinBST(root->right, replace->data);

        return root;

     }

     else{
         root->right = deleteinBST(root->right, data);
        return root;
     }
}


int main(){

	node* root = Create_BST();
    root = deleteinBST(root,3);
	return 0;
}