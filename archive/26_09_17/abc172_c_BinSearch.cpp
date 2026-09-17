// https://atcoder.jp/contests/abc172/tasks/abc172_c

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
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,k;
    cin >> n >> m >> k;
    vi a(n),b(m);
    cin >> a >> b;
    vi aa(n+1,0);
    rep(i,n) aa[i+1]=aa[i]+a[i];
    b.pb(0);
    int sm=0,ans=0;
    rep(i,m+1) {
        if (k<sm) break;
        auto it=upper_bound(all(aa),k-sm);
        int j=it-aa.begin()-1;
        chmax(ans,i+j);
        sm+=b[i];
    }
    print(ans);

    return 0;
}
