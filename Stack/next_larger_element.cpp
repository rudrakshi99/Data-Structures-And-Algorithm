#include <bits/stdc++.h>
using namespace std;

vector<int> nextLargerElement( vector<int>& A) {

    int n = A.size();
    vector<int> ans(n, -1);
 
    stack<int> s;
 
    for (int i = 0; i < n; i++)
    {
 
        while (!s.empty() && A[s.top()] < A[i])
        {
            ans[s.top()] = A[i];
            s.pop();
        }
 
        s.push(i);
    }
 
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for ( int i = 0; i < n; i++) cin >> A[i];

    vector<int> next_larger = nextLargerElement(A);
    for ( int i = 0; i < n; i++) {
        cout << next_larger[i] << " ";
    }
}
