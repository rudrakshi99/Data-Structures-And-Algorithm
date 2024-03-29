#include<bits/stdc++.h>
#define int             long long int
#define pb              push_back
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mod             1000000007
#define w(x)            int x; cin>>x; while(x--)
using namespace std;
 
 
void solve(){
 
    int v,e;
    cin>>v>>e;
    vector<vector<int> > g(v);
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    int res[v]; // result array
    bool available[v]; // mark availability of colors
    res[0]=0;
    for(int i=1;i<v;i++) res[i] = -1;
    for(int i=0;i<v;i++) available[i] = false;
 
    int cn = 0;
    for(int i=1;i<v;i++){
        // mark availability of colors to be used except adj nodes colors
        for(auto x:g[i]){
            if(res[x]!=-1){
                available[res[x]] = true;
            }
        }
        
        // find first color available
        int cr;
        for(cr=0;cr<v;cr++){
            if(available[cr] == false){
                break;
            }
        }
 
        res[i] = cr;
        cn = max(cn,cr+1);
        
        // reset except already colored nodes
        for(auto x:g[i]){
            if(res[x]!=-1){
                available[res[x]] = false;
            }
        }
    }
    cout<<cn<<endl;
    for(int i=0;i<v;i++) cout<<res[i]<<" ";
 
}
 
int32_t main() {
 
    solve();
    return 0;
 
}
 
