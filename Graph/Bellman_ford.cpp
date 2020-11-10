//weighted graph
//directed graph
//O(VE)
//bottom up DP
// 1) init dist[vertices] = INT_MAX, dist[src] = 0
// 2) Relax all edges V-1 times  // updating distance with less value
// 3) Negative weight cycle detection
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> bellman_ford(int V, int src, vector<vector<int> > edges){

   //create a vector
	vector<int> dist(V+1, INT_MAX);

	dist[src] = 0;

	//relax all edges V-1 times
	for(int i=0;i<V-1;i++){
         for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if(dist[u]!=INT_MAX and dist[u] + wt < dist[v]){
            	dist[v] = dist[u] + wt;
            }
         }
	}

 // check for negative wt cycle
	for(auto edge : edges){ // we can reduce the weight infinitly
		    int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
         if(dist[u]!=INT_MAX and dist[u] + wt < dist[v]){
             cout<<"negative wt cycle found";
             exit(0);
         }
	}
   return dist;
} 

int main(){
    
    int n, m;
    cin >> n>> m;

	//edge list
	vector< vector<int > > edges;  //(a,b,3), (c,d,5)...

	for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >>v >> w;
        edges.push_back({u,v,w});
	}
    
    //algo
    vector<int> distances = bellman_ford(n,1,edges);

    for(int i=1; i<=n;i++){
        cout<<"Node" <<i<<" is at dist " << distances[i] <<"\n";
    }

return 0;
}
