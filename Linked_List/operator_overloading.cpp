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

// we can only perform linear search
bool search(node* head, int key){
	node* temp = head;
	while(temp!=NULL){
		if(temp->data == key){
			return true;
		}
		temp = temp->next;
	}
	return false;
}
bool search_rec(node* head, int key){
	if(head==NULL){
		return false;
	}
	if(head->data == key){
		return true;
	}
	else{
		return search_rec(head->next,key);
	}
}

node* take_input(){
	int d;
	cin >> d;
	while(d!=1){ // or cin >> d
		insertion_at_head(head,d);
		cin >> d;
	}
	return head;
}

ostream& operotor<<(ostream &os, node* head){ // cascading of operators
	print(head);
	return;
}

istream& operator>>(istream &is, node*&head){
	head = take_input();
	return is;
}
int main() {

LinkedList l;
for(int i=1;i<6;i++){
	l.insertion_at_head(i);
}
node* head = take_input();

node* head2 = take_input();
cin >> head1;
cout<<head<<head2; 
cout<<"\n";  

return 0;
}