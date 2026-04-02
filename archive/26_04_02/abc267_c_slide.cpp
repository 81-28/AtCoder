// https://atcoder.jp/contests/abc267/tasks/abc267_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vi a(n);
    cin >> a;
    int ans=-INF;
    vi s(n+1,0);
    rep1(i,n) s[i]=s[i-1]+a[i-1];
    int sm=0;
    rep(i,m) sm+=(i+1)*a[i];
    chmax(ans,sm);
    for (int i=m; i<n; ++i) {
        sm-=s[i]-s[i-m];
        sm+=m*a[i];
        chmax(ans,sm);
    }
    print(ans);

    return 0;
}
