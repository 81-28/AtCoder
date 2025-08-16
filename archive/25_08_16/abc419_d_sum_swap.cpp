// https://atcoder.jp/contests/abc419/tasks/abc419_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
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

    int n,m;
    string st,t;
    cin >> n >> m >> st >> t;
    vi a(n+1,0);
    while (m--) {
        pii p;
        cin >> p;
        ++a[p.f-1];
        --a[p.s];
    }
    for (int i=1; i<n; ++i) a[i]+=a[i-1];
    string ans="";
    rep(i,n) ans+=(a[i]%2)?t[i]:st[i];
    print(ans);

    return 0;
}
