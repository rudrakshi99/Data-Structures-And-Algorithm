#include<bits/stdc++.h>
#define boost ios::sync_with_stdio(false); cin.tie(0)
#define ll              long long int
#define MOD             998244353
using namespace std;

ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, MOD - 2);}

int main()
{
    boost;
    //property
    // k(number of connected component) =  v(vertices) - f(faces) - e (edges) - 1
    ll m, n, k; cin >> m >> n >> k;
    ll E_e, E_f = 1, E_1 = 1, E_v, ans;
    E_v = mul(n, m);
    E_e = mul(add(mul(n, sub(m, 1)) , mul(m, sub(n, 1))), mod_inv(k)); // dividing by k for probability
    if (m == 2) E_f = add(E_f, mul(sub(n, 1), mod_inv(power(k, 3))));
    ans = sub(add(E_v , E_f) , add(E_e , E_1));
    cout << ans;

    return 0;
}
