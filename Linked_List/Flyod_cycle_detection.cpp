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
void cycle_detection(node* head){
	node* fptr = head->next;
	node* sptr = head;
	while(fptr!=sptr){ //detection of cycle
		if(fptr == NULL || fptr->next == NULL) // no cycle
			return;
		fptr = fptr->next->next;
		sptr = sptr->next;
	}
	sptr = head;

	while(fptr->next != sptr->next){ // break cycle
		fptr = fptr->next; 
		sptr = sptr->next;
	}
	fptr->next = NULL;

}
int main() {
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);  
  #endif
   LinkedList l;
  cout<<"\n";  
  for(int i=1;i<6;i++){
 	l.insertion_at_tail(i);
  } 

  /* Create a loop for testing */
    l.head->next->next->next->next = l.head; 
    cout<<"\n"; 


return 0;
}