// https://atcoder.jp/contests/abc444/tasks/abc444_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define all(v) v.begin(),v.end()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    sort(all(a));
    int l=0,r=n-1;
    int sm=a[r];
    while (a[r]==sm) --r;
    if (!((r+1-l)&1)) {
        bool ok=1;
        for (; l<r; ++l,--r) {
            if (a[l]+a[r]!=sm) {
                ok=0;
                break;
            }
        }
        if (ok) cout<<sm<<' ';
    }
    l=0,r=n-1;
    sm=a[l]+a[r];
    if (!((r+1-l)&1)) {
        bool ok=1;
        for (; l<r; ++l,--r) {
            if (a[l]+a[r]!=sm) {
                ok=0;
                break;
            }
        }
        if (ok) cout<<sm<<' ';
    }
    cout<<endl;

    return 0;
}
