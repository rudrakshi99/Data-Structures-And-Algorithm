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


node* bulidtree(int *a,int s, int e){

    //base case
    if(s>e){
       return NULL;
    }

    int mid = (s+e)/2;
    node* root = new node(a[mid]); // make mid of arr as root at each level
    root->left = bulidtree(a,s,mid-1);
    root->right = bulidtree(a,mid+1,e);

    return root;
}

int main(){

	int a[] = {8,4,1,5,3,7};
	int n = 6;
	node* root = bulidtree(a,0, n-1);
	Level_order_output(root);
	return 0;
}