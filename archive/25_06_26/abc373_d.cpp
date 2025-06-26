// https://atcoder.jp/contests/abc373/tasks/abc373_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define f first
#define s second

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

// pairのデクリメント
template<typename F,typename S>
pair<F,S>& operator--(pair<F,S>& p){--p.f;--p.s;return p;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vvi g(n);
    map<pii,int> c;
    rep(i,m) {
        pii p;
        int w;
        cin >> p >> w;
        --p;
        g[p.f].pb(p.s);
        g[p.s].pb(p.f);
        c[p]=w;
        c[{p.s,p.f}]=-w;
    }
    vi ans(n);
    v<bool> b(n,0);
    queue<int> q;
    rep(i,n) {
        if (b[i]) continue;
        ans[i]=0;
        b[i]=1;
        q.push(i);
        while (!q.empty()) {
            int pos=q.front();
            q.pop();
            for (int val:g[pos]) {
                if (!b[val]) {
                    ans[val]=ans[pos]+c[{pos,val}];
                    b[val]=1;
                    q.push(val);
                }
            }
        }
    }
    print(ans);

    return 0;
}
