// https://atcoder.jp/contests/abc295/tasks/abc295_a

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define YesNo(x) puts(x?"Yes":"No")

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    map<string,bool> m;
    m["and"]=m["not"]=m["that"]=m["the"]=m["you"]=1;
    rep(i,n) {
        string s;
        cin >> s;
        if (m[s]) {
            YesNo(1);
            return 0;
        }
    }
    YesNo(0);

    return 0;
}
