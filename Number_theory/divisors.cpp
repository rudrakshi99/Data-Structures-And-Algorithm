//no. of divisors
#include<iostream>
#include<vector>
using namespace std;
#define ll long long

vector<int> prime_sieve(int *p, int n){
     //first odd numbers as prime
	 for(int i=3;i<=10000;i+=2){
        p[i] = 1;
	 }

	 for(ll i=3;i<=10000;i+=2){
         //if it is prime
	 	if(p[i]==1){
         //mark all the multiples of i as not prime
	 		for(ll j=i*i; j <=10000; j=j+i){
               p[j] = 0;
	 		}
	 	}
	 }

	 //special case
	 p[2] = 1;
	 p[1] = p[0] = 0;

	 vector<int> v(n+1);
	 int k = 0;
	 for(int i=0;i<=n;i++) {
       if(p[i]==1){
          v[k]=i;
          k++;
       }
	}
	return v;
}

int factorize(int m, vector<int> &primes){

       int i=0;
       int p = primes[0];
       int ans = 1;
       while(p*p<=m){

            if(m%p==0){
               int c = 0;
              while(m%p==0){
                c++;
                 m = m/p;
              }

              ans = ans * (c + 1);
            }
            //go to the next position
            i++;
            p = primes[i];
       }

       if(m!=1){
          ans = ans * 2;
       }
       return ans;
}

int main(){

	
	int p[10005];
	for(int i=0;i<10005;i++){
        p[i] = 0;
	}
	vector<int> primes = prime_sieve(p, 100);
	
    int t;
    cin >> t;
    while(t--){

        int no;
        cin >> no;
        cout<<factorize(no, primes);

        
    }

  return 0;
}