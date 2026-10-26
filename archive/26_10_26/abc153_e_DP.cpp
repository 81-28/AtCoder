// https://atcoder.jp/contests/abc153/tasks/abc153_e

#include<bits/stdc++.h>
using namespace std;

constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,n;
    cin >> h >> n;
    v<pii> p(n);
    for (auto&[a,b]:p) cin >> a >> b;
    // dp[i]:体力iにするのに必要なコスト
    vi dp(h,INF);
    // [h,h+max(a))の範囲は0とみなす
    for (int i=h-1; i>=0; --i) {
        for (auto[a,b]:p) {
            int j=i+a;
            chmin(dp[i],((j<h)?dp[j]:0)+b);
        }
    }
    print(dp[0]);

    return 0;
}
