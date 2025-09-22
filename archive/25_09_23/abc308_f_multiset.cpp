// https://atcoder.jp/contests/abc308/tasks/abc308_f

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rall(v) v.rbegin(),v.rend()

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    multiset<int> s;
    int ans=0;
    rep(i,n) {
        int p;
        cin >> p;
        ans+=p;
        s.insert(p);
    }
    v<pii> p(m);
    for (auto&[d,l]:p) cin >> l;
    for (auto&[d,l]:p) cin >> d;
    sort(rall(p));
    for (auto[d,l]:p) {
        auto it=s.lower_bound(l);
        if (it!=s.end()) {
            ans-=d;
            s.erase(it);
        }
    }
    print(ans);

    return 0;
}
