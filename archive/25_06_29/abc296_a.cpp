// https://atcoder.jp/contests/abc296/tasks/abc296_a

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define YesNo(x) puts(x?"Yes":"No")

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    rep(i,n-1) {
        if (s[i]==s[i+1]) {
            YesNo(0);
            return 0;
        }
    }
    YesNo(1);

    return 0;
}
