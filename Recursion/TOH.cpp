#include<bits/stdc++.h>
using namespace std;
void TOH(int n, char src, char helper, char dest){
    if(n==0)
    	return;
    TOH(n-1,src,dest ,helper);
    cout<<"Moving "<<" "<<n <<" "<<"from" <<" "<<src<<" "<<"to"<<' '<<dest<<"\n";
    TOH(n-1,helper,src ,dest);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);  
#endif
    int n;
    cin >> n;
  TOH(n,'A','B','C');
return 0;
}