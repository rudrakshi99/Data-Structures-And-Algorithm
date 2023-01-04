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

int height(node* root){
	if(root == NULL)
		return 0;

	int left_height = height(root->left);

	int right_height = height(root->right);

	return max(left_height, right_height) + 1;

}

//time complexity O(N^2)
bool is_balnced(node* root){
	if(root==NULL){
		return true;
	}
	if(abs(height(root->left)-height(root->right))<=1 && is_balnced(root->left)&& is_balnced(root->right))
		return true;
	else
		return false;
}

//time complexity O(N)
int isBalanced(node* root)
{
    if (root == NULL)
        return 0;
    int lh = isBalanced(root->left);
    if (lh == -1)
        return -1;
    int rh = isBalanced(root->right);
    if (rh == -1)
        return -1;
 
    if (abs(lh - rh) > 1)
        return -1;
    else
        return max(lh, rh) + 1;
}

int main(){

	node* root = Create_BST();
    cout << boolalpha << is_balnced(root);
	return 0;
}
