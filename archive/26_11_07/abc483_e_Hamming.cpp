// https://atcoder.jp/contests/abc483/tasks/abc483_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    // 文字列に対するカウント
    unordered_map<string,int> cnt;
    cnt.reserve(n*(1+m+m*(m-1)/2));
    int ans=0;
    while (n--) {
        string s;
        cin >> s;
        string t=s;

        // 完全一致
        int res=cnt[t]++;
        ans+=res*(m-1)*(m-2)/2;

        // 1字違い
        res=0;
        rep(i,m) {
            t[i]='.';
            res+=cnt[t]++;
            t[i]=s[i];
        }
        ans-=res*(m-2);

        // 2字違い
        res=0;
        rep(i,m) {
            t[i]='.';
            for(int j=i+1; j<m; ++j) {
                t[j]='.';
                res+=cnt[t]++;
                t[j]=s[j];
            }
            t[i]=s[i];
        }
        ans+=res;
    }
    print(ans);

    return 0;
}
