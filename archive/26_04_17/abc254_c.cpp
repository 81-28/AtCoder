// https://atcoder.jp/contests/abc254/tasks/abc254_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    vi a(n);
    cin >> a;
    vvi b(k);
    rep(i,n) b[i%k].pb(a[i]);
    rep(i,k) sort(all(b[i]));
    vi c;
    rep(i,n) c.pb(b[i%k][i/k]);
    sort(all(a));
    rep(i,n) {
        if (a[i]!=c[i]) {
            YesNo(0);
            return 0;
        }
    }
    YesNo(1);

    return 0;
}
