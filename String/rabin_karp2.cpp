#include<iostream>
using namespace std;
#define int long long int

const int mod = 1e9+7;
const int p = 31;
int powr(int a, int b){ // binary exponentiation(a^b %m) - o(log b)
     int res = 1;
     while(b){

       if(b & 1LL){
          res *= a;
          res %= mod;
       }
       b /= 2;
       a *= a;
       a %= mod;
     }
     return res;
}

int inv(int a){ 
   
   //a^-1 % m
	return powr(a, mod-2); //fermats little theorem
}

int poly_hash_string(string s){ // hash function
   
   int p_powr = 1;
   int hash = 0;

   for(int i=0;i<s.size();i++){
      hash += (p_powr*(s[i]-'a' + 1));
      p_powr *= p;
      p_powr *= mod;
      hash %= mod;
   }

   return hash;
   
}

int32_t main(){
    
    string text = "ababab", pat = "aba";

    int pat_hash = poly_hash_string(pat);
     
    int n = text.size(), m = pat.size();

    int pref[n];

    for(int i =0;i < n;i++){
      pref[i] = (text[i] - 'a' + 1)*powr(p, i);
      pref[i] %= mod;
    }

    for(int i=1; i < n;i++){
       pref[i] += pref[i-1];
       pref[i] %= mod;
    }
    for(int i=1;i+m <= n;i++){ 
       // substring from s[l...r]
       //r = i+m-1
      int new_hash = ssspref[i + m - 1];
      if( i -1 > 0) new_hash -= pref[i-1];

      new_hash += mod;
      new_hash %= mod;

      if(new_hash == (pat_hash * powr(p,i))% mod) {
        cout << i <<"\n";
      }

    }
    
   return 0;
}