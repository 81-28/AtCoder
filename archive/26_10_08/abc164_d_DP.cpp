// https://atcoder.jp/contests/abc164/tasks/abc164_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int n=s.size();
    vi dp(2019,0);
    int ans=0;
    rep(i,n) {
        int d=s[i]-'0';
        ++dp[0];
        vi dpn(2019,0);
        rep(j,2019) {
            int k=(j*10+d)%2019;
            dpn[k]+=dp[j];
        }
        dp=dpn;
        ans+=dp[0];
    }
    print(ans);

    return 0;
}
