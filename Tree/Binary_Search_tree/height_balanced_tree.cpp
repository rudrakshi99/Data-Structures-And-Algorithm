// |h1 - h2| <=1 at every node

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


class HBPair{
public:
	int height;
	bool balance;
};

bool isheightbalance(node* root){

	HBPair p;

	if(root==NULL){
		p.height = 0;
		p.balance = true;
		return p;
	}
	//Recursive case - post order traversal
	HBPair left = isheightbalance(root->left);
	HBPair left = isheightbalance(root->right);

	p.height = max(left.height,right.height) +1;

	if(abs(left.height-right.height)<=1 && left.balance && right.balance){
         p.balance = true;
	}
	else{
        p.balance = false;
	}

	return p;
}
int main(){

	node* root = Create_BST();
    cout << boolalpha << isheightbalance(root).balance;
	return 0;
}