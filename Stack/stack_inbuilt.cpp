#include <iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int> s;
    for(int i=1; i<=5;i++){
    	s.push(i);
    }
    cout << s.top() << "\n";
    s.pop();
    cout << s.top() << "\n";
    cout << s.size()<< "\n";
    cout << s.empty() << "\n";
    while(!s.empty()){  // print all elements
    	cout << s.top()<<"\n";
    	s.pop();
    }
	return 0;
}