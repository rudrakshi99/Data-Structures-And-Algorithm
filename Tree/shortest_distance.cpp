//shortest distance between nodes of a binary tree
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
ostream& operator<<(ostream&os, node* root){
      Level_order_output(root);
      return os;
}

node* lca(node* root,int a, int b){
    if(root==NULL){
        return NULL;
    }
    
    if(root->data==a or root->data==b){  
    	return root;
    }

    //search in left and right subtree
    node* leftans = lca(root->left, a, b);
    node* rightans = lca(root->right, a, b);

    if(leftans!=NULL && rightans!=NULL){
        return root;
    }
    if(leftans!=NULL){ // one node is present in left subtree
        return leftans;
    }

    return rightans;  // one node is present in right subtree

} 

int search(node* root, int key, int level) { // search for node and return its level
   
   if(root==NULL){ //means that node is not present in tree 
       return -1;
   }

   if(root->data==key){
      return level;
   }

   int left = search(root->left, key, level+1);
   if(left!=-1){ //present on left side
      return left;
   }
   //else
   return search(root->right, key, level+1);
}


//find distance b/w two nodes
int findDistance(node* root, int a, int b){
      
      node* lca_node = lca(root,a,b); //i.e. 2

      int l1 = search(lca_node, a,0); //distance of a from lca - 0 is root level
      int l2 = search(lca_node, b,0); //distance of b from lca

      return l1 + l2;

}
int main(){

	node* root = Level_order_input();
    
    //cout<<root;
    int a =7, b=9;
    cout<<findDistance(root,a,b);

	return 0;
}