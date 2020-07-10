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
	
	
	void delete_at_head(){
		node* temp = head;
		head = head->next;
		delete temp;
	}
	void delete_at_tail(){
		node* temp = head;
		while(temp->next!=tail){
			temp = temp->next;
		}
		delete tail;
		 temp->next = NULL;
		 tail = temp;

	}
	
	void print(){
		node* temp = head;
		while(temp!=NULL){
			cout << temp->data<<" ";
			temp = temp->next;
		}
	}
	
};
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);  
#endif
LinkedList l;
for(int i=1;i<6;i++){
	l.insertion_at_head(i);
}
l.print();
cout<<"\n";
l.delete_at_head();
l.print();
cout<<"\n";
l.delete_at_tail();
l.print();
cout<<"\n";
return 0;
}