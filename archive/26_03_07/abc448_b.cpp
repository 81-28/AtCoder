// https://atcoder.jp/contests/abc448/tasks/abc448_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vi c(m);
    cin >> c;
    v<pii> p(n);
    vi s(m,0);
    for (auto&[a,b]:p) {
        cin >> a >> b;
        s[--a]+=b;
    }
    int ans=0;
    rep(i,m) ans+=min(s[i],c[i]);
    print(ans);

    return 0;
}
