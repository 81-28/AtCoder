// https://atcoder.jp/contests/abc394/tasks/abc394_d

#include<bits/stdc++.h>
using namespace std;

#define YesNo(x) cout<<(x?"Yes\n":"No\n")

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int n=s.size();
    stack<int> st;
    if (s[0]==')' || s[0]==']' || s[0]=='>') {
        YesNo(0);
        return 0;
    }
    if (s[0]=='(')st.push(0);
    if (s[0]=='[')st.push(1);
    if (s[0]=='<')st.push(2);
    int l;
    for (int i=1; i<n; i++) {
        if (s[i]==')' || s[i]==']' || s[i]=='>') {
            if (st.size() == 0) {
                YesNo(0);
                return 0;
            }
            if (s[i]==')') {
                l=st.top();
                if (l==0) {
                    st.pop();
                } else {
                    YesNo(0);
                    return 0;
                }
            }
            if (s[i]==']') {
                l=st.top();
                if (l==1) {
                    st.pop();
                } else {
                    YesNo(0);
                    return 0;
                }
            }
            if (s[i]=='>') {
                l=st.top();
                if (l==2) {
                    st.pop();
                } else {
                    YesNo(0);
                    return 0;
                }
            }
        } else {
            if (s[i]=='(')st.push(0);
            if (s[i]=='[')st.push(1);
            if (s[i]=='<')st.push(2);
        }
    }
    YesNo(st.size() == 0);

    return 0;
}
