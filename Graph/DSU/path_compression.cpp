// directly attach each node to parent
//o(log n)
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
   void union_set(int x,int y, int parent[]){
       int s1 = findset(x,parent); // x present in s1 set
       int s2 = findset(y,parent); // y present in s2 set

       if(s1!=s2){
           parent[s1] = s2; // make union
       }
   }


   bool contain_cycle(){
      //DSU logic to check if graph contain cycle or not
   	  int *parent = new int[V];
   	  for(int i=0;i<V;i++){
          parent[i] = -1;
   	  }

   	  for(auto edge: l){
        int i = edge.first; // parent
        int j = edge.second; // node

        int s1 = findset(i, parent);
        int s2 = findset(j, parent);

        if(s1!=s2){
           union_set(s1,s2,parent); // making set means building graph when parents are not same
        }
        else{ // both belong to same set hence cycle present
           cout<<" same parent " <<s1<<" and "<<s2<<endl;
           return true;
        }
   	  }

   	  delete [] parent;
   	  return false;
      
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