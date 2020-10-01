// no. of ways in which two cities can be choosen so that there
// will be no direct coonection
// ans -> total ways - ways of selecting cities from same components
// total nodes - rank[leader]

#include<iostream>
#include<list>
using namespace std;

class Graph{
   int V;
   list<pair<int,int> > l; //Edge list
   
public:
   Graph(int V){
      this->V = V;
   }

   void addEdge(int u, int v){
      l.push_back(make_pair(u,v));
   }
    // Find

   int findset(int i, int parent[]){
         //base case
   	    if(parent[i]==-1){ // node is parent of itself
           return i;
   	    }
       
   	    return parent[i]= findset(parent[i],parent); /**********path compression optimisation*************/ 
   }

   //unoin
   void union_set(int x,int y, int parent[], int rank[]){
       int s1 = findset(x,parent); // x present in s1 set
       int s2 = findset(y,parent); // y present in s2 set

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


   bool pairing_problem(){
      //DSU logic to check if graph contain cycle or not
   	  int *parent = new int[V];
   	  int *rank = new int[V];

      // initialisation
   	  for(int i=0;i<V;i++){
          parent[i] = -1;
          rank[i] = 1; //each node contain one node
   	  }

   	  for(int i=0;i<V;i++){
         parent[i] = -1;
         rank[i] = 1;
   	  }

   	  //code logic
   	 
   	  for(auto edge: l){ // building array
         int i = edge.first;
         int j = edge.second;

         int s1 = findset(i, parent);
         int s2 = findset(j, parent);

         union_set(s1, s2, parent, rank);
   	  }
     
       int ans = 0;
      for(int i=0;i<V;i++){
         ans += V - rank[findset(i, parent)];
      }

      delete [] parent;
      delete [] rank;
      return ans/2; // we are counting two times
   }


};

int main()
{
	int n,m;
	cin >> n >> m;
	Graph g(n);

	while(m--){
      int x,y;
      cin >> x >> y;
      g.addEdge(x, y);
	}
	
	cout<<g.pairing_problem();
	return 0;
}