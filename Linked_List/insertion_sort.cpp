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
node* insert(node* li, node* new_node){

		// Insertion at first position
		if(li == NULL || li->data >= new_node->data){
			new_node->next = li;
			li = new_node;
		}

		else{
			node* temp1 = li;
			while(temp1->next!=NULL && temp1->next->data < new_node->data){
               temp1 = temp1->next;
			}
			new_node->next = temp1->next;
			temp1->next = new_node;
			
		}
		return li;
}
	node* Insertionsort(node* head){
		node* sorted_list = NULL;
		node* temp = head;
		while(temp!= NULL){
			node *Next = temp->next; 
			sorted_list= insert(sorted_list, temp);
			temp = Next;
		}
		return sorted_list;
	}
	
int main() {

LinkedList l;
int n, a;
cin >> n;
for(int i=1;i<=n;i++){
	cin >> a;
	l.insertion_at_tail(a);
} 
 l.head = Insertionsort(l.head);
l.print();


return 0;
}