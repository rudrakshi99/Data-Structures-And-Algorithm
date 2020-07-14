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

int cnt_Node(node* root){
	if(root == NULL)
		return 0;
	int x = cnt_Node(root->left); //count left tree nodes
	int y = cnt_Node(root->right); //count right tree nodes

	return x+y+1; // left+right+root;
}



int main(){
	node* root = CreateTree();
	cout<<cnt_Node(root);
	return 0;
}