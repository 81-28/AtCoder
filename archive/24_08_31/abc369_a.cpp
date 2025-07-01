// https://atcoder.jp/contests/abc369/tasks/abc369_a

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
    int a,b;
    cin >> a >> b;
    if (a == b) {
        print(1);
    } else {
        if ((a+b)%2 == 0) {
            print(3);
        } else {
            print(2);
        }
    }

    return 0;
}
