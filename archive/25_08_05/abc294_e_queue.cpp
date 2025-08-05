// https://atcoder.jp/contests/abc294/tasks/abc294_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int l,n,m;
    cin >> l >> n >> m;
    // {数,個数}
    v<queue<pii>> q(2);
    pii p;
    rep(i,n) {
        cin >> p;
        q[0].push(p);
    }
    rep(i,m) {
        cin >> p;
        q[1].push(p);
    }
    int ans=0;
    while (!q[0].empty()) {
        auto&[a,b]=q[0].front();
        auto&[c,d]=q[1].front();
        if (b==d) {
            if (a==c) ans+=b;
            q[0].pop(),q[1].pop();
        } else if (b>d) {
            if (a==c) ans+=d;
            b-=d;
            q[1].pop();
        } else {
            if (a==c) ans+=b;
            d-=b;
            q[0].pop();
        }
    }
    print(ans);

    return 0;
}
