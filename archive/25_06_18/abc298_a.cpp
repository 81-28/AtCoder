// https://atcoder.jp/contests/abc298/tasks/abc298_a

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define YesNo(x) puts(x?"Yes":"No")

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    int g=0,b=0;
    rep(i,n) {
        if (s[i]=='o') ++g;
        if (s[i]=='x') ++b;
    }
    YesNo(g&&!b);

    return 0;
}
