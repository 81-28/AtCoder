// https://atcoder.jp/contests/abc176/tasks/abc176_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w,m;
    cin >> h >> w >> m;
    vi r(h,0),c(w,0);
    v<pii> p(m);
    int mxr=0,mxc=0;
    for (auto&[x,y]:p) {
        cin >> x >> y;
        chmax(mxr,++r[--x]);
        chmax(mxc,++c[--y]);
    }
    int nr=count(all(r),mxr);
    int nc=count(all(c),mxc);
    int ans=mxr+mxc;
    int sm=nr*nc;
    for (auto[x,y]:p) {
        if (r[x]==mxr&&c[y]==mxc) --sm;
    }
    print(ans-(sm<1));

    return 0;
}
