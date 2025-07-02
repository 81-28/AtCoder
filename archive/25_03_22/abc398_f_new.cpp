// https://atcoder.jp/contests/abc398/tasks/abc398_f

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int n=s.size();
    bool ok;
    int l,r;
    rep(i,n) {
        ok=1;
        l=i,r=n-1;
        while (l<r) {
            if (s[l]!=s[r]) {
                ok=0;
                break;
            }
            l++,r--;
        }
        if (ok) {
            cout<<s;
            rep(j,i) cout<<s[i-1-j];
            cout<<'\n';
            return 0;
        }
    }

    return 0;
}
