// https://atcoder.jp/contests/abc344/tasks/abc344_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string t;
    int n;
    cin >> t >> n;
    int m=t.size();
    // dp[i]:tのi文字目までを作る最小の金額
    vi dp(m+1,n+1);
    dp[0]=0;
    int q=n;
    while (q--) {
        // 同じ袋で更新の連鎖をしてはいけない
        vi dpp=dp;
        int a;
        cin >> a;
        while (a--) {
            string s;
            cin >> s;
            int l=s.size();
            for (int i=0; i+l<=m; ++i) {
                bool ok=1;
                rep(j,l) {
                    if (s[j]!=t[i+j]) {
                        ok=0;
                        break;
                    }
                }
                if (ok) chmin(dp[i+l],dpp[i]+1);
            }
        }
    }
    print(dp[m]>n?-1:dp[m]);

    return 0;
}
