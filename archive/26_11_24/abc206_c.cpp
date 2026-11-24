// https://atcoder.jp/contests/abc206/tasks/abc206_c

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
    cin >> n;
    unordered_map<int,int> cnt;
    int ans=0;
    rep(i,n) {
        int a;
        cin >> a;
        ans+=i-cnt[a]++;
    }
    print(ans);

    return 0;
}
