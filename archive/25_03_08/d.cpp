// https://atcoder.jp/contests/abc396/tasks/abc396_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define all(v) v.begin(),v.end()
using ull=unsigned long long;
template<typename T>
using v=vector<T>;
using vi=v<int>;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int n;
v<set<int>> g;
v<map<int,ull>> c;
int p;
ull ans=ULLONG_MAX,nans;

void f(const v<int>& r) {
    nans=0;
    p=1;
    for (int val:r) {
        if (g[p].find(val) != g[p].end()) {
            nans ^= c[p][val];
            p=val;
            if (g[p].find(n) != g[p].end()) {
                ans=min(ans,nans^c[p][n]);
            }
        } else break;
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int m;
    cin >> n >> m;
    g = v<set<int>>(n+1);
    int a,b;
    ull w;
    c = v<map<int,ull>>(n+1);
    rep(i,m) {
        cin >> a >> b >> w;
        g[a].insert(b);
        g[b].insert(a);
        c[a][b]=w;
        c[b][a]=w;
    }

    if (g[1].find(n) != g[1].end()) {
        ans=min(ans,c[1][n]);
    }

    vi r;
    for (int i=2; i<n; i++) r.pb(i);
    f(r);
    while (next_permutation(all(r))) {
        f(r);
    }
    print(ans);

    return 0;
}
