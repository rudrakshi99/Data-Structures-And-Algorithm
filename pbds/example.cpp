#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 
 // key, mapped, comparision funct, tag (tree structures), node_update

// functionality
/* all set functionality

extra - log(n)

find_by_order(k) - returns the iterator to the kth largest element

order_of_key(k)- returns the no. of elements in the set which are strictly less
than k. OR index of that element*/

int main(){
   
   pbds st;
   st.insert(1);
   st.insert(3);
   st.insert(4);
   st.insert(10);
   st.insert(15);

   //if we insert pair - <value, index>

   //kth largest element at till now (log n)
   for(int i=0;i<st.size();i++){
     cout<<i<<" "<<*st.find_by_order(i)<<"\n";
   }

   cout<<st.order_of_key(5)<<"\n";
    
   return 0;
}