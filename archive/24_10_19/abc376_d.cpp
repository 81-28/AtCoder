// https://atcoder.jp/contests/abc376/tasks/abc376_d

#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i=0; i<(int)(n); i++)
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
    rep(i,m) {
        cin >> a >> b;
        g[a].pb(b);
    }
    queue<int> q;
    q.push(1);
    vi d(n+1,-1);
    d[1] = 0;
    vi nexG;
    while(!q.empty()) {
        int pos = q.front();
        q.pop();
        nexG = g[pos];
        for(int val : nexG) {
            if (val == 1) {
                print(d[pos]+1);
                return 0;
            }
            if (d[val] == -1) {
                d[val] = d[pos]+1;
                q.push(val);
            }
        }
    }
    print(-1);

    return 0;
}
