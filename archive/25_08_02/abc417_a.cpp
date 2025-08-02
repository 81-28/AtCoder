// https://atcoder.jp/contests/abc417/tasks/abc417_a

#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,a,b;
    string s;
    cin >> n >> a >> b >> s;
    for (int i=a; i+b<n; i++) cout<<s[i];
    cout<<endl;

    return 0;
}
