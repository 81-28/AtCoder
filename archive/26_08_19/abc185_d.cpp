// https://atcoder.jp/contests/abc185/tasks/abc185_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vi a(m);
    cin >> a;
    a.pb(0),a.pb(n+1);
    sort(all(a));
    m+=2;
    int k=n+1;
    rep(i,m-1) {
        int d=a[i+1]-a[i]-1;
        if (d==0) continue;
        chmin(k,d);
    }
    if (k==n+1) {
        print(0);
        return 0;
    }
    int ans=0;
    rep(i,m-1) {
        int d=a[i+1]-a[i]-1;
        ans+=(d+k-1)/k;
    }
    print(ans);

    return 0;
}
