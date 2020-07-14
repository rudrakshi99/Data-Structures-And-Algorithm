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

node* CreateTree(){
	int data;
	cin  >> data;
	if(data == -1){
        return NULL;
	}
	else{
       node* root = new node(data);
       cout <<"Enter left child of "<<data<<"\n";
       root->left = CreateTree();
       cout <<"Enter right child of "<<data<<"\n";
       root->right = CreateTree();

       return root;
	}

}

int height(node* root){
	if(root == NULL)
		return 0;

	int left_height = height(root->left);

	int right_height = height(root->right);

	return max(left_height, right_height) + 1;

}

// time complexity O(n^2)
int diameter(node* root){
	if(root == NULL)
		return 0;

	int op1 = height(root->left) + height(root->right); //passing through root node

	int op2 = diameter(root->left); // left tree

	int op3 = diameter(root->right);  //right tree

	return max(op1, max(op2, op3));

}


int main(){
	node* root = CreateTree();
	cout << diameter(root);
	return 0;
}