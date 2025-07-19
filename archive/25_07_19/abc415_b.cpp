// https://atcoder.jp/contests/abc415/tasks/abc415_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int n=s.size();
    bool a=0;
    int l;
    rep(i,n) {
        if (s[i]=='#') {
            if (a) {
                cout<<l<<','<<i+1<<endl;
            } else {
                l=i+1;
            }
            a=!a;
        }
    }

    return 0;
}
