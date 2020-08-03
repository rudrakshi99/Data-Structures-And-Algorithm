#include <iostream>
#include<string>
#include <unordered_map>
#include <list>
#include <map> // sorted according
using namespace std;

int main(){
	
	unordered_map<string, int> m;
	m.insert(make_pair("Pizza",100));
	m.insert(make_pair("Fries",50));

	m["coke"] = 80; //if present then update value

	string s = "Pizza";

	if(m.count(s)){ //return 0 or 1 for existance
		cout<<"Price of "<<s<<" is "<<m[s]<<"\n";
	}
	else{
		cout<<"not found";
	}
	cout<<"\n";
    
    for(auto i : m){
    	cout<<i.first<<" "<<i.second<<"\n";
    }
	
	cout<<"\n";

	unordered_map<string,list<string> > m1; //ds

	m1["modi"].push_back("trumph");
	m1["modi"].push_back("yogi");
	m1["prahu"].push_back("modi");
	m1["modi"].push_back("putin");

	for(auto i : m1){
		cout<<i.first<<" -> ";
		for(auto j : i.second){
			cout<<j<<" -> ";
		}
		cout<<"\n";
	}


	return 0;
}