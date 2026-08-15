// https://atcoder.jp/contests/abc471/tasks/abc471_e

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

using ll=long long;
#define int ll
using mint=modint998244353;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

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

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    CombinationMint m(n);
    mint sm=0,sqsm=0;
    rep(i,n) {
        int a;
        cin >> a;
        sm+=a;
        sqsm+=a*a;
    }
    mint ans=sqsm * m.nCr(n-1,k-1);
    if (k>1) ans+=(sm*sm-sqsm) * m.nCr(n-2,k-2);
    print(ans.val());

    return 0;
}
