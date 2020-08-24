#include<iostream>
#include<map>
#include<string>
#include<queue>
#include<list>
using namespace std;

template<typename T> // for generic

class Graph{

	map<T, list<T> > m;
public:
	void addEdge(T src, T dest){

		m[src].push_back(dest);
		
	}

	void print(){
		for(auto i : m){
			cout << i.first<<" -> ";
			for(auto j: i.second){
				cout<<j<<" -> ";
			}
			cout<<"\n";
		}
	}
	void DFS_helper(T src, map<int, bool> &visited,list<T> &ordering){


		visited[src] = true;
		for(auto i : m[src]){
			if(!visited[i]){
				DFS_helper(i, visited,ordering);
			}
		}

		ordering.push_front(src);
		return;
	}

	void DFS(){ 
		map<int, bool> visited;
		list<T> ordering; // maintaing the list
       
       for(auto p : visited){
           visited[p.first] = false;
       }
	    

	    for(auto i : m){ // call function for each node 
	    	if(!visited[i.first]){
	    		DFS_helper(i.first,visited,ordering);
	    	}
	    }
	    for( auto i : ordering){
	    	cout << i <<"\n";
	    }

	}

};

int main(){
Graph<int> g;
    
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
  
    cout << "Following is a Topological Sort of the given graph \n"; 
    g.DFS(); 
	return 0;
}