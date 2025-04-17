// https://atcoder.jp/contests/abc306/tasks/abc306_a

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    rep(i,n) cout<<s[i]<<s[i];
    cout<<'\n';

    return 0;
}
