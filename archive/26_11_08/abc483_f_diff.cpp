// https://atcoder.jp/contests/abc483/tasks/abc483_f

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    int sm=0;
    v<pii> p(n);
    for (auto&[a,b]:p) {
        cin >> a >> b;
        sm+=a;
    }
    sort(all(p));

    // (x+a)%b = x+a - b*((x+a)/b)
    // 答え: n*x+sm - 剰余による減算分

    const int mx=5e5;
    // sub[x]:x+aから引く値の合計
    vi sub(mx+1,0);
    rep(i,n) {
        auto[a,b]=p[i];
        int j=i+1;
        // 同じペアの個数をカウント
        while (j<n && p[i]==p[j]) ++j;
        // x+aがbの倍数に達するたび、引く値がb増加
        // x=b-a, 2b-a, ... に増加分を記録
        // 同じ組が(j-i)個あるので、その個数倍を加算
        for (int x=b-a; x<=mx; x+=b) {
            sub[x]+=b*(j-i);
        }
        i=j-1;
    }
    // 累積和で、各xにおいて引く値の合計を求める
    rep(i,mx) sub[i+1]+=sub[i];

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        print(n*x+sm-sub[x]);
    }

    return 0;
}
