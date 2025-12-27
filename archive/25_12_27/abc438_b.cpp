// https://atcoder.jp/contests/abc438/tasks/abc438_b

#include<bits/stdc++.h>
using namespace std;

constexpr int INF=numeric_limits<int>::max()/4;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    string s,t;
    cin >> n >> m >> s >> t;
    int ans=INF;
    rep(i,n-m+1) {
        int res=0;
        rep(j,m) res+=(s[i+j]-t[j]+10)%10;
        chmin(ans,res);
    }
    print(ans);

    return 0;
}
