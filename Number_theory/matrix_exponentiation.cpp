// problem invoves linear recurrences
//linear recurrences is a function in which each term of the seq
// is a linear combination of prev terms.
// k^3 o(log n)


/* steps -
1. find the k.
k is the no. of terms in which f(n) depends

2. find out first k terms.

3. find transformation matrix T (k*k)

F = (T)^n-1 * F(1)

*/

#include<iostream>
#include<vector>
using namespace std;

#define ll long long
#define MOD 1000000000

ll k;
vector<ll> a, b, c;

vector<vector<ll> > multiply(vector<vector<ll> > A, vector<vector<ll> > B) {

	//lets store the result in some matrix C
	vector<vector<ll> > C
	//logic to multiply matrices
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= k; j++) {
			for (int x = i; x < k; x++) {
				C[i][j] = (C[i][j] + (A[i][x] * B[x][j]) % MOD) % MOD;

			}
		}
	}

	return C;
}

vector<vector<ll> > pow(power<vector<ll> > A, ll p ) {

	//base case
	if (p == 1) {
		return A;
	}

	//power is odd

	if (p & 1) {
		return multiply(A * pow(A, p - 1));
	}

	vector<vector<ll>> X = power(A, p / 2);
	return multiply(X, X);
}

ll compute(ll n) {


	//base case
	if (n == 0) {
		return 0;
	}

	if (n <= k) {
		return b[n - 1];
	}

	//otherwise use matrix exponentiation
	vector<ll> F1(k + 1);
	//indexing from 1

	//step -1
	for (int i = 1; i <= k; i++) {
		F1[i] = b[i - 1];
	}

	//step 2 - transformation matrix
	vector<vector<ll> > T(k + 1, vector<ll>(k + 1));

	// shifted identity matrix with last row having cofficients
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= k; j++) {
			if (i < k) {
				//fill 0s and 1s
				if (j == i + 1) {
					T[i][j] = 1;
				} else {
					T[i][j] = 0;
				}
			} else { // when i==k
				// put cofficients in reverse order
				T[i][j] = c[k - j];
			}
		}
	}

	//step 3
	T = pow(T, n - 1);

	// step 4
	ll res = 0;


	for (int i = 1; i <= k; i++) {
		//calculating only nth term
		res = (res + (T[1][i] * F1[i]) % MOD) % MOD;
	}

	return res;
}

int main() {
	ll t, n, num;

	cin >> t

	while (t--) {
		cin >> k;

		//init vector F1
		for (int i = 0; i < k; i++) {
			cin >> num;
			b.push_back(num);
		}

		//coefficients
		for (int i = 0; i < k; i++) {
			cin >> num;
			c.push_back(num);
		}

		//the value of n
		cin >> n;
		cout << compute(n) << "\n";

		b.clear();
		c.clear();
	}


	return 0;
}





