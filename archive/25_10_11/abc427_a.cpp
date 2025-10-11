// https://atcoder.jp/contests/abc427/tasks/abc427_a

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int n=s.size();
    int mid=n/2;
    rep(i,n) {
        if (i!=mid) cout<<s[i];
    }
    cout<<endl;

    return 0;
}
