// https://atcoder.jp/contests/abc417/tasks/abc417_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

#define f first
#define s second

template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


int y;
map<int,map<int,bool>> g;
map<int,bool> b;
bool ok=0;
vi ans;
void dfs(int x,vi vec) {
    if (ok) return;
    if (x==y) {
        ans=vec;
        ok=1;
        return;
    }
    for (auto nxt:g[x]) {
        if (b[nxt.f]) continue;
        vi vvec=vec;
        vvec.pb(nxt.f);
        b[nxt.f]=1;
        dfs(nxt.f,vvec);
    }
    
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin >> n >> m >> x >> y;
        g=map<int,map<int,bool>>();
        rep(i,m) {
            pii p;
            cin >> p;
            g[p.f][p.s]=1;
            g[p.s][p.f]=1;
        }
        ans=vi();
        ok=0;
        b=map<int,bool>();
        b[x]=1;
        dfs(x,{x});
        print(ans);
    }

    return 0;
}
