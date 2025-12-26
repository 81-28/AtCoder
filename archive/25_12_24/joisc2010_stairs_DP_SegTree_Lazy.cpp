// https://atcoder.jp/contests/joisc2010/tasks/joisc2010_stairs

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
#define all(v) v.begin(),v.end()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


using S=int;
S op(S a,S b){return min(a,b);}
S e(){return INF;}
using F=int;
S mapping(F f,S x){return f+x;}
F composition(F f,F g){return f+g;}
F id(){return 0;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int m=1234567;
    int n,p;
    cin >> n >> p;
    vi h(n);
    cin >> h;
    vi sm(n+1,0);
    rep1(i,n) sm[i]=sm[i-1]+h[i-1];
    // dp[i]:i段昇った位置でのパターン数
    // 配るDP
    v<S> init(n+1,0);
    init[0]=1;
    lazy_segtree<S,op,e,F,mapping,composition,id> dp(init);
    rep(i,n) {
        int add=dp.get(i)%m;
        int now=sm[i];
        auto it=upper_bound(all(sm),now+p);
        int j=it-sm.begin();
        dp.apply(i+1,j,add);
    }
    print(dp.get(n)%m);

    return 0;
}
