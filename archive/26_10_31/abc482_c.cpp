// https://atcoder.jp/contests/abc482/tasks/abc482_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w,n,q;
    cin >> h >> w >> n >> q;
    vvi p(2,vi(n));
    rep(i,n) cin >> p[1][i] >> p[0][i];
    rep(i,2) sort(all(p[i]));
    while (q--) {
        int m,x,y;
        cin >> m >> x >> y;
        auto itl=lower_bound(all(p[m&1]),x);
        auto itr=upper_bound(all(p[m&1]),y);
        print(itr-itl);
    }

    return 0;
}
