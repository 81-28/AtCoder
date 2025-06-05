// https://atcoder.jp/contests/abc317/tasks/abc317_d

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
using pii=pair<int,int>;

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    int z;
    pii p;
    int all=0;
    int t=0;
    // {議席数,鞍替え数}
    v<pii> a;
    rep(i,n) {
        cin >> p >> z;
        all+=z;
        if (p.f>p.s) {
            t+=z;
        } else {
            a.pb({z,(p.s+p.f+1)/2-p.f});
        }
    }
    int need=(all+1)/2-t;
    if (need<1) {
        print(0);
        return 0;
    }
    n=a.size();
    // dp[j]:i+1個目までのいくつかの区を選んで、j以上議席を獲得できる最小コスト
    vll dp(need+1,LLONG_MAX/2);
    rep(i,n)for(int j=need; j>0; --j) {
        dp[0]=0;
        if (j<need) chmin(dp[j],min(dp[j+1],dp[max(0,j-a[i].f)]+a[i].s));
        else chmin(dp[j],dp[max(0,j-a[i].f)]+a[i].s);
    }
    print(dp[need]);

    return 0;
}
