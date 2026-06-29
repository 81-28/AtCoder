// https://atcoder.jp/contests/abc210/tasks/abc210_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int h,w,c;
    cin >> h >> w >> c;
    vvi a(h,vi(w));
    cin >> a;
    int ans=INF;
    // 自分より右下と結ぶ場合
    // j以上かつ今までのiの範囲で、最小
    vi dp(w,INF);
    for (int i=h-1; i>=0; --i) for (int j=w-1; j>=0; --j) {
        int now=a[i][j]+c*(i+j);
        if (j+1<w) chmin(dp[j],dp[j+1]);
        chmin(ans,dp[j]+now-(i+j)*2*c);
        chmin(dp[j],now);
    }
    // 自分より左下と結ぶ場合
    dp=vi(w,INF);
    for (int i=h-1; i>=0; --i)rep(j,w) {
        int now=a[i][j]+c*(i+(w-1-j));
        if (j) chmin(dp[j],dp[j-1]);
        chmin(ans,dp[j]+now-(i+(w-1-j))*2*c);
        chmin(dp[j],now);
    }
    print(ans);

    return 0;
}
