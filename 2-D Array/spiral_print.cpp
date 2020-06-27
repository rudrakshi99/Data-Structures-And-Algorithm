#include<bits/stdc++.h>
using namespace std;
void spiralpri(int a[][30], int r, int c){
	int sr = 0;
	int er = r-1;
	int sc = 0;
	int ec = c-1;
	int ele = 0;
	while(ele < r*c){
		for(int i=sc; i<=ec;i++){
			cout << a[sr][i] <<" ";
			ele++;
		}
		sr++;
		if(ele == r*c)
			break;
		for(int i=sr; i<=er;i++){
			cout << a[i][ec] <<" ";
			ele++;
		}
		ec--;
		if(ele == r*c)
			break;
		for(int i=ec; i>=sc;i--){
			cout << a[er][i] <<" ";
			ele++;
		}
		er--;
		if(ele == r*c)
			break;
		for(int i=er;i>=sr;i--){
			cout << a[i][sc] <<" ";
			ele++;
		}
		sc++;

	}

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);  
#endif
  int a[30][30];

int r, c;
cin >> r >>c;

for(int  i = 0; i < r; i++ ){
	for(int j =0; j < c; j++){
		cin >> a[i][j];
	}
}

spiralpri(a,r,c);
  
 return 0;
}