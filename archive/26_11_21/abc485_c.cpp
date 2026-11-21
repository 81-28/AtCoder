// https://atcoder.jp/contests/abc485/tasks/abc485_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define substring(s,l,r) s.substr(l,r-l)
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi c(n),ans(n);
    cin >> c;
    rep(l,n) {
        int r=l;
        while (r<n && c[r]==c[l]) ++r;
        // [l,r) 同じ色が連続する区間
        for (int i=l; i<r; ++i) {
            int d=n;
            if (l>0) chmin(d,i-l+1);
            if (r<n) chmin(d,r-i);
            ans[i]=d;
        }
        l=r-1;
    }
    print(ans);

    return 0;
}
