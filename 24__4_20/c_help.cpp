// https://atcoder.jp/contests/abc350/tasks/abc350_c

// Ctrl + Shift + B       => Build
// Terminal << "./a.out"  => Run

#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
// using mint = modint1000000007;


int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1), l, r;
    int k = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] != i && a[i] != 0) {
            l.push_back(i);
            r.push_back(a[i]);
            swap(a[i], a[a[i]]);
            k++;
            i--;
        }
    }

    cout << k << endl;
    for (int i = 0; i < k; i++) {
        cout << l[i] << ' ' << r[i] << endl;
    }

    return 0;
}