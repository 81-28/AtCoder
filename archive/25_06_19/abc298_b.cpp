// https://atcoder.jp/contests/abc298/tasks/abc298_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define YesNo(x) puts(x?"Yes":"No")

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vvi a(n,vi(n)),b=a;
    cin >> a >> b;
    v<bool> g(4,1);
    rep(i,n)rep(j,n) {
        if (a[i][j]>b[i][j]) g[0]=0;
        if (a[i][j]>b[n-1-j][i]) g[1]=0;
        if (a[i][j]>b[n-1-i][n-1-j]) g[2]=0;
        if (a[i][j]>b[j][n-1-i]) g[3]=0;
    }
    YesNo(g[0]||g[1]||g[2]||g[3]);

    return 0;
}
