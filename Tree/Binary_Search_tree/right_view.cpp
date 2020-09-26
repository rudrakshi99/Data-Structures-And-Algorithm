//print last node of each level
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
void rightview(node* root, int level,int &maxlevel){
   
   if(root==NULL){
      return ;
   }

   if(maxlevel<level){
      //we have discovered a new level
   	  cout << root->data<<" ";
   	  maxlevel = level;
   }

   //right
   rightview(root->right,level+1,maxlevel);

   //left
   rightview(root->left,level+1,maxlevel);


}

int main()
{
	
	int maxlevel = -1;
	
	node* root = Level_order_input();

	rightview(root,0,maxlevel);
	return 0;
}