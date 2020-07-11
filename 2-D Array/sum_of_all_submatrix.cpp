#include<bits/stdc++.h>
using namespace std;

int sumofsubmatrix(int a[][1000], int r, int c){
	int sum = 0;
	for(int  i = 0; i < r; i++ ){
	for(int j =0; j < c; j++){
		int tl = (i+1)*(j+1);
		int br = (r-i)*(c-j);
		sum += a[i][j] *(tl * br); // value * total sub matrices
	}
 }
return sum;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);  
#endif
 
int a[1000][1000];
int r, c;
cin >> r >>c;
 

for(int  i = 0; i < r; i++ ){
	for(int j =0; j < c; j++){
		cin >> a[i][j];
	}
}

cout << sumofsubmatrix(a,r,c);
  
 return 0;
}