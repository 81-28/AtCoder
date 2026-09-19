// https://atcoder.jp/contests/abc476/tasks/abc476_e

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}


using S_max = int;
S_max op_max(S_max a, S_max b){ return max(a,b); }
S_max e_max(){ return -INF; }

using S_min = int;
S_min op_min(S_min a, S_min b){ return min(a,b); }
S_min e_min(){ return INF; }

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vi p(n);
    cin >> p;

    vi idx(n);
    rep(i,n) {
        --p[i];
        idx[p[i]]=i;
    }
    segtree<S_max,op_max,e_max> t_max(p);
    segtree<S_min,op_min,e_min> t_min(p);

    while (m--) {
        int l,r;
        cin >> l >> r;
        --l;
        int mx=t_max.prod(l,r);
        int mi=t_min.prod(l,r);
        int i=idx[mx];
        int j=idx[mi];
        int tmp=p[i];
        p[i]=p[j];
        p[j]=tmp;
        idx[p[i]]=i;
        idx[p[j]]=j;
        t_max.set(i,p[i]);
        t_max.set(j,p[j]);
        t_min.set(i,p[i]);
        t_min.set(j,p[j]);
    }
    for (int val:p) cout<<val+1<<' ';
    cout<<'\n';

    return 0;
}
