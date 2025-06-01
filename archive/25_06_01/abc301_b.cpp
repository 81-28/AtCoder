// https://atcoder.jp/contests/abc301/tasks/abc301_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    cout<<a[0];
    rep(i,n-1) {
        int add=(a[i]<a[i+1])*2-1;
        for (int j=a[i]+add; j!=a[i+1]; j+=add) cout<<' '<<j;
        cout<<' '<<a[i+1];
    }
    cout<<'\n';

    return 0;
}
