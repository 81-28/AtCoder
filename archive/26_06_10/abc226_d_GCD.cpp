// https://atcoder.jp/contests/abc226/tasks/abc226_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<pii> p(n);
    for (auto&[x,y]:p) cin >> x >> y;
    set<pii> s;
    rep(i,n-1) {
        auto[a,b]=p[i];
        for(int j=i+1; j<n; ++j) {
            auto[c,d]=p[j];
            int x=c-a,y=d-b;
            if (x==0) {
                s.insert({0,1});
                s.insert({0,-1});
                continue;
            }
            if (y==0) {
                s.insert({1,0});
                s.insert({-1,0});
                continue;
            }
            int g=gcd(abs(x),abs(y));
            s.insert({x/g,y/g});
            s.insert({-x/g,-y/g});
        }
    }
    print(s.size());

    return 0;
}
