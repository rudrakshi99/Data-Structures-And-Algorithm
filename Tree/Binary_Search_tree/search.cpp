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




int main(){

	node* root = Create_BST();
    cout << boolalpha << search(root, 6);
	return 0;
}