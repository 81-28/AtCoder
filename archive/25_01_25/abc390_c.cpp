// https://atcoder.jp/contests/abc390/tasks/abc390_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define YesNo(x) cout<<(x?"Yes\n":"No\n")
template<typename T>
using v=vector<T>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w;
    cin >> h >> w;
    v<string> s(h);
    cin >> s;
    int maI=0,miI=h-1,maJ=0,miJ=w-1;
    rep(i,h)rep(j,w) {
        if (s[i][j] == '#') {
            maI = max(maI,i);
            miI = min(miI,i);
            maJ = max(maJ,j);
            miJ = min(miJ,j);
        }
    }
    rep(i,h)rep(j,w) {
        if (miI <= i && i <= maI && miJ <= j && j <= maJ && s[i][j] == '.') {
            YesNo(0);
            return 0;
        }
    }
    YesNo(1);

    return 0;
}
