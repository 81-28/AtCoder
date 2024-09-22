// https://atcoder.jp/contests/abc372/tasks/abc372_d

#include <bits/stdc++.h>
using namespace std;

template<typename T>
using v = vector<T>;
using vi = v<int>;

#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for(T &in : v) is >> in;
    return is;
}
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for(int i = 0; i < (int) v.size(); i++) {
        os << v[i] << (i + 1 != (int) v.size() ? " " : "");
    }
    return os;
}
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
    vi h(n);
    cin >> h;

    vi anss(n,0);
    stack<int> s;
    s.push(h[n-1]);
    for (int i = n-2; i >= 0; i--) {
        anss[i] = s.size();
        while (!s.empty() && s.top() < h[i]) s.pop();
        s.push(h[i]);
    }
    print(anss);

    return 0;
}
