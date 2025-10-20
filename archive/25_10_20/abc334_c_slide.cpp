// https://atcoder.jp/contests/abc334/tasks/abc334_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    vi a(k);
    cin >> a;
    int sm=0;
    rep(i,k-1) {
        if (!(i&1)) sm+=a[i+1]-a[i];
    }
    if (k&1) {
        int res=sm;
        for (int i=k-2; i>0; i-=2) {
            sm+=a[i+1]-a[i];
            sm-=a[i]-a[i-1];
            chmin(res,sm);
        }
        sm=res;
    }
    print(sm);

    return 0;
}
