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

class  LinkedList{
public:
	node* head;
	node* tail;
	 LinkedList(){  //constructor
	 	head = NULL;
	 	tail = NULL;
	 }
	void insertion_at_head(int x){
		// node create
		node* n = new node(x);
		if(head == NULL){ //only one node
			head = n;
			tail = n;
		}
		else{
			n->next = head;
			head = n;
		}
	}
	void insertion_at_tail(int x){
		node* n = new node(x);
		if(head == NULL){ //only one node
			head = n;
			tail = n;
		}
		else{
			tail->next = n;
			tail = n;
		}
	}
	void print(){
		node* temp = head;
		while(temp!=NULL){
			cout << temp->data<<" ";
			temp = temp->next;
		}
	}
	
};
node* mid(node* head){
		node* fptr = head->next;
		node* sptr = head;
		while(fptr!=NULL && fptr->next!=NULL){
			fptr = fptr->next->next;
			sptr = sptr->next;
		}
		return sptr;
	}
	
	

node* merge(node*a, node*b){
	if(a==NULL)
		return b;
	if(b==NULL)
		return a;
	node* c= NULL;

	if(a->data < b->data){
		c = a;
        c->next = merge(a->next,b);
	}
	else{
		c = b;
		c->next = merge(a, b->next);
    
	}
   return c;
}

node* Mergesort(node* head){
	if(head == NULL || head->next == NULL){ //only one element or null list
        return head;
	}
	node* mid = mid(head);
	node* a = head;
	node* b = mid->next;
	mid->next = NULL; // break two list

	a = Mergesort(a);
	b = Mergesort(b);
	node* newnode = merge(a,b);

	return newnode;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);  
#endif
LinkedList l1, l2;
l1.insertion_at_tail(5);
l1.insertion_at_tail(3);
l1.insertion_at_tail(2);
l1.insertion_at_tail(4);
l1.insertion_at_tail(1);

l1.head = Mergesort(l1.head);
l1.head = merge(l1.head,l2.head);
l1.print();

return 0;
}