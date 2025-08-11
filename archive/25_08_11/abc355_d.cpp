// https://atcoder.jp/contests/abc355/tasks/abc355_d

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

#define f first
#define s second

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<pii> p(n);
    rep(i,n) cin >> p[i];
    sort(all(p));
    vi st(n);
    rep(i,n) st[i]=p[i].f;
    int ans=0;
    rep(i,n) {
        auto[l,r]=p[i];
        ans+=upper_bound(all(st),r)-st.begin()-i-1;
    }
    print(ans);

    return 0;
}
