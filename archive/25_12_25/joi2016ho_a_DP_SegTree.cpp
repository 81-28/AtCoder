// https://atcoder.jp/contests/joi2016ho/tasks/joi2016ho_a

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

using ll=long long;
#define int ll
constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


struct S{
    int mx,mi;
    S(int x,int y) {
        mx=x;
        mi=y;
    }
    S(int x) {
        mx=mi=x;
    }
    S(){
        mx=-INF;
        mi=INF;
    }
};
S op(S a,S b){return S(max(a.mx,b.mx),min(a.mi,b.mi));}
S e(){return S();}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,k;
    cin >> n >> m >> k;
    vi a(n);
    cin >> a;
    // 区間の{最大値,最小値}を同時に求める
    // 下のDPでlが遡る時に求める方法O(1)もある
    v<S> init(n);
    rep(i,n) init[i]=S(a[i]);
    segtree<S,op,e> t(init);
    // dp[i]:i個のオレンジを詰める時の最小コスト
    vi dp(n+1,INF);
    dp[0]=0;
    // iから見てj個を同じ箱に入れることを考える
    rep1(i,n)rep1(j,m) {
        int l=i-j;
        if (l<0) break;
        S res=t.prod(l,i);
        chmin(dp[i],dp[l]+k+j*(res.mx-res.mi));
    }
    print(dp[n]);

    return 0;
}
