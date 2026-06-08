// https://atcoder.jp/contests/abc265/tasks/abc265_b

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,t;
    cin >> n >> m >> t;
    vi a(n-1);
    cin >> a;
    vi b(n,0);
    rep(i,m) {
        int x,y;
        cin >> x >> y;
        b[--x]=y;
    }
    rep(i,n-1) {
        t+=b[i];
        t-=a[i];
        if (t<=0) {
            YesNo(0);
            return 0;
        }
    }
    YesNo(1);

    return 0;
}
