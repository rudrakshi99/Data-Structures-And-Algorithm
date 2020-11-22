// a[i]+a[j] > b[i] + b[j] such that i < j
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> pbds; 



int main() {

    int n;
    cin >> n;
    int a[n], b[n], c[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    for(int i=0;i<n;i++){
        c[i] = a[i] - b[i];
    }
	pbds st;

    int cnt =0;
	
	for(int i=0;i<n;i++){
       cnt += (st.size() - st.order_of_key({-c[i], 10000000}));
       st.insert({c[i],i});
	}
    
    cout<<cnt<<"\n";
   return 0;
}