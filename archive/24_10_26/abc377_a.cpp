// https://atcoder.jp/contests/abc377/tasks/abc377_a

#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define YesNo(x) cout<<(x ? "Yes\n":"No\n")
template<typename T>
using v = vector<T>;
using vi = v<int>;

#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fastio();

    string s;
    cin >> s;
    vi a(3,0);
    rep(i,3) {
        a[s[i]-'A']++;
    }
    rep(i,3) {
        if (a[i] != 1) {
            YesNo(0);
            return 0;
        }
    }
    YesNo(1);

    return 0;
}
