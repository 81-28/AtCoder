// https://atcoder.jp/contests/abc368/tasks/abc368_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;

#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define f first
#define s second

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    v<map<int,bool>> g(n+1);
    vi cnt(n+1,0);
    rep1(i,n-1) {
        pii p;
        cin >> p;
        g[p.f][p.s]=1;
        g[p.s][p.f]=1;
        ++cnt[p.f],++cnt[p.s];

    }
    queue<int> q;
    rep1(i,n) {
        if (cnt[i]==1) q.push(i);
    }
    map<int,bool> m;
    rep1(i,k) {
        int x;
        cin >> x;
        m[x]=1;
    }
    int ans=n;
    while (!q.empty()) {
        int pos=q.front();
        q.pop();
        if (!m[pos]) {
            --ans;
            int par=-1;
            for (auto p:g[pos]) {
                if (p.s) {
                    par=p.f;
                    break;
                }
            }
            if (par==-1) continue;
            g[par][pos]=0;
            if (--cnt[par]==1) q.push(par);
        }
    }
    print(ans);

    return 0;
}
