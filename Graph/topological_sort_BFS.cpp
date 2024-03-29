// not for cycle graph as it has dependensies
// applied for directed acyclic graph 
//start with the node which has no dependency - indegree = 0
#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<cstring>
using namespace std;

class Graph{

	list<int> *l;
	int V;

public:
	Graph(int V){
		this->V=V;
		l = new list<int>[V];
	}   
	void addEdge(int x, int y){ // directed graph
		l[x].push_back(y);
	}

    void topological_sort(){

    	//indegree
    	int *indegree = new int[V];
    	// initialize with 0 indegree
    	for(int i=0;i<V;i++){
    		indegree[i] = 0;
    	}
    	//update indegree by traversing edged x->y
    	//indegree[y]++   
    	for(int i=0;i<V;i++){
    		
    		for(auto y : l[i]){
    			indegree[y]++;
    		}
    	}

    	// bfs
    	queue<int> q;
    	//1. step find nodes with 0 indegree
    	for(int i=0;i<V;i++){
    		if(indegree[i]==0){
    			q.push(i);  // for starting
    		}
    	}
	int c=0; //to detect cycle
	c = q.size() // take size to get no. of nodes of indegree 0
    	// start removing elements from the queue
    	while(!q.empty()){
    		int node = q.front();
    		cout << node<<'\n';
    		q.pop();

    		// iterate over nbrs of that node and reduce their indegree by 1
    		for(auto nbr:l[node]){
    			indegree[nbr]--;
    			if(indegree[nbr]==0){
    				q.push(nbr);
				c++; // increase to count 0 indegree nodes
    			}
    		}
    	}
        
	if(c==V){
	   cout<<"No cycle present";
	}else{
           cout<<"Cycle is present";
	}
    }
};

int main(){
	 Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
  
    cout << "Following is a Topological Sort of the given graph \n"; 
    g.topological_sort(); 
  

	return 0;
}
