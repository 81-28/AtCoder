// https://atcoder.jp/contests/abc322/tasks/abc322_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

int int_pow(int a,int b) {
    int r=1;
    while(b){if(b&1)r*=a;a*=a;b>>=1;}
    return r;
}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


constexpr int inf=LLONG_MAX>>1;

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k,p;
    cin >> n >> k >> p;
    vi c(n);
    vvi a(n,vi(k));
    rep(i,n) cin >> c[i] >> a[i];
    int mx=int_pow(p+1,k);
    // dp[j]:今までのいくつかを選んで、状態jにするのに必要な最小コスト
    // j:p+1進数k桁
    vi dp(mx,inf);
    dp[0]=0;
    rep(i,n) {
        vi dpi=dp;
        rep(j,mx) {
            if (dp[j]==inf) continue;
            int sm=0;
            for (int nj=j,l=0; l<k; nj/=p+1,++l) {
                int d=nj%(p+1);
                sm+=min(p,d+a[i][l])*int_pow(p+1,l);
            }
            chmin(dpi[sm],dp[j]+c[i]);
        }
        dp=dpi;
    }
    print(dp[mx-1]==inf?-1:dp[mx-1]);

    return 0;
}
