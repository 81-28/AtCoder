// https://atcoder.jp/contests/abc278/tasks/abc278_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int H,W,n,h,w;
    cin >> H >> W >> n >> h >> w;
    vvi a(H,vi(W));
    cin >> a;
    map<int,int> m;
    rep(i,H)rep(j,W) ++m[a[i][j]];
    rep(i,H-h+1) {
        auto mp=m;
        rep(x,h)rep(y,w-1) {
            --mp[a[i+x][y]];
            if (!mp[a[i+x][y]]) mp.erase(mp.find(a[i+x][y]));
        }
        rep(j,W-w+1) {
            rep(x,h) {
                --mp[a[i+x][w-1+j]];
                if (!mp[a[i+x][w-1+j]]) mp.erase(mp.find(a[i+x][w-1+j]));
            }
            cout<<mp.size()<<' ';
            rep(x,h) ++mp[a[i+x][j]];
        }
        cout<<endl;
    }

    return 0;
}
