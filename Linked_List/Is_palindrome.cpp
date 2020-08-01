#include <iostream>
#include<stack>
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
bool palindrome(node* head){
	node* slow = head;
	stack<int> s;
	while(slow!=NULL){ // push all elements
       s.push(slow->data);
	   slow = slow->next;
	}
	node* temp = head;
	while(temp!=NULL){
		int d = s.top();
		s.pop();
		if(d!=temp->data)
		  return false;

		temp = temp->next;
	}
  return true;
}
int main() {
	int a, n;
LinkedList l;
   cin >> n;
for(int i=1;i<=n;i++){
	cin>> a;
	l.insertion_at_tail(a);
} 
//l.print();
  if(palindrome(l.head))
  cout<<"true";
  else
  cout<<"false";
return 0;
}