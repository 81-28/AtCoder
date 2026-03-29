// https://atcoder.jp/contests/abc273/tasks/abc273_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    int k;
    cin >> s >> k;
    int n=s.size();
    int l=16;
    s=string(l-n,'0')+s;
    int sm=0;
    rep(i,k) {
        int j=l-1-i;
        sm+=(s[j]-'0');
        sm=sm>4;
        s[j]='0';
    }
    for (int i=k; i<l; ++i) {
        int j=l-1-i;
        sm+=(s[j]-'0');
        s[j]=(sm%10+'0');
        sm/=10;
    }
    bool b=0;
    rep(i,l) {
        if (b||s[i]!='0') {
            cout<<s[i];
            b=1;
        }
    }
    if (!b) cout<<0;
    cout<<endl;

    return 0;
}
