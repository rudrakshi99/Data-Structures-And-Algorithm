// you can divide all vertices of graph in 2 sets
// such that all edges of the graph are from set1 to set2

// It also known as 2 graph coloring problem

#include<iostream>
#include<vector>
using namespace std;

bool dfs_helper(vector<int> graph[], int node, int *visited, int parent,int color){
    
     //come to node
	visited[node] = color; //1 or 2, both mean visited

	for(auto nbr : graph[node]){

         if(visited[nbr]==0){
             int subprob = dfs_helper(graph,nbr, visited,node, 3-color); // 3-color will give only 0,1,2 as values

             if(subprob==false){ // if not bipartite 
                return false;
             }
         }
         else if(nbr!=parent and color==visited[nbr]){
                return false;
         }
	}

	return true;
}

bool dfs(vector<int>graph[], int n){

   int visited[n] = {0} ;// 0- not visited, 1 - visited color is 1, 2 -visited color 2
   
   int color = 1;
   int ans = dfs_helper(graph,0,visited, -1,color);
   
   //colors
   for(int i=0;i<n;i++){
       cout<<i <<" - color "<<visited[i]<<"\n";
   }


   return ans;

}


int main() {

   int n, m;
   cin >> n >> m;

   vector<int> graph[n];

   while(m--){
       int x, y;
       cin >> x >> y;

       graph[x].push_back(y);
       graph[y].push_back(x);

   }

   // BFS OR DFS,  by coloring the nodes at each step (current node has color 1, nbr should have a color 2)

   if(dfs(graph,n)){
     cout<<"yes";
   }else {

     cout<<"no";
   }


   return 0;
}