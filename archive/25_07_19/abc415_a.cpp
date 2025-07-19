// https://atcoder.jp/contests/abc415/tasks/abc415_a

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define YesNo(x) puts(x?"Yes":"No")

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    int x;
    cin >> a >> x;
    rep(i,n) {
        if (a[i]==x) {
            YesNo(1);
            return 0;
        }
    }
    YesNo(0);

    return 0;
}
