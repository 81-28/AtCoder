// https://atcoder.jp/contests/abc286/tasks/abc286_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
constexpr int INF=numeric_limits<int>::max()/4;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,a,b;
    string s;
    cin >> n >> a >> b >> s;
    int ans=INF;
    rep(i,n) {
        int res=a*i;
        int l=i,r=i+n-1;
        while (l<r) {
            if (s[l++%n]!=s[r--%n]) res+=b;
        }
        chmin(ans,res);
    }
    print(ans);

    return 0;
}
