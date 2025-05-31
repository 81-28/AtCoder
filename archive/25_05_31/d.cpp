// https://atcoder.jp/contests/abc408/tasks/abc408_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
template<class T> constexpr bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
#define f first
#define s second
using ll=long long;
template<typename T>
using v=vector<T>;
using vll=v<ll>;
using pll=pair<ll,ll>;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    rep(k,t) {
        ll n;
        string st;
        cin >> n >> st;
        ll cmb=1;
        ll cnt1=0;
        v<pll> p;
        rep(i,n) {
            if (st[i]-'0') {
                if (i+1==n || !(st[i+1]-'0')) {
                    p.pb({1,cmb});
                    cmb=1;
                } else {
                    ++cmb;
                }
                ++cnt1;
            } else {
                if (i+1==n || (st[i+1]-'0')) {
                    p.pb({0,cmb});
                    cmb=1;
                } else {
                    ++cmb;
                }
            }
        }
        if (cnt1==0) {
            print(0);
            continue;
        }
        ll ans=LLONG_MAX;
        ll nn=p.size();
        vll dp(nn+1,nn);
        dp[0]=0;
        ll th1=0;
        rep(i,nn) {
            if (p[i].f) {
                if (i-2<0) {
                    dp[i]=0;
                } else {
                    dp[i]=min(dp[i-2]+p[i-1].s,th1);
                }
                cnt1-=p[i].s;
                chmin(ans,dp[i]+cnt1);
                th1+=p[i].s;
            }
        }
        print(ans);
    }

    return 0;
}
