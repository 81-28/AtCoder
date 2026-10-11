// https://atcoder.jp/contests/abc479/tasks/abc479_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,w;
    cin >> n >> w;
    v<pii> p(n);
    for (auto&[a,b]:p) cin >> a >> b;
    int mx=1LL<<n,ans=0;
    rep(i,mx) {
        int res=0,sm=0;
        rep(j,n) {
            if ((i>>j)&1) continue;
            auto[a,b]=p[j];
            res+=a,sm+=b;
        }
        if (sm>w) continue;
        chmax(ans,res);
    }
    print(ans);

    return 0;
}
