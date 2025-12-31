// https://atcoder.jp/contests/abc286/tasks/abc286_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    cout<<s[0];
    rep(i,n-1) {
        if (s[i]=='n' && s[i+1]=='a') cout<<'y';
        cout<<s[i+1];
    }
    cout<<endl;

    return 0;
}
