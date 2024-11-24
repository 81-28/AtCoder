// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ec

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define YesNo(x) cout<<(x?"Yes\n":"No\n")

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q,l,r;
    string s,t;
    cin >> n >> q >> s;
    t = s;
    reverse(all(t));
    cout<<s<<' '<<t<<'\n';
    s = ' '+s;
    rep(i,q) {
        cin >> l >> r;
        // YesNo(substring(s,l,r+1)==substring(t,n-r,n-l+1));
        YesNo(s.substr(l,r-l+1)==t.substr(n-r,r-l+1));
    }

    return 0;
}
