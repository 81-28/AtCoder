// https://atcoder.jp/contests/abc307/tasks/abc307_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
template<typename T>
using v=vector<T>;
using vi=v<int>;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    stack<int> st;
    vi b(n+1,0);
    rep(i,n) {
        if (s[i]=='(') st.push(i);
        if (s[i]==')') {
            if (!st.empty()) {
                b[st.top()]++;
                st.pop();
                b[i+1]--;
            }
        }
    }
    rep(i,n) {
        if (i) b[i]+=b[i-1];
        if (!b[i]) cout<<s[i];
    }
    cout<<'\n';

    return 0;
}
