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
for(int i=1;i<6;i++){
	l.insertion_at_tail(i);
} 
l.print();
cout<<"\n"; 
l.insertion_at_x(6,2);
l.print();
cout<<"\n";
cout<< l.length();

return 0;
}