
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    int matrixMultiplication(int N, int arr[])
    {
        int dp[N][N] = {0};

        for (int g = 0; g < N - 1; g++) {
            for (int i = 0, j = g; j < N - 1; i++, j++) {
                if (g == 0) {
                    dp[i][j] = 0;
                }
                else if (g == 1) {
                    dp[i][j] = arr[i] * arr[j] * arr[j + 1];
                }
                else {
                    int ans = INT_MAX;
                    for (int k = i; k < j; k++) {
                        int lc = dp[i][k];
                        int rc = dp[k + 1][j];
                        int mc = arr[i] * arr[k + 1] * arr[j + 1];
                        int tc = lc + rc + mc;
                        ans = min(ans, tc);

                    }

                    dp[i][j] = ans;
                }

            }

        }

        // for(int i=0;i<N-1;i++){
        //     for(int j=0;j<N-1;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }

        return dp[0][N - 2];
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.matrixMultiplication(N, arr) << endl;
    }
    return 0;
}