// https://atcoder.jp/contests/abc467/tasks/abc467_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

template<typename T>
T min(const v<T>& v){return *min_element(v.begin(),v.end());}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n,m;
    cin >> n >> m;
    vi a(n),b(n-1);
    cin >> a >> b;
    // dp[i][j]:iの位置で偶奇jの時、最小操作数
    vvi dp(n,vi(2));
    dp[0][a[0]]=0;
    dp[0][!a[0]]=1;
    for (int i=1; i<n; ++i) {
        dp[i][0] = dp[i-1][b[i-1]]+a[i];
        dp[i][1] = dp[i-1][!b[i-1]]+!a[i];
    }
    print(min(dp[n-1]));

    return 0;
}
