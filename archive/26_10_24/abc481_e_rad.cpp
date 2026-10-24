// https://atcoder.jp/contests/abc481/tasks/abc481_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

#define f first
#define s second

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


// 偏角が [0,PI) にあるか
bool up(const pii& p) {
    return p.s>0 || (p.s==0 && p.f>=0);
}
// 外積
int cross(const pii& a,const pii& b) {
    return a.f*b.s - a.s*b.f;
}
// 偏角ソート
bool comp(const pii& a,const pii& b) {
    bool ua=up(a),ub=up(b);
    if (ua!=ub) return ua>ub;
    return cross(a,b)>0;
}

void solve() {
    int n;
    cin >> n;
    v<pii> p(n);
    for (auto&[x,y]:p) cin >> x >> y;
    sort(all(p),comp);
    int ans=0,r=0;
    // PIを超える最小のrを尺取り
    rep(l,n) {
        p.pb({p[l]});
        if (r<l) r=l;
        while (r<l+n) {
            if (r==l || cross(p[l],p[r])>0) ++r;
            else break;
        }
        chmax(ans,r-l);
    }
    print(ans);
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
