// https://atcoder.jp/contests/abc443/tasks/abc443_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,t;
    cin >> n >> t;
    vi a(n);
    cin >> a;
    a.pb(t);
    int now=0,ans=0;
    rep(i,n+1) {
        ans+=a[i]-now;
        now=min(a[i]+100,t);
        if (now==t) break;
        while (i+1<n && a[i+1]<now) ++i;
    }
    print(ans);

    return 0;
}
