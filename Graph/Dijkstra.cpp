//O(E log V)
#include<iostream>
#include<map>
#include<string>
#include<queue>
#include<list>
#include<climits>
#include<set>
using namespace std;

template<typename T> // for generic

class Graph{

    map<T, list<pair<T,int > > > m;
public:
    void addEdge(T src, T dest,int dist, bool nondirectional = true){

        m[src].push_back(make_pair(dest,dist));
        if(nondirectional){ // bi-directional
            m[dest].push_back(make_pair(src,dist));
        }
    }

    void print(){
        for(auto i : m){
            cout << i.first<<" -> ";
            for(auto j: i.second){
                cout<<"("<<j.first<<" , "<<j.second<<")";
            }
            cout<<"\n";
        }
    }
    
    void Dijkstra(T src){

        map<T, int> dist; // (node,dist)

        for(auto i : m){ // initilize 
            dist[i.first] = INT_MAX;
        }
        dist[src] = 0; // distance of src to src

        set<pair<int,T> > s;  //(dist,node)

        s.insert(make_pair(0,src)); // dist, node
        
        while(!s.empty()){
            auto p = *(s.begin()); // picking from front

            s.erase(s.begin());

            T parent = p.second;

            int dist_till_parent = p.first;

            for(auto neigh : m[parent]){
                if(dist[neigh.first] > dist_till_parent + neigh.second){
                    //check if already present in set then delete and push new value

                    auto f = s.find(make_pair(dist[neigh.first],neigh.first));

                    if(f!=s.end()){ // delete to avoid repetation
                        s.erase(f);
                    }
                      //update for smaller distance in map
                     dist[neigh.first] = dist_till_parent + neigh.second;

                     s.insert(make_pair(dist[neigh.first], neigh.first));

                }
            }
        }

        for(auto i : dist){
             cout<<"Distance of "<<i.first<<" from "<<src<<" is "<<i.second<<"\n";
        }
    }
        
};

int main(){
Graph<string> g;
     g.addEdge("Amritsar","Agra",1);
    g.addEdge("Amritsar","Jaipur",4);
    g.addEdge("Delhi","Jaipur",2);
    g.addEdge("Delhi","Agra",1);
    g.addEdge("Bhopal","Agra",2);
    g.addEdge("Bhopal","Mumbai",3);
    g.addEdge("Jaipur","Mumbai",8);

    //g.print();
    g.Dijkstra("Amritsar");
    

    return 0;
}