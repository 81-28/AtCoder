// https://atcoder.jp/contests/abc171/tasks/abc171_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    int x=0;
    rep(i,n) x^=a[i];
    rep(i,n) cout<<(x^a[i])<<' ';
    cout<<'\n';

    return 0;
}
