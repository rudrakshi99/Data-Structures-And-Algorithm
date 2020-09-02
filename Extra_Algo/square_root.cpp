#include<iostream>
using namespace std;

float square_root(int n, int p){ // O(log N+p) 

	int s = 0;
	int e = n;

	float ans = -1;
	while(s <= e){ // integral part
		int mid = (s+e)>>1;
		if(mid*mid == n){
			return mid;
		}
		if(mid*mid < n){
			ans = mid;
			s = mid +1;
		}
		else{
			e = mid -1;
		}
	}

	float inc = 0.1;

	for(int i =1; i<=p;i++){ // floating part

		while(ans* ans <= n){

			ans = ans + inc;
		}

		ans = ans - inc;
		inc = inc/10;
	}

	return ans;
}

int main(){

	int n ;
    cin >> n;

	cout << square_root(n, 3)<<"\n";

	return 0;
}