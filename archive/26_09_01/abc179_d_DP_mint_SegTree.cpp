// https://atcoder.jp/contests/abc179/tasks/abc179_d

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
using mint=modint998244353;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define all(v) v.begin(),v.end()

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


using S=mint;
S op(S a,S b){return a+b;}
S e(){return S();}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    v<pii> p(k);
    for (auto&[a,b]:p) cin >> a >> b;
    sort(all(p));

    v<S> init(n,0);
    init[0]=1;
    segtree<S,op,e> dp(init);

    rep1(i,n-1) {
        mint sm=0;
        for (auto[a,b]:p) {
            int l=max(0,i-b);
            int r=max(0,i-a+1);
            if (l>=r) break;
            sm+=dp.prod(l,r);
        }
        dp.set(i,sm);
    }
    print(dp.get(n-1).val());

    return 0;
}
