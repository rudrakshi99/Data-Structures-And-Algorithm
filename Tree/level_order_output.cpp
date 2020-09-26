// aanother way
// levels == height
//worst case - 	o(n)
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


int height(node* root){
    if(root==NULL){
    	return 0;
    }
    int ls = height(root->left); //left sub-tree
    int rs = height(root->left); //right sub-tree


    return max(ls,rs)+1;
}

int count(node* root){ // total number of nodes  - preorder traversal o(n)
   if(root==NULL){
       return 0;
   }

   return 1 + count(root->left)+count(left->right);
}

void printkthLevel(node *root,int k){ // for particular k level
   if(root==NULL){
       return;
   }
   if(k==1){
      cout<<root->data<<" ";
      return;
   }
   printkthLevel(root->left,k-1);
   printkthLevel(root->right,k-1);
   return;
}

void printAllLevels(node* root){
   int h = height(root);

   for(int i=0;i<=h;i++){
      printAllLevels(root,i);
      cout<<endl;
   }
   return;
}


int main(){

	node* root = Level_order_input();
	printAllLevels(root);
	return 0;
}