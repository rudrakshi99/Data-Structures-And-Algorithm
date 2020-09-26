// nodes at k distance from given target node
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


// for below nodes from target
void printAtKLevel(node* root, int k){
  if(root == NULL){
     return;
  }

  if(k==0){

   cout<<root->data<<" ";
   return;
  }

  printAtKLevel(root->left,k-1);
  printAtKLevel(root->right,k-1);
   return;
}

int printAtDistanceK(node* root, node* target,int k){
   
   //base case
	if(root==NULL){
       return -1;
	}
	// reach the target node
	if(root==target){
      printAtKLevel(target,k); // for below nodes from target
      return 0; 
	}

	// ancestor
    int DL = printAtDistanceK(root->left,target,k); //find the distance of target node in left subtree from parent

    if(DL!=-1){ // target node found in left subtree
       
       if(DL+1==k){
       	 cout<<root->data<<" "; //print ancestor itself
       }

       else{
          printAtKLevel(root->right,k-2-DL); // call on right subtree
       }
       return 1 + DL; // distance to parent
    }

    int DR = printAtDistanceK(root->right,target,k); //find the distance of target node in right subtree from parent
    
    if(DR!=-1){ // target node found in right subtree
       
       if(DR+1==k){
       	 cout<<root->data<<" "; //print ancestor itself
       }

       else{
          printAtKLevel(root->left,k-2-DR); // call on left subtree
       }
       return 1 + DR; // distance to parent
    }

    //node was not present in left and right subtree
    return -1;

}


int main(){
	
    node* root = Level_order_input();
	node* target = root->left->left;

	int k;

	printAtDistanceK(root,target,2);

 return 0;
}