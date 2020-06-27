#include<bits/stdc++.h>
using namespace std;
void permutation(char a[], int i){
	// base
	if(a[i]=='\0'){
		cout<<a<<"\n";
		return;
	}
	for(int j=i;a[j]!='\0';j++){
		swap(a[i],a[j]);
		permutation(a,i+1);
		swap(a[i],a[j]);
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);  
#endif
char a[]="abc";
permutation(a,0);
  return 0;
}