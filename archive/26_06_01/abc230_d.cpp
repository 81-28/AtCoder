// https://atcoder.jp/contests/abc230/tasks/abc230_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,d;
    cin >> n >> d;
    v<pii> p(n);
    rep(i,n) cin >> p[i];
    sort(all(p));
    int ans=0,last=INF;
    for (int i=n-1; i>=0; --i) {
        auto[l,r]=p[i];
        if (r+d>last) continue;
        ++ans;
        last=l;
    }
    print(ans);

    return 0;
}
