//inversions in array - a[i] > a[j] such that i < j
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 


//1. merge sort
//2. pbds

int main() {

    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
	pbds st;

    int cnt =0;
	
	for(int i=0;i<n;i++){
       cnt += (st.size() - st.order_of_key(arr[i]));
       st.insert(arr[i]);
	}
    
    cout<<cnt<<"\n";
   return 0;
}