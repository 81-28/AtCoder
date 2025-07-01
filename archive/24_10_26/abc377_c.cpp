// https://atcoder.jp/contests/abc377/tasks/abc377_c

#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i=0; i<(int)(n); i++)
using ll = long long;
using pii = pair<int,int>;

#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
void print() { cout << '\n'; }
template<typename T>
void print(const T &t) { cout << t << '\n'; }
template<typename Head, typename... Tail>
void print(const Head &head, const Tail &... tail) {
    cout << head << ' ';
    print(tail...);
}


int main() {
    fastio();

    ll n,m;
    cin >> n >> m;
    set<pii> s;
    int a,b;
    int i,j;
    rep(k,m) {
        cin >> a >> b;
        i = a; j=b;
        if (1 <= i && i <= n && 1 <= j && j <= n) {
            s.insert({i,j});
        }
        i = a+2; j=b+1;
        if (1 <= i && i <= n && 1 <= j && j <= n) {
            s.insert({i,j});
        }
        i = a+1; j=b+2;
        if (1 <= i && i <= n && 1 <= j && j <= n) {
            s.insert({i,j});
        }
        i = a-1; j=b+2;
        if (1 <= i && i <= n && 1 <= j && j <= n) {
            s.insert({i,j});
        }
        i = a-2; j=b+1;
        if (1 <= i && i <= n && 1 <= j && j <= n) {
            s.insert({i,j});
        }
        i = a-2; j=b-1;
        if (1 <= i && i <= n && 1 <= j && j <= n) {
            s.insert({i,j});
        }
        i = a-1; j=b-2;
        if (1 <= i && i <= n && 1 <= j && j <= n) {
            s.insert({i,j});
        }
        i = a+1; j=b-2;
        if (1 <= i && i <= n && 1 <= j && j <= n) {
            s.insert({i,j});
        }
        i = a+2; j=b-1;
        if (1 <= i && i <= n && 1 <= j && j <= n) {
            s.insert({i,j});
        }
    }
    print(n*n-s.size());

    return 0;
}
