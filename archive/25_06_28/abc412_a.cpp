// https://atcoder.jp/contests/abc412/tasks/abc412_a

#include<bits/stdc++.h>
using namespace std;

using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
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
    int cnt=0;
    rep(i,n) {
        pii p;
        cin >> p;
        if (p.f<p.s) ++cnt;
    }
    print(cnt);

    return 0;
}
