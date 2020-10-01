#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// DSU Data Structure
// pth compression + union by rank

class DSU{
    
    int *parent;
    int *rank;
public:

	DSU(int n){
       parent = new int[n];
       rank = new int[n];

        // initialisation
   	  for(int i=0;i<n;i++){
          parent[i] = -1;
          rank[i] = 1; //each node contain one node
   	  }

	}

	//Find Function
	int findset(int i){
         //base case
   	    if(parent[i]==-1){ // node is parent of itself
           return i;
   	    }
       
   	    return parent[i]= findset(parent[i]); /**********path compression optimisation*************/ 
    }

    //unite (union)

    //unoin by rank
   void union_set(int x,int y){
       int s1 = findset(x); // x present in s1 set
       int s2 = findset(y); // y present in s2 set

       if(s1!=s2){
       	   if(rank[s1]<rank[s2]){
           parent[s1] = s2; // s2 will be parent of s1
           rank[s2] = s2 + s1;
          }
          else{
             parent[s2] = s1;
             rank[s1] += rank[s2];
          }
       }
   }

};

class Graph{
   
   vector<vector<int> > edgelist;
   int V;

public:
	Graph(int V){
      this->V = V;
   }

  
   void addEdge(int x, int y, int w){
        edgelist.push_back({w,x,y});
   }

   int kruskal_mst(){

       //1, sort all the edges based upon weight
   	   sort(edgelist.begin(), edgelist.end());
       
       // initialise DSU
       DSU s(V);

   	   int ans = 0;
   	   for(auto edge : edgelist){
          
          int w = edge[0]; // weight
          int x = edge[1]; 
          int y = edge[2];

          //take that edge in MST if it doesn't form a cycle

          if(s.findset(x)!=s.findset(y)){
             s.union_set+(x,y);
             ans += w;
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
	
   cout<<g.kruskal_mst();

   return 0;
}