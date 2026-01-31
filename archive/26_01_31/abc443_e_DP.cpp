// https://atcoder.jp/contests/abc443/tasks/abc443_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vb=v<bool>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n,c;
        cin >> n >> c;
        v<string> s(n);
        cin >> s;
        // dp[i]:i列目に到達できるかどうか
        vb dp(n,0);
        dp[--c]=1;
        // sm[j]:今まで通過した、j列目の壁の数
        vi sm(n,0);
        rep(j,n) sm[j]+=(s[n-1][j]=='#');
        // 壊してしまって、別ルートに影響しないか？
        // 壊せる場合は、最後まで掘れるので、大丈夫
        for (int i=n-2; i>=0; --i) {
            vb dpn(n,0);
            rep(j,n) {
                bool ok=0;
                if (j&&dp[j-1]) ok=1;
                if (dp[j]) ok=1;
                if (j+1<n&&dp[j+1]) ok=1;
                if (!ok) continue;
                if (s[i][j]=='.') {
                    dpn[j]=1;
                    continue;
                }
                if (sm[j]==0) {
                    dpn[j]=1;
                    s[i][j]='.';
                }
            }
            dp=dpn;
            rep(j,n) sm[j]+=(s[i][j]=='#');
        }
        rep(i,n) cout<<dp[i];
        cout<<endl;
    }

    return 0;
}
