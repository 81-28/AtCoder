// https://atcoder.jp/contests/abc448/tasks/abc448_a

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

    int n,x;
    cin >> n >> x;
    vi a(n);
    cin >> a;
    rep(i,n) {
        if (a[i]<x) {
            x=a[i];
            cout<<1<<' ';
        } else cout<<0<<' ';
    }
    cout<<endl;

    return 0;
}
