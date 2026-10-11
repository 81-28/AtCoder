// https://atcoder.jp/contests/abc479/tasks/abc479_d

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
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


using S=int;
S op(S a,S b){return min(a,b);}
S e(){return INF;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    vi l(n,INF),r(n,INF);
    rep(i,n-1) cin >> l[i+1];
    rep(i,n-1) cin >> r[i];
    segtree<S,op,e> tl(l),tr(r);
    while (q--) {
        int s,t;
        cin >> s >> t;
        --s,--t;
        // 直接or折り返し
        int ans=INF;
        if (s<t) {
            chmin(ans,r[s]);
            chmin(ans,l[s]+tr.prod(0,s));
        } else {
            chmin(ans,l[s]);
            chmin(ans,r[s]+tl.prod(s+1,n));
        }
        print(ans);
    }

    return 0;
}
