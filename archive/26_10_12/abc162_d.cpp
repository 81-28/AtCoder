// https://atcoder.jp/contests/abc162/tasks/abc162_d

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

    int n;
    string s;
    cin >> n >> s;
    int r=0,g=0,b=0;
    rep(i,n) {
        if (s[i]=='R') ++r;
        if (s[i]=='G') ++g;
        if (s[i]=='B') ++b;
    }
    int ans=r*g*b;
    rep(i,n)for(int j=i+1; j<n; ++j) {
        int k=j*2-i;
        if (k>=n) break;
        if (s[i]==s[j]) continue;
        if (s[j]==s[k]) continue;
        if (s[k]==s[i]) continue;
        --ans;
    }
    print(ans);

    return 0;
}
