// https://atcoder.jp/contests/abc485/tasks/abc485_f

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rall(v) v.rbegin(),v.rend()
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

#define f first
#define s second

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    v<pii> p(n);
    int sm=0;
    for (auto&[c,v]:p) {
        cin >> c >> v;
        sm+=v;
    }
    sort(rall(p));

    // dp[j][k]:
    // 高い方から処理済みの商品のうちj個を選び、k円以下の最大価値
    vvi dp(1,vi(m+1,0));
    vi ans(m+1,sm);
    rep(i,n) {
        auto[c,v]=p[i];
        // 基準となる橋渡り回数を、前の商品料金からcに変更
        // 既存の商品は、それぞれd円ずつ高くなる
        int d=(i==0 ? 0 : p[i-1].f-c);
        // ndp[j][k]:
        // 高い方からi+1個の商品について、
        // ちょうどj個を選び、料金k以下で得られる最大価値
        vvi ndp(i+2,vi(m+1,-INF));
        rep(j,i+2) {
            rep(k,m+1) {
                // 商品iを選ばない場合
                // 既存のj個の料金がそれぞれd円増える
                if(j<=i && k>=j*d) chmax(ndp[j][k],dp[j][k-j*d]);

                // 商品iを選ぶ場合
                // 既存のj-1個の料金がそれぞれd円増える
                // 新しい商品自体の料金は0円
                if(j>=1 && k>=(j-1)*d) {
                    int x=dp[j-1][k-(j-1)*d];
                    if(x!=-INF) {
                        chmax(ndp[j][k],x+v);
                    }
                }
            }
        }
        dp=move(ndp);
        // 処理済みの商品を無料商品の合計から除外
        sm-=v;

        // 次に処理する商品の料金
        // 未処理の商品は、橋をnc回以上渡れば無料
        int nc=(i+1<n ? p[i+1].f : 0);
        // nc<=t<c の範囲では、
        // 処理済みの商品だけが有料となる
        for(int t=nc;t<c;++t) {
            // DPの基準は橋をc回渡った時点
            // 実際はt回なので、選んだ商品1個につきc-t円高い
            int d=c-t,best=0;
            // 有料の商品からj個選ぶ場合
            rep(j,i+2) {
                if(j*d>m) break;
                // 料金が合計j*d円増えるため、
                // DP上で使用できる予算はm-j*d
                chmax(best,dp[j][m-j*d]);
            }
            // 無料の商品はすべて購入
            ans[t]=sm+best;
        }
    }
    for (int val:ans) print(val);

    return 0;
}
