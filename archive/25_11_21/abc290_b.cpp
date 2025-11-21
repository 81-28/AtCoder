// https://atcoder.jp/contests/abc290/tasks/abc290_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    string s;
    cin >> n >> k >> s;
    rep(i,n) {
        if (s[i]=='o'&&k-->0) cout<<'o';
        else cout<<'x';
    }
    cout<<endl;

    return 0;
}
