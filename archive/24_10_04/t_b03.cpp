// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cb

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
template<typename T>
using v = vector<T>;
using vi = v<int>;

#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for(T &in : v) is >> in;
    return is;
}


int main() {
    fastio();

    int n;
    cin >> n;
    vi a(n);
    cin >> a;

    rep(i,n) {
        rep(j,n) {
            if (i != j) {
                rep(k,n) {
                    if (i != k && j != k && a[i]+a[j]+a[k] == 1000) {
                      YesNo(true);
                      return 0;
                    }
                }
            }
        }
    }
    YesNo(false);

    return 0;
}
