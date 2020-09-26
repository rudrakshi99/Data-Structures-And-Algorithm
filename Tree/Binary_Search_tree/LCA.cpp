//lowest common ancestor
//node can itself be an ancestor
//for LCA - one node should lie in left subtree and another one should lie in right subtree
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
// assumption - a and b present in tree and all keys are unique
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

int main()
{
	node* root = Level_order_input();
	int a, b;
	cin >> a >> b;
	cout<<lca(root,a,b)->data;
	return 0;
}


