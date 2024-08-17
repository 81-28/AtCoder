// https://atcoder.jp/contests/abc367/tasks/abc367_b

#include <bits/stdc++.h>
using namespace std;

void print() { cout << '\n'; }
template<typename T>
void print(const T &t) { cout << t << '\n'; }
template<typename Head, typename... Tail>
void print(const Head &head, const Tail &... tail) {
    cout << head << ' ';
    print(tail...);
}

int main() {
    string x;
    cin >> x;
    for (int i = x.size()-1; i >= 0; i--) {
        if (x[i] == '0') {
            x.pop_back();
        } else if (x[i] == '.') {
            x.pop_back();
            break;
        } else {
            break;
        }
    }
    print(x);

    return 0;
}
