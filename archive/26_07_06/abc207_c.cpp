// https://atcoder.jp/contests/abc207/tasks/abc207_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n;
    cin >> n;
    v<pii> p(n);
    // 開区間の共通部分を求める関係上、0.5ズラす
    // [l,r)の形にする
    for (auto&[l,r]:p) {
        int t;
        cin >> t >> l >> r;
        l*=2,r*=2;
        if (t>2) ++l;
        if (t&1) ++r;
    }
    int ans=0;
    rep(i,n-1) {
        auto[li,ri]=p[i];
        for (int j=i+1; j<n; ++j) {
            auto[lj,rj]=p[j];
            ans+=(li<rj && lj<ri);
        }
    }
    print(ans);

    return 0;
}
