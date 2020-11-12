#include<iostream>.
using namespace std;

void decimalToBinary(int n){

    int ans = 0;
    int p =1;
	while(n>0){
       int last_bit = (n&1);
       ans += p * last_bit;
       n = n >> 1;
	}
	return ans;
}

int main(){

	int n;
	cin >> n;
	cout<<decimalToBinary(n);

  return 0;
}