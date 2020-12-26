#include<iostream>
#include<stack>
#include<climits>
using namespace std;
#define ll long long

int main() {
    ll n;
	cin >> n;
	ll arr[n+1];
	stack<ll> s;
	for(ll i=0;i<n;i++){
		cin >> arr[i];
	}
	ll max = 0,ans;

	for(ll i=1;i<n;i++){
        
        
        while(!s.empty()&&arr[s.top()]>arr[i]){
            int top=s.top();
            s.pop();
			if(s.empty()){
                        ans=arr[top]*i;
                     }
			else{
			    ans =arr[top]*(i-s.top()-1);
			}
            if(max<ans)
            max=ans;
        }
        s.push(i);
    }
	ll size=s.size();
    while(!s.empty()){
		ll tp = s.top();
         s.pop();
		   ans = arr[tp]*(size-s.size());
		   if(max<ans ){
			max = ans;
		}
	}

	cout<<max<<"\n";
	return 0;
}
