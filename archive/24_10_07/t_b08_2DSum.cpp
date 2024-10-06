// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cg

#include <bits/stdc++.h>
using namespace std;

#define rep1(i,n) for (int i=1; i<(int)(n+1); i++)
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

    int n;
    cin >> n;
    vvi p(1501,vi(1501,0));
    int x,y;
    rep1(_,n) {
        cin >> x >> y;
        p[x][y]++;
    }

    rep1(i,1500) rep1(j,1500) {
        p[i][j] += p[i][j-1]+p[i-1][j]-p[i-1][j-1];
    }

    int q,a,b,c,d;
    cin >> q;
    rep1(_,q) {
        cin >> a >> b >> c >> d;
        print(p[c][d]-p[c][b-1]-p[a-1][d]+p[a-1][b-1]);
    }

    return 0;
}
