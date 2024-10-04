// https://atcoder.jp/contests/tessoku-book/tasks/math_and_algorithm_an

#include <bits/stdc++.h>
using namespace std;

#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
#define pb(a) push_back(a)
template<typename T>
using v = vector<T>;
using vi = v<int>;
using vvi = v<vi>;

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

    int n,m;
    cin >> n >> m;
    vvi g(n+1);
    int a,b;
    rep1(i,m) {
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    queue<int> q;
    q.push(1);
    vi d(n+1,-1);
    d[1] = 0;
    while(!q.empty()) {
        int pos = q.front();
        q.pop();
        vi nexG = g[pos];
        for (int i = 0; i < nexG.size(); i++) {
            if (d[nexG[i]] == -1) {
                d[nexG[i]] = d[pos]+1;
                q.push(nexG[i]);
            }
        }
    }
    rep1(k,n) print(d[k]);

    return 0;
}
