// https://atcoder.jp/contests/abc418/tasks/abc418_a

#include<bits/stdc++.h>
using namespace std;

#define YesNo(x) puts(x?"Yes":"No")

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    YesNo(s[n-3]=='t' && s[n-2]=='e' && s[n-1]=='a');

    return 0;
}
