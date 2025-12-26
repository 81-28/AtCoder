// https://atcoder.jp/contests/joi2011ho/tasks/joi2011ho2

#include<bits/stdc++.h>
using namespace std;

constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back
#define rall(v) v.rbegin(),v.rend()
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    vvi c(10);
    rep(i,n) {
        int p,g;
        cin >> p >> g;
        c[--g].pb(p);
    }
    // c[i[j]:ジャンルiの本のj+1冊目までを売った時の値段
    rep(i,10) {
        sort(rall(c[i]));
        int l=c[i].size();
        rep1(j,l-1) c[i][j]+=c[i][j-1]+j*2;
    }
    // dp[i][j]:iジャンルまでで、合計j冊売った場合の最大値
    vvi dp(10,vi(k+1,-INF));
    dp[0][0]=0;
    rep1(j,min((int)c[0].size(),k)) dp[0][j]=c[0][j-1];
    rep1(i,9) {
        dp[i]=dp[i-1];
        // ジャンルiをl冊売る
        rep1(j,k)rep1(l,c[i].size()) {
            if (j-l<0) break;
            chmax(dp[i][j],dp[i-1][j-l]+c[i][l-1]);
        }
    }
    print(dp[9][k]);

    return 0;
}
