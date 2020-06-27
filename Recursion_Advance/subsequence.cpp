#include<bits/stdc++.h>
using namespace std;
void subsequence(char a[],int i, char output[], int j){
	// base
	if(a[i]=='\0'){
		output[j]='\0';
		cout << output<<"\n";
		return;
	}
	output[j]=a[i];
	subsequence(a,i+1, output, j+1);
	subsequence(a, i+1, output, j);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);  
#endif
char a[]="abc";
char output[1001];
subsequence(a,0,output,0);
return 0;
}