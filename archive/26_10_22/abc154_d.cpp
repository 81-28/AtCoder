// https://atcoder.jp/contests/abc154/tasks/abc154_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n,k;
    cin >> n >> k;
    vi p(n);
    cin >> p;
    int ans=0,sm=0;
    rep(i,k-1) sm+=p[i]+1;
    rep(i,n+1-k) {
        sm+=p[k-1+i]+1;
        chmax(ans,sm);
        sm-=p[i]+1;
    }
    print(ans/2.0);

    return 0;
}
