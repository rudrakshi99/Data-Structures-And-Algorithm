// DFS
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
	void addEdge(int x, int y,bool directed=true){ 
		l[x].push_back(y);
		if(!directed){
           l[y].push_back(x);
		}
	}
    
    bool cycle_helper(int node,bool *visited, bool *stack){
          visited[node] = true;
          stack[node] = true;
           
           for(int nbr:l[node]){
               if(stack[nbr]==true){
                    return true; //cycle present
               }
               else if(visited[nbr]==false){  //not visited
                  bool cycle_found = cycle_helper(nbr, visited, stack);
                  if(cycle_found==true){
                      return true; //cycle present
                  }
               }
           }
          //leave a node 
          stack[node] = false;
          return false;

    }
   bool contains_cycle(){
       
       bool *visited = new bool[V];
       bool *stack = new bool[V]; //order array
        
       for(int i=0;i<V;i++){
          visited[i] = stack[i] = false;
       }

       return cycle_helper(0,visited,stack);

   }
};

int main(){
   
   Graph g(7);

   g.addEdge(0,1);
   g.addEdge(1,2);
   g.addEdge(2,3);
   g.addEdge(3,4);
   g.addEdge(4,5);
   g.addEdge(1,5);
   g.addEdge(5,6);
   g.addEdge(4,2); //Back Edge - node to an ancestor of that node
   
   if(g.contains_cycle()){
        cout<<"Yes";
	}
	else{
        cout<<"No";
	}

   return 0;
}
