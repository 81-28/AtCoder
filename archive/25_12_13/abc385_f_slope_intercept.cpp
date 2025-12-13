// https://atcoder.jp/contests/abc385/tasks/abc385_f

#include<bits/stdc++.h>
using namespace std;

using ld=long double;
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi x(n),h(n);
    ld ans=-LDBL_MAX;
    rep(i,n) cin >> x[i] >> h[i];
    rep(i,n-1) {
        ld a=(ld)(h[i+1]-h[i])/(x[i+1]-x[i]);
        ld res=h[i]+a*(-x[i]);
        chmax(ans,res);
    }
    if (ans<0) {
        print(-1);
    } else {
        cout<<fixed<<setprecision(16);
        print(ans);
    }

    return 0;
}
