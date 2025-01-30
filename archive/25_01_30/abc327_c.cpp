// https://atcoder.jp/contests/abc327/tasks/abc327_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define YesNo(x) cout<<(x?"Yes\n":"No\n")
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    vvi a(9,vi(9));
    rep(i,9) cin >> a[i];
    set<int> s;
    rep(i,9) {
        s.clear();
        rep(j,9) s.insert(a[i][j]);
        if (s.size() != 9) {
            YesNo(0);
            return 0;
        }
    }
    rep(j,9) {
        s.clear();
        rep(i,9) s.insert(a[i][j]);
        if (s.size() != 9) {
            YesNo(0);
            return 0;
        }
    }
    rep(i,3)rep(j,3) {
        s.clear();
        rep(k,3)rep(l,3) s.insert(a[i*3+k][j*3+l]);
        if (s.size() != 9) {
            YesNo(0);
            return 0;
        }
    }
    YesNo(1);

    return 0;
}
