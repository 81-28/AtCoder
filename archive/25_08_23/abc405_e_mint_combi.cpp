// https://atcoder.jp/contests/abc405/tasks/abc405_e

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

using mint=modint998244353;
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

    int a,b,c,d;
    cin >> a >> b >> c >> d;
    CombinationMint m(max({a,b,c,d})*3);
    mint ans=0;
    // (a個のリンゴとc-i個のバナナ)と(b個のオレンジ) | (左端のブドウ) | (d-1個のブドウ)と(i個のバナナ)
    // リンゴとバナナは順番固定→1種類のフルーツのように扱える
    for (int i=0; i<=c; ++i) ans+=m.nCr(a+c-i+b,b)*m.nCr(d-1+i,i);
    print(ans.val());

    return 0;
}
