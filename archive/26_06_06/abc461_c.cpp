// https://atcoder.jp/contests/abc461/tasks/abc461_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vb=v<bool>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rall(v) v.rbegin(),v.rend()

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k,m;
    cin >> n >> k >> m;
    v<pii> p(n);
    for (auto&[v,c]:p) cin >> c >> v;
    sort(rall(p));
    int ans=0;
    map<int,bool> b;
    vb d(n,0);
    int cnt=0;
    rep(i,m) {
        auto[v,c]=p[i];
        if (b[c]) {
            ++m;
            continue;
        }
        b[c]=1;
        ans+=v;
        d[i]=1;
        ++cnt;
    }
    rep(i,n) {
        if (cnt>=k) break;
        if (d[i]) continue;
        auto[v,c]=p[i];
        ans+=v;
        ++cnt;
    }
    print(ans);

    return 0;
}
