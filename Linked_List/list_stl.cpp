#include <iostream>
#include<list>
using namespace std;

int main(){
	
	list<int> li;

	//insertion

	li.push_front(4);
	li.push_front(3);
	li.push_front(2);
	li.push_front(1);

	while(!li.empty()){
		cout<<li.front()<<" ";
		li.pop_front();
	}
     cout<<"\n";

	list<pair<char,char> > l1; // edge list

	 //pushing a pair

	l1.push_front(make_pair('a','c'));

	// or

	pair<char,char> p;
	p.first = 'a';
	p.second = 'd';
	l1.push_front(p);

	l1.push_front(make_pair('e','c'));
	l1.push_front(make_pair('d','a'));

	while(!l1.empty()){
		pair<char,char> d = l1.front();
		cout <<d.first<<" "<<d.second<<"\n";
		l1.pop_front();
	}
	
	//Adjacency list

	list<int>* l = new list<int>[5]; //array of list

	l[0].push_back(1);
	l[0].push_back(4);
	l[1].push_back(0);
	l[1].push_back(2);
	l[1].push_back(3);
	l[1].push_back(4);
	l[2].push_back(1);
	l[2].push_back(3);
	l[3].push_back(1);
	l[3].push_back(2);
	l[3].push_back(4);
    l[4].push_back(0);
    l[4].push_back(1);
    l[4].push_back(3);


    for(int i=0;i<5;i++){
    	cout<<i<<"-->";
    	while(!l[i].empty()){
    		cout <<l[i].front()<<" ";
    		l[i].pop_front();
    	}
    	cout<<"\n";
    }



	
	return 0;
}