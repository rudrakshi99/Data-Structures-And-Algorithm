#include <iostream>
#include<queue>
using namespace std;

int main()
{
	queue<int> q;
	for(int i=1; i<=5;i++){
		q.push(i);
	}

	cout<<q.front()<<"\n";
    cout<<q.size()<<"\n";
    q.pop();
    cout<<q.empty()<<"\n";
    cout<<q.front()<<"\n";
    while(!q.empty()){
		cout<<q.front()<<endl;
		q.pop();
	}

	return 0;
}