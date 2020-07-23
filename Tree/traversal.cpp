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

void pre_order(node* root){
	if(root == NULL)
		return;

	cout << root->data <<" ";
	pre_order(root-> left);
	pre_order(root->right);
}
void in_order(node* root){
	if(root == NULL)
		return;

	in_order(root->left);
	cout<<root->data<<" ";
	in_order(root->right);
}
void post_order(node* root){
	if(root == NULL)
		return;

	post_order(root->left);
	post_order(root->right);
	cout << root->data <<" ";
}


int main(){
	node* root = CreateTree();
	pre_order(root);
	in_order(root);
	post_order(root);
	
	return 0;
}