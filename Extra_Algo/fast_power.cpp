#include<bits/stdc++.h>
using namespace std;

int fast_power(int a, int n){
	if(n==0){
		return 1;
	}

	int smaller_ans = fast_power(a,n/2);
	smaller_ans *= smaller_ans;

	if(n & 1){ // for odd
		return smaller_ans * a;
	}

	return smaller_ans;
}

int main()
{
	int a, n;
	cin >> a >> n;

	cout << fast_power(a,n);
	return 0;
}