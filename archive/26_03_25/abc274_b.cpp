// https://atcoder.jp/contests/abc274/tasks/abc274_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w;
    cin >> h >> w;
    v<string> s(h);
    cin >> s;
    rep(j,w) {
        int sm=0;
        rep(i,h) sm+=s[i][j]=='#';
        cout<<sm<<' ';
    }
    cout<<endl;

    return 0;
}
