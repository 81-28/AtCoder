// https://atcoder.jp/contests/abc320/tasks/abc320_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define f first
#define s second
using ll=long long;
template<typename T>
using v=vector<T>;
using vll=v<ll>;
using pll=pair<ll,ll>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
template<typename F,typename S>
ostream &operator<<(ostream &os,const pair<F,S> &p){os<<p.first<<" "<<p.second;return os;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n,m;
    cin >> n >> m;
    v<v<pair<ll,pll>>> g(n);
    vll p(4);
    rep(i,m) {
        cin >> p;
        p[0]--,p[1]--;
        g[p[0]].pb({p[1],{p[2],p[3]}});
        g[p[1]].pb({p[0],{-p[2],-p[3]}});
    }

    v<pll> ans(n,{LLONG_MIN,LLONG_MIN});
    v<bool> d(n,0);
    ans[0] = {0,0};
    d[0]=1;

    queue<ll> q;
    q.push(0);
    ll now;
    while (!q.empty()) {
        now=q.front();
        q.pop();
        for (pair<ll,pll> pp:g[now]) {
            if (!d[pp.f]) {
                ans[pp.f] = {ans[now].f + pp.s.f, ans[now].s + pp.s.s};
                d[pp.f]=1;
                q.push(pp.f);
            }
        }
    }
    rep(i,n) {
        if (ans[i]==pll(LLONG_MIN,LLONG_MIN)) {
            print("undecidable");
        } else print(ans[i]);
    }

    return 0;
}
