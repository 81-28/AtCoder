// https://atcoder.jp/contests/abc481/tasks/abc481_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()
using pii=pair<int,int>;
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


bool up(const pii& p) {return p.second>0 || (p.second==0 && p.first>0);}
int cross(const pii& a,const pii& b) {return a.first*b.second-a.second*b.first;}
bool comp(const pii& a,const pii& b) {return (up(a)!=up(b)) ? up(a)>up(b) : cross(a,b)>0;}

void solve() {
    int n;
    cin >> n;
    v<pii> p(n);
    for (auto&[x,y]:p) cin >> x >> y;
    sort(all(p),comp);

    int ans=0;
    rep(i,n) {
        auto[x,y]=p[i];
        int j=lower_bound(all(p),pii(-x,-y),comp)-p.begin();
        chmax(ans,j-i+(up(p[i])?0:n));
    }
    print(ans);
}

signed main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
