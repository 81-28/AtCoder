// https://atcoder.jp/contests/abc419/tasks/abc419_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,l;
    cin >> n >> m >> l;
    vi a(n);
    cin >> a;
    // dp[i][j]:iまでで、(mの剰余がjとなり、l以降でも成立する)ための最小操作数
    vvi dp(l,vi(m,INT_MAX));
    rep(i,l) {
        rep(j,m) {
            // lの剰余がiとなる要素全てが、mの剰余がjとなるのに必要なコスト
            int ad=0;
            for (int k=i; k<n; k+=l) ad+=(m+j-a[k])%m;
            // i-1までの剰余がkとなり、iの要素の剰余がjとなると、iまでの剰余は(j+k)%mとなる
            if (i) {
                rep(k,m) chmin(dp[i][(j+k)%m],dp[i-1][k]+ad);
            } else chmin(dp[i][j],ad);
        }
    }
    print(dp[l-1][0]);

    // 短縮版
    // vi dp(m,INT_MAX/2);
    // dp[0]=0;
    // rep(i,l) {
    //     vi d(m,INT_MAX/2);
    //     rep(j,m) {
    //         int ad=0;
    //         for (int k=i; k<n; k+=l) ad+=(m+j-a[k])%m;
    //         rep(k,m) chmin(d[(j+k)%m],dp[k]+ad);
    //     }
    //     dp=d;
    // }
    // print(dp[0]);

    return 0;
}
