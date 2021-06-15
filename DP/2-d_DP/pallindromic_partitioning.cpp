
#include <bits/stdc++.h>
using namespace std;



class Solution {
public:



    int palindromicPartition(string str)
    {
        bool dp[str.length() + 1][str.length() + 1]; // matrix to store pallindrome check

        for (int g = 0; g < str.length(); g++) {
            for (int i = 0, j = g; i < str.length(); j++, i++) {
                if (g == 0) {
                    dp[i][j] = true;
                }
                else if (g == 1) {
                    dp[i][j] = (str[i] == str[j]);
                } else {
                    if (str[i] == str[j] && dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = false;
                    }
                }
            }
        }

        int arr[str.length() + 1]; // no. of cuts
        arr[0] = 0;
        for (int j = 0; j < str.length(); j++) {
            if (dp[0][j]) { // if already pall
                arr[j] = 0;
            }
            else {
                int ans = INT_MAX;
                for (int i = j; i >= 1; i--) {
                    if (dp[i][j]) { // if pall
                        int k = arr[i - 1];
                        ans = min(k, ans);
                    }
                }

                arr[j] = 1 + ans;
            }
        }
        // for(int j=0;j<str.length();j++){
        //     cout<<arr[j]<<" ";
        // }

        return arr[str.length() - 1];
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;
        cout << ob.palindromicPartition(str) << "\n";
    }
    return 0;
}