// https://atcoder.jp/contests/abc278/tasks/abc278_a

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

    int n,k;
    cin >> n >> k;
    vi a(n);
    cin >> a;
    rep(i,n-k) cout<<a[i+k]<<' ';
    rep(i,min(k,n)) cout<<0<<' ';
    cout<<endl;

    return 0;
}
