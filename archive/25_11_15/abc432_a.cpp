// https://atcoder.jp/contests/abc432/tasks/abc432_a

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rall(v) v.rbegin(),v.rend()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    vi a(3);
    cin >> a;
    sort(rall(a));
    rep(i,3) cout<<a[i];
    cout<<endl;

    return 0;
}
