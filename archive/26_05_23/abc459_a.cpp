// https://atcoder.jp/contests/abc459/tasks/abc459_a

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int x;
    cin >> x;
    string s="HelloWorld";
    rep(i,s.size()) {
        if (i+1==x) continue;
        cout<<s[i];
    }

    return 0;
}
