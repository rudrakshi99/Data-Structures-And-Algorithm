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

// time complexity O(N)
bool is_bst(node* root, int mini=INT_MIN, int maxi=INT_MAX){

	if(root == NULL)
		return true;

	if((root->data >=mini && root->data <= maxi ) && is_bst(root->left,mini,root->data) && is_bst(root->right,root->data, maxi)) //check root, (left, right)
       return true;
   else
   	 return false;
}


int main(){

	node* root = Create_BST();
    cout << boolalpha << is_bst(root);
	return 0;
}