// https://atcoder.jp/contests/joig2024-open/tasks/joig2024_c

#include<bits/stdc++.h>
using namespace std;

constexpr int INF=numeric_limits<int>::max();
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<tuple<int,int,int>> t(n);
    map<int,vi> mp;
    multiset<int> s;
    rep(i,n) {
        auto&[c,x,j]=t[i];
        cin >> c >> x;
        j=i;
        mp[c].pb(x);
        s.insert(x);
    }
    sort(all(t));

    for (int x:mp[get<0>(t[0])]) s.erase(s.find(x));
    vi ans(n,INF);
    rep(i,n) {
        auto[c,x,j]=t[i];
        // 左右で最も近い人を探す
        auto itl=s.lower_bound(x);
        if (itl!=s.end()) chmin(ans[j],*itl-x);
        auto itr=s.upper_bound(x);
        if (itr!=s.begin()) chmin(ans[j],x-*(--itr));
        if (i+1<n) {
            // 国が変わる時だけ更新(変わる回数最小化のために事前ソート)
            auto[cc,a,b]=t[i+1];
            if (c==cc) continue;
            for (int y:mp[c]) s.insert(y);
            for (int y:mp[cc]) s.erase(s.find(y));
        }
    }
    rep(i,n) print(ans[i]);


    return 0;
}
