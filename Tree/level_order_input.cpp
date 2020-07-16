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



void in_order(node* root){
	if(root == NULL)
		return;

	cout << root->data <<" ";
	in_order(root-> left);
	in_order(root->right);
}
	

node* Level_order_input(){
	int data;
	cin >> data;
    if(data==-1)
    	return NULL;
	node* root = new node(data);

	queue<node*> q;

	q.push(root);

	while(!q.empty()){
		node* temp = q.front();
        cin >> data; // left child

        if(data!= -1){
        	temp->left = new node(data);

        	q.push(temp->left);
        }

	//right child
	cin >> data;
	if(data!= -1){
		temp->right = new node(data);
		q.push(temp->right);
	}
	q.pop();
   }

   return root;
}

int main(){

	node* root = Level_order_input();
		in_order(root);
	return 0;
}