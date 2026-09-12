// https://atcoder.jp/contests/abc475/tasks/abc475_a

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int n=s.size();
    rep(i,n-1) cout<<s[i]<<'o';
    cout<<s[n-1];

    return 0;
}
