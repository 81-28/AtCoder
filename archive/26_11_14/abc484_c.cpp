// https://atcoder.jp/contests/abc484/tasks/abc484_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vb=v<bool>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n),b(n);
    cin >> a >> b;
    vb e(n,0);
    rep(i,n) e[i]=a[i]==b[i];
    vb l(n,0),r(n,0);
    rep(i,n-1) {
        l[i+1]=a[i+1]==b[i];
        r[i]=a[i]==b[i+1];
    }
    int h=n,t=0;
    rep(i,n) {
        if (e[i]) continue;
        h=i;
        break;
    }
    for (int i=n; i; --i) {
        if (e[i-1]) continue;
        t=i;
        break;
    }
    if (t<h) {
        YesNo(1);
        return 0;
    }
    if (a[h]==b[t-1]) {
        bool ok=1;
        for (int i=h+1; i<t; ++i) {
            if (l[i]) continue;
            ok=0;
            break;
        }
        if (ok) {
            YesNo(1);
            return 0;
        }
    }
    if (a[t-1]==b[h]) {
        bool ok=1;
        for (int i=h; i<t-1; ++i) {
            if (r[i]) continue;
            ok=0;
            break;
        }
        if (ok) {
            YesNo(1);
            return 0;
        }
    }
    YesNo(0);

    return 0;
}
