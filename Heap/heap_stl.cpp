#include <iostream>
#include <queue>

using namespace std;


void print(priority_queue< int, vector<int>, greater<int> > h){
	while(!h.empty()){
		cout<<h.top()<<" ";
		h.pop();
	}
}


int main()
{


	//priority_queue<int> h;   //max heap

	priority_queue< int, vector<int>, greater<int> > h;  ///min heap

	h.push(1);
	h.push(2);
	h.push(3);
	h.push(17);
	h.push(19);
	h.push(36);
	h.push(7);
	h.push(25);
	h.push(100);

	print(h);
	
	return 0;
}