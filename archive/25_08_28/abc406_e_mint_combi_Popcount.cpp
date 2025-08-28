// https://atcoder.jp/contests/abc406/tasks/abc406_e

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

using ll=long long;
#define int ll
using mint=modint998244353;

#define f first
#define s second

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
};

CombinationMint m(60);

// {パターン数,合計}
pair<mint,mint> solve(const int& n,const int& k) {
    if (k==0) return {1,0};
    if (n==0) return {0,0};
    int d=0;
    for (int i=n; i>1; i>>=1) ++d;
    // n以下で最大の2の冪乗
    int sub=(1LL<<d);
    // 最上位桁を固定して、{subを使った回数,残りの桁の合計}を求める
    auto p=solve(n-sub,k-1);
    // {sub未満でPopcountがk} + {sub以上でPopcountがk}
    mint res=(sub-1)*m.nCr(d-1,k-1)+sub*p.f+p.s;
    return {m.nCr(d,k)+p.f,res};
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        print(solve(n,k).s.val());
    }

    return 0;
}
