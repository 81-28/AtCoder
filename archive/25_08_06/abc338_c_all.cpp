// https://atcoder.jp/contests/abc338/tasks/abc338_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi q(n),a(n),b(n);
    cin >> q >> a >> b;
    int mxa=INT_MAX;
    rep(k,n) {
        if (a[k]!=0) chmin(mxa,q[k]/a[k]);
    }
    int ans=0;
    for (int i=0; i<=mxa; ++i) {
        int j=INT_MAX;
        rep(k,n) {
            int dif=q[k]-a[k]*i;
            if (b[k]!=0) chmin(j,dif/b[k]);
        }
        chmax(ans,i+j);
    }
    print(ans);

    return 0;
}
