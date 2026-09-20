// https://atcoder.jp/contests/arc230/tasks/arc230_a

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using mint=modint998244353;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


class CombinationMint {
private:
    vector<mint> fact,inv_fact;
public:
    CombinationMint(const int& n) {
        fact.resize(n+1);
        inv_fact.resize(n+1);
        fact[0]=1;
        for(int i=1; i<=n; ++i) fact[i]=fact[i-1]*i;
        inv_fact[n]=fact[n].inv();
        for(int i=n-1; i>=0; --i) inv_fact[i]=inv_fact[i+1]*(i+1);
    }
    mint nCr(const int& n,const int& r) {
        if(r>n||r<0) return 0;
        return fact[n]*inv_fact[r]*inv_fact[n-r];
    }
    mint nPr(const int& n,const int& r) {
        if(r>n||r<0) return 0;
        return fact[n]*inv_fact[n-r];
    }
};

vi siz;
vvi chi;
int dfs(int n) {
    for (int nxt:chi[n]) siz[n]+=dfs(nxt);
    return siz[n];
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vvi g(n);
    rep(i,n-1) {
        int x,y;
        cin >> x >> y;
        --x,--y;
        g[x].pb(y);
        g[y].pb(x);
    }

    CombinationMint cm(n);

    mint pw=mint(2).pow(n);
    v<mint> m(n+1);
    m[0]=mint(n)*pw/2;

    mint sm=0;
    rep(i,n) {
        sm+=cm.nCr(n,i);
        m[i+1]=m[i]+2*sm-pw;
    }

    // 0を根とした木
    vi d(n,n);
    chi=vvi(n);
    d[0]=0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int pos=q.front();
        q.pop();
        for (int nxt:g[pos]) {
            if (chmin(d[nxt],d[pos]+1)) {
                q.push(nxt);
                chi[pos].pb(nxt);
            }
        }
    }
    // 部分木のサイズ
    siz=vi(n,1);
    dfs(0);

    mint ans=0;
    rep1(i,n-1) {
        ans+=mint(n)*pw/4-m[siz[i]]/2;
    }
    print(ans.val());

    return 0;
}
