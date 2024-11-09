// https://atcoder.jp/contests/abc379/tasks/abc379_e
#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost::multiprecision;
#define rep1(i, n) for (int i = 1; i < (int)(n + 1); i++)
using vll = vector<cpp_int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    vll ele(n);
    ele[0] = 1;
    rep1(i,n-1) ele[i] = ele[i-1]*10+1;

    cpp_int ans = 0;
    cpp_int d;
    for (int i=1; i<=n; i++) {
        d = cpp_int(s[i-1]-'0');
        ans += i*d*ele[n-i];
    }
    cout << ans << '\n';

    return 0;
}
