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
	
	int mid(){
		node* fptr = head->next;
		node* sptr = head;
		while(fptr!=NULL && fptr->next!=NULL){
			fptr = fptr->next->next;
			sptr = sptr->next;
		}
		return sptr->data;
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
	  l.insertion_at_tail(i);
    }
    l.print();
    cout<<"\n";
    cout<< l.mid();  

  return 0;
}