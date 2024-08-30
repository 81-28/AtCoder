// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_n

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for(T &in : v) is >> in;
    return is;
}


int main() { 
    int n,k;
    cin >> n >> k;
    vector<int> a(n),b(n),c(n),d(n);
    cin >> a >> b >> c >> d;
    vector<int> p(n*n);
    rep(i,n) {
        rep(j,n) {
            p[i*n+j] = a[i]+b[j];
        }
    }
    set<int> abset(all(p));
    rep(i,n) {
        rep(j,n) {
            int nowab = k-c[i]-d[j];
            if (abset.find(nowab) != abset.end()) {
                YesNo(true);
                return 0;
            }
        }
    }
    YesNo(false);
    return 0;
}
