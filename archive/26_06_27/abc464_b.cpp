// https://atcoder.jp/contests/abc464/tasks/abc464_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int h,w;
    cin >> h >> w;
    v<string> s(h);
    cin >> s;
    vi r(h,0),c(w,0);
    rep(i,h)rep(j,w) {
        if (s[i][j]=='.') continue;
        ++r[i],++c[j];
    }
    int u=-1,d=-1,x=-1,y=-1;
    rep(i,h) {
        if (!r[i]) continue;
        if (u==-1) u=i;
        d=i;
    }
    rep(i,w) {
        if (!c[i]) continue;
        if (x==-1) x=i;
        y=i;
    }
    for (int i=u; i<=d; ++i) {
        for (int j=x; j<=y; ++j) cout<<s[i][j];
        cout<<endl;
    }

    return 0;
}
