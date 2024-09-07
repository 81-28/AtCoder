// https://atcoder.jp/contests/abc370/tasks/abc370_c

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb(a) push_back(a)
template<typename T>
using v = vector<T>;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for(T &in : v) is >> in;
    return is;
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

    string s,t;
    cin >> s >> t;
    int sn = s.size();
    v<string> anss;
    rep(i,sn) {
        if (s[i] > t[i]) {
            s.replace(i,1,string(1,t[i]));
            anss.pb(s);
        }
    }
    for (int i = sn-1; i  >= 0; i--) {
        if (s[i] < t[i]) {
            s.replace(i,1,string(1,t[i]));
            anss.pb(s);
        }
    }

    int n = anss.size();
    print(n);
    if (n > 0) {
        rep(i,n) print(anss[i]);
    }

    return 0;
}
