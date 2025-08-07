// https://atcoder.jp/contests/abc293/tasks/abc293_a

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int n=s.size()/2;
    rep(i,n) cout<<s[i*2+1]<<s[i*2];
    cout<<endl;

    return 0;
}
