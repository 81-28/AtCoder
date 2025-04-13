// https://atcoder.jp/contests/abc401/tasks/abc401_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(ll i=1;i<=(ll)(n);i++)
#define pb push_back
template<typename T>
using v=vector<T>;
using vll=v<ll>;
using vvll=v<vll>;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


vvll g;
unordered_set<ll> ok,s;
void dfs(const ll& n,const ll& i) {
    for (ll val:g[n]) {
        if (val>i) {
            s.insert(val);
        } else {
            if (ok.find(val)==ok.end()) {
                ok.insert(val);
                dfs(val,i);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n,m;
    cin >> n >> m;
    g = vvll(n+1);
    ll a,b;
    rep1(i,m) {
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    s.insert(1);
    rep1(i,n) {
        if (s.find(i)!=s.end()){
            s.erase(i);
        } else {
            print(-1);
            continue;
        }
        ok.insert(i);
        dfs(i,i);
        if (ok.size()==i) print(s.size());
        else print(-1);
    }

    return 0;
}
