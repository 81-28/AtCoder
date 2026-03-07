// https://atcoder.jp/contests/abc266/tasks/abc266_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

template<typename T>
T max(const v<T>& v){return *max_element(v.begin(),v.end());}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    int t;
    map<int,pii> mp;
    rep1(i,n) cin >> t >> mp[t];
    // dp[i]:位置iにいる時の最大スコア
    vi dp(5,-INF);
    dp[0]=0;
    rep1(i,t) {
        vi dpn(5,0);
        dpn[0]=max(dp[0],dp[1]);
        rep1(i,3) dpn[i]=max({dp[i-1],dp[i],dp[i+1]});
        dpn[4]=max(dp[3],dp[4]);
        dp=dpn;
        auto it=mp.find(i);
        if (it!=mp.end()) {
            auto[x,a]=it->second;
            dp[x]+=a;
        }
    }
    print(max(dp));

    return 0;
}
