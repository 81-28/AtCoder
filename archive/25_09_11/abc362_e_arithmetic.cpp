// https://atcoder.jp/contests/abc362/tasks/abc362_e

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
using mint=modint998244353;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    // dp[i][j][k]:iで終わり、長さが(j>=2)で、交差kの等差数列である部分列の個数
    v<v<map<int,mint>>> dp(n,v<map<int,mint>>(n+1));
    v<mint> ans(n+1,0);
    ans[1]=n;
    for (int i=1; i<n; ++i) {
        map<pii,bool> mp;
        for (int j=0; j<i; ++j) {
            int d=a[i]-a[j];
            ++dp[i][2][d];
            mp[{2,d}]=1;
            for (int k=3; k<=n; ++k) {
                dp[i][k][d]+=dp[j][k-1][d];
                mp[{k,d}]=1;
            }
        }
        for (auto[p,b]:mp) {
            auto[k,d]=p;
            ans[k]+=dp[i][k][d];
        }
    }
    rep1(i,n) cout<<ans[i].val()<<' ';
    cout<<endl;

    return 0;
}
