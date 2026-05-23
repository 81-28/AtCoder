// https://atcoder.jp/contests/abc459/tasks/abc459_e

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using vb=v<bool>;
using pii=pair<int,int>;
using mint=modint998244353;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


mint ans=1;
vvi g;
vb b;
vi cnt,c,d;
v<pii> pa;
int mxr=0;

void dfs(int n) {
    int res=c[n];
    b[n]=1;
    for (int nxt:g[n]) {
        if (b[nxt]) continue;
        dfs(nxt);
        res+=cnt[nxt];
    }
    cnt[n]=res;
    pa.pb({mint(cnt[n]).val(),mint(d[n]).val()});
    chmax(mxr,(int)mint(d[n]).val());
    cnt[n]-=d[n];
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    g=vvi(n);
    rep1(i,n-1) {
        int p;
        cin >> p;
        --p;
        g[i].pb(p);
        g[p].pb(i);
    }
    c=d=vi(n);
    cin >> c >> d;

    b=vb(n,0);
    cnt=vi(n,0);
    dfs(0);

    v<mint> inv(mxr+1,1);
    for (int i=2; i<=mxr; ++i) inv[i]=mint(i).inv();

    for (auto[l,r]:pa) {
        for (int i=1; i<=r; ++i) ans*=mint(l+1-i)*inv[i];
    }

    print(ans.val());

    return 0;
}
