#include <bits/stdc++.h>
using namespace std;

int longestValidParentheses(string s){

        stack<int> st;
        int ans=0;
        st.push(-1);
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='('){
                 st.push(i);
            }
            else if(st.top()!=-1 && s[st.top()]=='(')
            {
                st.pop();
                ans = max(ans,i-st.top());
            }
            else st.push(i);
        }
        return ans;
 

}


int main(){
    string S;
    cin >> S;
    int ans = longestValidParentheses(S);
    cout << ans;
}
