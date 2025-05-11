// https://atcoder.jp/contests/abc303/tasks/abc303_e

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()
#define f first
#define s second
template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi d(n,0);
    pii p;
    rep(i,n-1) {
        cin >> p;
        --p.f,--p.s;
        ++d[p.f],++d[p.s];
    }
    int cnt=0;
    rep(i,n) {
        if (d[i]>1) ++cnt;
    }
    cnt=(cnt+2)/3;
    sort(all(d));
    for (int i=n-cnt;i<n;++i) {
        cout<<d[i]<<' ';
    }
    cout<<'\n';

    return 0;
}
