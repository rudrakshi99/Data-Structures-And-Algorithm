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

node* Insert_into_bst(node* root, int data){

	if(root == NULL){
		root = new node(data);
		return root;
	}

	else if(data < root->data){
        root->left = Insert_into_bst(root->left,data);
	}
	else{
        root->right = Insert_into_bst(root->right,data);
	}

	return root;
}
node* Create_BST(){

	int data; // root node
	cin >> data;

	node* root = NULL;

	while(data!= -1){
		root = Insert_into_bst(root, data);
		cin >> data;
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

int search(int in[], int s, int e, int data){ // linear search
	for(int i=s; i<=e;i++){
		if(in[i]==data){
			return i;
		}
	}
}
int ind = 0; //global 
 node* pre_in(int *pre, int *in, int s, int e){
 	if(s>e){
 		return NULL;
 	}
    node* root = new node(pre[ind]); // pick each node from preorder arr
        ind++;

    if(s==e)// only one element
    	return root;

    
    int ind1 = search(in, s,e,root->data); //search for index in inorder arr

    root->left = pre_in(pre, in,s, ind1-1); // all element left of ind1 will form left subtree
    root->right = pre_in(pre, in, ind1+1,e);  // all element right of ind1 will form right subtree
  
    return root;

 }
int main(){

	int pre[] = {8,4,1,5,3,7};
	int in[]={1,4,5,8,3,7};
	node* root = pre_in(pre, in, 0, 5);
	Level_order_output(root);
	return 0;
}