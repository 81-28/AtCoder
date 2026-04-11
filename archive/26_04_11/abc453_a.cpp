// https://atcoder.jp/contests/abc453/tasks/abc453_a

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    bool b=0;
    rep(i,n) {
        if (b||s[i]!='o') {
            cout<<s[i];
            b=1;
        }
    }
    cout<<endl;

    return 0;
}
