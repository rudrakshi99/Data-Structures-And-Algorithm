//replace each node by sum of nodes (do not change leaf nodes)
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

void Level_order_output(node* root){
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* temp = q.front();
		q.pop();

		cout << temp->data<<" ";

		if(temp->left){
			q.push(temp->left);
		}
		if(temp->right){
			q.push(temp->right);
		}
		if(q.front()==NULL){
			cout<<"\n";

			q.pop();

			if(!q.empty()){
				q.push(NULL);
			}
		}
	}
}

int replacesum(node* root){
   if(root==NULL){
      return 0;
   }
   if(root->left==NULL && root->right==NULL){ // leaf nodes
       return root->data;
   }

   //Recursive part - post order traversal (bottom up approach)

   int leftsum = replacesum(root->left);
   int rightsum = replacesum(root->right);

   int temp = root->data; // storing current node
   root->data = leftsum + rightsum; // change by sum of childnodes

   return temp + root->data; // current node + child nodes

}

int main(){

	node* root = Level_order_input();
	replacesum(root);
	Level_order_output(root);
	return 0;
}