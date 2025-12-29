// https://atcoder.jp/contests/abc286/tasks/abc286_a

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,p,q,r,s;
    cin >> n >> p >> q >> r >> s;
    --p,--r;
    vi a(n);
    cin >> a;
    vi b;
    rep(i,n) {
        if (p<=i && i<q) b.pb(a[i-p+r]);
        else if (r<=i && i < s) b.pb(a[i-r+p]);
        else b.pb(a[i]);
    }
    print(b);

    return 0;
}
