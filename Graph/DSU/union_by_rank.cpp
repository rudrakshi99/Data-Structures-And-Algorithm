// rank - nunber of nodes connected along with it (size of set)
// attach smaller tree to bigger tree
// O(log n)- union by rank
// o(1) - applying both path compression and union by rank

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
	
    // Find -> O(1)
   int findset(int i, int parent[]){
         //base case
   	    if(parent[i]==-1){ // node is parent of itself
           return i;
   	    }
       
   	    return parent[i]= findset(parent[i],parent); /**********path compression optimisation*************/ 
   }

	//O(Log(N))	
   //unoin by size and and initialize rank arr by 1
   void union_set(int x,int y, int parent[], int rank[]){
       int s1 = findset(x,parent); // x present in s1 set
       int s2 = findset(y,parent); // y present in s2 set

       if(s1!=s2){
       	   if(rank[s1]<rank[s2]){
           parent[s1] = s2; // s2 will be parent of s1
           rank[s2] += rank[s1];
          }
          else{
             parent[s2] = s1;
             rank[s1] += rank[s2];
          }
       }
   }
	
//unoin by rank and initialize rank arr by 0
//here rank represents height of tree
   void union_set_by rank(int x,int y, int parent[], int rank[]){
       int s1 = findset(x,parent); // x present in s1 set
       int s2 = findset(y,parent); // y present in s2 set

       if(s1!=s2){
       	   if(rank[s1]>=rank[s2]){
           parent[s2] = s1; 
            if(rank[s1]==rank[s2]){
                rank[s1] = rank[s1]+1;
            }
          }
          else{
             parent[s1] = s2;
          }
       }
   }

   bool contain_cycle(){
      //DSU logic to check if graph contain cycle or not
   	  int *parent = new int[V];
   	  int *rank = new int[V];

      // initialisation
   	  for(int i=0;i<V;i++){
          parent[i] = -1;
          rank[i] = 1; //each node contain one node
   	  }

   	  for(auto edge: l){
        int i = edge.first; // parent
        int j = edge.second; // node

        int s1 = findset(i, parent);
        int s2 = findset(j, parent);

        if(s1!=s2){
           union_set(s1,s2,parent,rank); // making set means building graph when parents are not same
        }
        else{ // both belong to same set hence cycle present
           return true;
        }
   	  }

   	  delete [] parent;
   	  return false;
      
   }

   int num_of_component(){
        int comp=0;
        for(int i=0;i<V;i++){
            int p = findset(i);
            if(p==i){
                comp++;
            }
        }
       return comp;
   }

};

int main()
{
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,1);

	cout<<g.contain_cycle();
	return 0;
}
