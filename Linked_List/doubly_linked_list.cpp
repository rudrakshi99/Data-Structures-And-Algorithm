#include <iostream>
using namespace std;

class node{
  
  public:
  	int data;
  	node* next;
  	 node(int x){  //constructor
       data = x;
       next = NULL;
  	 }

};

void insertion(node*&head, int data){
	node* n = new node(data);
	node* temp = head;

	n->next = head;
	if(temp!=NULL){

		while(temp->next!=head){
			temp = temp->next;
		}
		// we get the tail
		temp->next = n;
	}
	else{
		n->next = n; // self loop
	}
	head = n;
}

node* getnode(node* head, int data){

	node* temp = head;
	while(temp->next!=head){
		if(temp->data==data){
			return temp;
		}
		temp = temp->next;
	}

	if(temp->data==data){ // check in last node
		return temp;
	}
	return NULL;
}

void deleteNode(node* head, int data){

	node* del = getnode(head,data);
	if(del==NULL){ // not present
		return;
	}
    if(head==del){ // if we want to delete head
    	head = head->next;
    }
	node* temp = head;
	//stop one step behind the node to be deleted 
	while(temp->next!=del){
		temp=temp->next;
	}

	temp->next = del->next;
	delete del;
}

void print(node* head){

	node* temp = head;
	while(temp->next!=head){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<temp->data;
}
int main()
{
	node* head = NULL;
	insertion(head,10);
	insertion(head,20);
	insertion(head,30);
	insertion(head,40);
	insertion(head,50);
	insertion(head,60);
	print(head);
	cout<<"\n";	
	deleteNode(head, 40);
	print(head);
	return 0;
}