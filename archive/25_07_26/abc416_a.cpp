// https://atcoder.jp/contests/abc416/tasks/abc416_a

#include<bits/stdc++.h>
using namespace std;

#define YesNo(x) puts(x?"Yes":"No")

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,l,r;
    string s;
    cin >> n >> l >> r >> s;
    for (int i=l-1; i<r; ++i) {
        if (s[i]=='x') {
            YesNo(0);
            return 0;
        }
    }
    YesNo(1);

    return 0;
}
