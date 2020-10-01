#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph{
  
  //Adjacency list
  vector<pair<int,int> > *l;
  int V;

public:
	Graph(int n){
       V = n;
       l = new vector<pair<int,int> > [n]; // node, weight
	}

	void addEdge(int x, int y, int w){
        l[x].push_back({y,w});
        l[y].push_back({x,w});
	}


	int prim_mst(){
        //most important stuff
        priority_queue<pair<int, int> , vector<pair<int, int>>, greater< pair<int, int>> > Q; //w,y  //min heap

        // another array 
        // visited array that denotes whether a node has been included in MST or NOT
        bool *vis = new bool[V]{0};

        int ans = 0;

        //begin 
        Q.push({0,0}); //weight, node - src
        
        while(!Q.empty()){
          //pick out the edge with min weight
          auto best = Q.top();
          Q.pop();
          
          int to = best.second;
          int weight = best.first;

          if(vis[to]){ // if the vertex is visited
            // discard the edge and continue
            continue;

          }

          //otherwise take the current edge
          ans += weight;
          vis[to] =1; // mark the node visited to which this edge is connected

          //add the new nodes in queue which are linked with this edge
          for(auto x: l[to]){ // in l, first - node , second - weight
             if(vis[x.first]==0){
               Q.push({x.second, x.first}); //push weight, node
             }
          }

        }

        return ans;

	}

};

int main(){

   int n,m; //node, egde
	cin >> n >> m;
	Graph g(n);

	while(m--){ // take input for each edge
      int x,y,w;
      cin >> x >> y >> w;
      g.addEdge(x-1, y-1,w); // our code 0 based indexing
	}
	
   cout<<g.prim_mst();

   return 0;
}