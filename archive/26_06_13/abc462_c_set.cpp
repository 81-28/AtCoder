// https://atcoder.jp/contests/abc462/tasks/abc462_c

#include<bits/stdc++.h>
using namespace std;

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

    int n;
    cin >> n;
    v<pii> p(n);
    rep(i,n) cin >> p[i];
    sort(all(p));
    int ans=0;
    set<int> s;
    for (auto[a,b]:p) {
        auto it=s.lower_bound(b);
        if (it==s.begin()) ++ans;
        s.insert(b);
    }
    print(ans);

    return 0;
}
