// https://atcoder.jp/contests/abc476/tasks/abc476_a

#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    if (s.back()=='e') cout<<s<<"r";
    else cout<<s<<"er";

    return 0;
}
