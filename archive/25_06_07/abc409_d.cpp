// https://atcoder.jp/contests/abc409/tasks/abc409_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
using ll=long long;


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        string s;
        cin >> n >> s;
        ll l=0,r=-1;
        for (; l<n-1; ++l) {
            if (s[l]>s[l+1]) {
                r=l+1;
                break;
            }
        }
        for (; r<n; ++r) {
            if (s[l]<s[r]) break;
        }
        --r;
        rep(i,n) {
            int j=i;
            if (l<=i&&i<r) ++j;
            if (i==r) j=l;
            cout<<s[j];
        }
        cout<<'\n';
    }

    return 0;
}
