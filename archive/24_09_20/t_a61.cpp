// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bi

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
#define pb(a) push_back(a)
#define all(v) v.begin(), v.end()
template<typename T>
using v = vector<T>;
using vi = v<int>;
using vvi = v<vi>;

#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)


int main() {
    fastio();

    int n,m;
    cin >> n >> m;
    vvi g(n+1);
    int a,b;
    rep(i,m) {
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    rep1(k,n) {
        sort(all(g[k]));
        cout << k << ": {";
        rep(i,g[k].size()) {
            if (i!=0) cout << ", ";
            cout << g[k][i];
        }
        cout << "}" << endl;
    }

    return 0;
}
