// https://atcoder.jp/contests/joi2016yo/tasks/joi2016yo_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,t,q;
    cin >> n >> t >> q;
    v<pii> p(n);
    rep(i,n) cin >> p[i];
    vi x(q);
    cin >> x;
    vi stop;
    vi ans(n,INF);
    // 近づく隣り合う人は、ぶつかって中点で止まる
    rep(i,n-1) {
        auto[l,dl]=p[i];
        auto[r,dr]=p[i+1];
        if (dl!=1 || dr!=2) continue;
        int mid=(l+r)/2;
        if (mid-l>t) {
            ans[i]=l+t;
            ans[i+1]=r-t;
        } else {
            ans[i]=ans[i+1]=mid;
            stop.pb(mid);
        }
    }
    // それ以外の人は、上の止まっている人に当たれば止まる
    rep(i,n) {
        if (ans[i]!=INF) continue;
        auto[pos,d]=p[i];
        if (d==1) {
            auto it=upper_bound(all(stop),pos);
            if (it==stop.end() || *it-pos>t) ans[i]=pos+t;
            else ans[i]=*it;
        } else {
            auto it=lower_bound(all(stop),pos);
            if (it==stop.begin() || pos-*--it>t) ans[i]=pos-t;
            else ans[i]=*it;
        }
    }
    for (int i:x) print(ans[i-1]);

    return 0;
}
