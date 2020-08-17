#include<iostream>
#include<map>
#include<string>
#include<climits>
#include<queue>
#include<list>
using namespace std;

template<typename T> // for generic

class Graph{

	map<T, list<T> > m;
public:
	void AddEdge(T src, T dest){

		m[src].push_back(dest);
		
	}


	int BFS(T src,T dest){ // like level order traversal
		map<T, int> dist;
		map<T,T> parent;
		queue<T> q;
		for(auto node_pair : m){
			T node = node_pair.first;
			dist[node] = INT_MAX;
		}
		q.push(src);

	    dist[src] = 0;
	    parent[src] = src;

		while(!q.empty()){
			T temp = q.front();
			//cout<<temp<<" ";

			q.pop();

			for(auto neigh : m[temp]){ // traverse list of neighbours
				if(dist[neigh] == INT_MAX){ // if not visited
					q.push(neigh);
					dist[neigh] = dist[temp] + 1;
					parent[neigh] = temp;
				}
			}
		}
        
        //print the dist to dest node
        //dest to src
        T temp = dest;
        while(temp!=src){
        	cout<<temp<<"<--";
        	temp = parent[temp];
        } 
        cout<<src<<endl;
		return dist[dest];
	}
   
};

int main(){
	int board[50] = {0};
	// snake and ladders
	board[2] = 13;
	board[5] = 2;
	board[9] = 18;
	board[18] = 11;
	board[17] = -13;
	board[20] = -14;
	board[24] = -8;
	board[25] = 10;
	board[32] = -2;
	board[34] = -22;

	//add edges

	Graph<int> g;
	for(int i=0;i<=36;i++){
		for(int dice=1;dice<=6;dice++){
			int j = i + dice;
			j+=board[j];
			if(j<=36){
				g.AddEdge(i,j);
			}
		}
	}

    g.AddEdge(36,36);
   cout << g.BFS(0,36);



    

	return 0;
}