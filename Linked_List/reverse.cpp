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
	void insertion_at_x(int x, int pos){
		node* n = new node(x);
		if(pos<=0){
			insertion_at_head(x);
		}
		else if(pos>length()){
			insertion_at_tail(x);
		}
		else{
		  node* temp = head;
		  int move = 1;
		  while(move < pos-1){
		  	move++;
		  	temp = temp->next;
		  }
		  n->next = temp->next;
		  temp->next = n;

		}
	}
	
	int length(){
		node* temp = head;
		int l = 0;
		while(temp!=NULL){
			l++;
			temp = temp->next;
		}
	  return l;
	}
	void print(){
		node* temp = head;
		while(temp!=NULL){
			cout << temp->data<<" ";
			temp = temp->next;
		}
	}
	
};
node* reverse(node* head){
	node *C = head; // current
	node* P = NULL; //previous
    node* N;
    while(C!=NULL){
    	//save next node
    	N = C->next;
    	//make the current node point to prev
    	C->next = P;
    	// update P and C take them 1 step forward
    	P = C;
    	C = N;
    }
    head = P;

    return head;
}

node* recReverse(node* head){ // O(N)
	if(head->next==NULL || head==NULL){ 
		return head; // return the address of node whose next is null or only one node
	}
    
    node* shead = recReverse(head->next); 
	node* temp = head->next; 
	temp->next = head;// or head->next->next = head;
	head->next = NULL;
	
	return shead;

}
int main() {

LinkedList l;

for(int i=1;i<6;i++){
	l.insertion_at_tail(i);
} 
l.print();
cout<<"\n"; 
l.head = reverse(l.head);
l.print();

return 0;
}