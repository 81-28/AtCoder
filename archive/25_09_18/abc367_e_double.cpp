// https://atcoder.jp/contests/abc367/tasks/abc367_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    // x[i][j]:2^i回操作後のjの位置の数のインデックス
    vi x(n),a(n);
    cin >> x >> a;
    rep(i,n) --x[i];
    // idx[i]:最終的なiの位置の数のインデックス
    vi idx(n);
    rep(i,n) idx[i]=i;
    for (; k; k>>=1) {
        if (k&1) {
            rep(i,n) idx[i]=x[idx[i]];
        }
        vi nx(n);
        rep(i,n) nx[i]=x[x[i]];
        x=nx;
    }
    vi ans(n);
    rep(i,n) ans[i]=a[idx[i]];
    print(ans);

    return 0;
}
