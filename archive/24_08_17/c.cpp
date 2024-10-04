// https://atcoder.jp/contests/abc367/tasks/abc367_c

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

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

int sum(const vector<int>& v) { return accumulate(all(v),0); }

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> r(n);
    cin >> r;
    vector<int> a;
    rep(i,n) {
        a.push_back(1);
    }
    vector<vector<int>> anss;
    if (n%k == 0) {
        anss.push_back(a);
    }
    while(a[0] <= r[0]) {
        do {
            a[n-1]++;
            for (int i = n-1; i > 0; i--) {
                if (a[i] > r[i])
                {
                    a[i] = 1;
                    a[i-1]++;
                } else {
                    break;
                }
            }
        } while (sum(a)%k != 0);
        if (a[0] <= r[0]) {
            anss.push_back(a);
        } else {
            break;
        }
    }
    rep(i,anss.size()) {
        print(anss[i]);
    }

    return 0;
}
