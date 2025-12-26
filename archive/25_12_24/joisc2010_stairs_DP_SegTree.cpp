// https://atcoder.jp/contests/joisc2010/tasks/joisc2010_stairs

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define all(v) v.begin(),v.end()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


int m=1234567;

using S=int;
S op(S a,S b){return (a+b)%m;}
S e(){return 0;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,p;
    cin >> n >> p;
    vi h(n);
    cin >> h;
    vi sm(n+1,0);
    rep1(i,n) sm[i]=sm[i-1]+h[i-1];
    // dp[i]:i段登った位置でのパターン数
    // 貰うDP
    v<S> init(n+1,0);
    init[0]=1;
    segtree<S,op,e> dp(init);
    rep1(i,n) {
        int now=sm[i];
        // 現在の位置に来れる最小位置を探索
        auto it=lower_bound(all(sm),now-p);
        int j=it-sm.begin();
        dp.set(i,dp.prod(j,i));
    }
    print(dp.get(n));

    return 0;
}
