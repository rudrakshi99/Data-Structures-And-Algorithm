#include <iostream>
#include<stack>
using namespace std;

void insert_stack(stack<int> &s, int top){

	if(s.empty()){
		s.push(top);
		return;
	}

	int upper = s.top();
	s.pop();
	insert_stack(s, top);
   
    s.push(upper); // push all elements

}

void reverse_stack(stack<int> &s){
	if(s.empty())
		return;

	int top = s.top();
	s.pop();

	reverse_stack(s);

	insert_stack(s, top);
}

int main()
{
	stack<int> s;
	for(int i=1; i<=3;i++)
		s.push(i);

	reverse_stack(s);

	while(!s.empty()){
		cout << s.top()<<" ";
		s.pop();
	}
	return 0;
}