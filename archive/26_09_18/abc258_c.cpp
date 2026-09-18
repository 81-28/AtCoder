// https://atcoder.jp/contests/abc258/tasks/abc258_c

#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    string s;
    cin >> n >> q >> s;
    int b=0;
    while (q--) {
        int t,x;
        cin >> t >> x;
        if (t&1) b=(b-x+n)%n;
        else cout<<s[(b+x-1)%n]<<'\n';
    }

    return 0;
}
