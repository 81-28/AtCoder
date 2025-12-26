// https://atcoder.jp/contests/joigsp2025/tasks/joigsp2025_e

#include<bits/stdc++.h>
using namespace std;

constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    string s;
    cin >> n >> q >> s;
    set<int> b,r;
    rep(i,n) {
        if (s[i]=='b') b.insert(i);
        else r.insert(i);
    }
    // 全部同じ色の場合
    if (b.size()==0 || r.size()==0) {
        while (q--) {
            int x,y;
            cin >> x >> y;
            print(1);
        }
        return 0;
    }
    int mxb=*b.rbegin(),mib=*b.begin();
    b.insert(mxb-n),b.insert(mib+n);
    int mxr=*r.rbegin(),mir=*r.begin();
    r.insert(mxr-n),r.insert(mir+n);
    // 魔法陣iからb,rそれぞれに一番近い距離
    vvi d(n,vi(2,INF));
    rep(i,n) {
        auto itb=b.lower_bound(i);
        chmin(d[i][0],*itb-i);
        itb=b.upper_bound(i);
        --itb;
        chmin(d[i][0],i-*itb);
        auto itr=r.lower_bound(i);
        chmin(d[i][1],*itr-i);
        itr=r.upper_bound(i);
        --itr;
        chmin(d[i][1],i-*itr);
    }
    while (q--) {
        int x,y;
        cin >> x >> y;
        --x,--y;
        // 徒歩
        int ans=min(abs(y-x),n-abs(y-x));
        // b経由
        chmin(ans,d[x][0]+1+d[y][0]);
        // r経由
        chmin(ans,d[x][1]+1+d[y][1]);
        // b->r経由
        chmin(ans,d[x][0]+3+d[y][1]);
        // r->b経由
        chmin(ans,d[x][1]+3+d[y][0]);
        // 複数色ある場合、必ず境目があるので、異色経由は+3
        print(ans);
    }

    return 0;
}
