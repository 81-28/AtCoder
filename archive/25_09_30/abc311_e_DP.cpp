// https://atcoder.jp/contests/abc311/tasks/abc311_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w,n;
    cin >> h >> w >> n;
    v<v<bool>> b(h+1,v<bool>(w+1,0));
    rep1(i,n) {
        int x,y;
        cin >> x >> y;
        b[x][y]=1;
    }
    int ans=0;
    vvi dp(h+1,vi(w+1,0));
    rep1(i,h)rep1(j,w) {
        if (b[i][j]) continue;
        dp[i][j]=min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]})+1;
        ans+=dp[i][j];
    }
    print(ans);

    return 0;
}
