// https://atcoder.jp/contests/abc362/tasks/abc362_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back
template<class T>constexpr bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
#define f first
#define s second

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}

// pairのデクリメント
template<typename F,typename S>
pair<F,S>& operator--(pair<F,S>& p){--p.f;--p.s;return p;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vi a(n);
    cin >> a;
    v<v<pii>> g(n);
    rep1(i,m) {
        pii p;
        int b;
        cin >> p >> b;
        --p;
        g[p.f].pb({p.s,b+a[p.s]});
        g[p.s].pb({p.f,b+a[p.f]});
    }
    // c[i]:位置iに来る最小コスト
    vi c(n,LLONG_MAX);
    c[0]=a[0];
    // q = {距離, 位置}
    priority_queue<pii,v<pii>,greater<>> q;
    q.push({c[0],0});
    while (!q.empty()) {
        auto [d,pos]=q.top();
        q.pop();
        if (d>c[pos]) continue;
        for (auto [nxt,w]:g[pos]) {
            if (chmin(c[nxt],d+w)) q.push({c[nxt],nxt});
        }
    }
    rep1(i,n-1) cout<<c[i]<<' ';
    cout<<endl;

    return 0;
}
