// https://atcoder.jp/contests/abc300/tasks/abc300_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}


int h,w;
v<v<bool>> c;
bool get(const int& i,const int& j) {
    if (0<=i && i<h && 0<=j && j<w) return c[i][j];
    return 0;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    
    cin >> h >> w;
    v<string> s(h);
    cin >> s;
    c=v<v<bool>>(h,v<bool>(w,0));
    rep(i,h)rep(j,w) {
        if (s[i][j]=='#') c[i][j]=1;
    }
    int n=min(h,w);
    vi ans(n+1,0);
    for(int i=1; i+1<h; ++i)for(int j=1; j+1<w; ++j) {
        rep(d,n) {
            bool ok=1;
            if (!get(i+d,j+d)) ok=0;
            if (!get(i+d,j-d)) ok=0;
            if (!get(i-d,j+d)) ok=0;
            if (!get(i-d,j-d)) ok=0;
            if (!ok) {
                if (d) ++ans[d-1];
                break;
            }
        }
    }
    rep1(i,n) cout<<ans[i]<<' ';
    cout<<endl;

    return 0;
}
