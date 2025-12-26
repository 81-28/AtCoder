// https://atcoder.jp/contests/joigsp2024/tasks/joigsp2024_a

#include<bits/stdc++.h>
using namespace std;

constexpr int INF=numeric_limits<int>::max()/2;
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define all(v) v.begin(),v.end()
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi x(n);
    cin >> x;
    sort(all(x));
    // 4匹以上の集合は、2,3匹に分割できる
    // dp[i]:i匹目までの最小コスト
    vi dp(n,INF);
    dp[1]=x[1]-x[0];
    dp[2]=x[2]-x[0];
    for (int i=3; i<n; ++i) {
        chmin(dp[i],dp[i-2]+x[i]-x[i-1]);
        chmin(dp[i],dp[i-3]+x[i]-x[i-2]);
    }
    print(dp[n-1]);

    return 0;
}
