#include <iostream>
#include <stack>
using namespace std;


class Queue{

public:

	stack<int> s1; //main data structure

	stack<int> s2; //helper

	Queue(){
		//no need
	}

	void push(int x){
		s1.push(x);
	}

	void pop(){

		//copy s1 to s2

		while(!s1.empty()){
			s2.push(s1.top());
			s1.pop();
		}

		s2.pop();

		//copy s2 to s1

		while(!s2.empty()){
			s1.push(s2.top());
			s2.pop();
		}

	}

	int front(){
		//copy s1 to s2

		while(!s1.empty()){
			s2.push(s1.top());
			s1.pop();
		}

		int x = s2.top();

		//copy s2 to s1

		while(!s2.empty()){
			s1.push(s2.top());
			s2.pop();
		}

		return x;

	}

	int size(){
		return s1.size();
	}

	bool empty(){
		return s1.empty();
	}


};




int main()
{
	Queue q;

	for(int i=1;i<=5;i++){
		q.push(i);
	}


	cout<<q.front()<<endl;

	cout<<q.size()<<endl;

	q.pop();
	cout<<q.front()<<endl;
	
	cout<<q.empty()<<endl;


	while(!q.empty()){
		cout<<q.front()<<endl;
		q.pop();
	}


	
	return 0;
}