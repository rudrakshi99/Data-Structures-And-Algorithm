//maximum sum path from any node to node
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
class Pair{
public:
   int branchsum; // from root to other node
   int maxsum; // left + right sum

   Pair() {
      branchsum = 0;
      maxsum = 0;
   }
};

Pair maxSum(node* root) {
  
    Pair p;

    if(root == NULL){
       return p;
    }

    Pair left = maxSum(root->left);
    Pair right = maxSum(root->right);

    //construct two values
    int op1 = root->data;
    int op2 = left.branchsum + root->data;
    int op3 = right.branchsum + root->data;
    int op4 = left.branchsum + right.branchsum + root->data;

    int current_ans = max(op1, max(op2, max(op3, op4))); //through root

    //branch sum of the current root
    p.branchsum = max(left.branchsum, max(right.branchsum, 0)) + root->data; //0 to handle negative data
    p.maxsum = max(left.maxsum, max(right.maxsum, current_ans)); //entire left tree, entire right tree, both tree through root
    return p;


}

int main(){

	node* root = Level_order_input();
    
    //cout<<root;
    cout<<maxSum(root).maxsum; 
	return 0;
}