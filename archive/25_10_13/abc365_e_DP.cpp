// https://atcoder.jp/contests/abc365/tasks/abc365_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

template<typename T>
T max(const v<T>& v){return *max_element(v.begin(),v.end());}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    int mx=max(a);
    int ans=0;
    for (int i=0; mx; mx>>=1,++i) {
        // dp[i][j]:i番まででjとなるものの個数
        vvi dp(n,vi(2,0));
        ++dp[0][(a[0]>>i)%2];
        int sm=0;
        for (int j=1; j<n; ++j) {
            if ((a[j]>>i)%2) {
                dp[j][0]+=dp[j-1][1];
                dp[j][1]+=dp[j-1][0];
            } else {
                dp[j][0]+=dp[j-1][0];
                dp[j][1]+=dp[j-1][1];
            }
            sm+=dp[j][1];
            // 範囲の長さは2以上なので、次回から影響
            ++dp[j][(a[j]>>i)%2];
        }
        ans+=sm<<i;
    }
    print(ans);

    return 0;
}
