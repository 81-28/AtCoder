// https://atcoder.jp/contests/abc411/tasks/abc411_a

#include<bits/stdc++.h>
using namespace std;

#define YesNo(x) puts(x?"Yes":"No")

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    int l;
    cin >> s >> l;
    YesNo(s.size() >= l);

    return 0;
}
