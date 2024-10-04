// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bh

#include <bits/stdc++.h>
using namespace std;

#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
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

    int n;
    cin >> n;
    stack<pii> s;
    pii p;
    rep1(i,n) {
        cin >> p.first;
        while(!s.empty() && s.top().first < p.first) s.pop();
        if (s.empty()) print(-1);
        else print(s.top().second);
        p.second = i;
        s.push(p);
    }

    return 0;
}
