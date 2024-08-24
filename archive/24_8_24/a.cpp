// https://atcoder.jp/contests/abc368/tasks/abc368_a

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for(T &in : v) is >> in;
    return is;
}


int main() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    cin >> a;
    rep(i,n) {
        if (i < k)
        {
            cout << a[n-k+i] << ' ';
        } else {
            cout << a[i-k] << ' ';
        }
    }
    cout << endl;

    return 0;
}
