//no. of subarr b/w 1 to n divisible by all the prime nos less than 20

#include<iostream>
using namespace std;

#define ll long long

int main() {

	ll t;
	cin >> t;

	ll primes[] = {2,3,5,7,11,13,17,19};

	while(t--){

		ll n;
		cin >> n;

		ll subsets = (1<<8)-1; //2^8 - 1
         ll ans =0;

        for(ll i=1;i<=subsets;i++){
           ll deno = 1ll;

           ll setBits = __builtin_popcount(i);

           for(ll j=0;j<=7;j++){

              if(i & (1<<j)){ // if bit is set
                  deno = deno*primes[j];
                 
              }
           }

           if(setBits & 1){ // if total number of bits are odd
               ans += n/deno; // adding cardinality
           }
           else { // even
           	  ans -= n/deno;
           }
        }

        cout<< ans <<endl;
	}

   return 0;
}
