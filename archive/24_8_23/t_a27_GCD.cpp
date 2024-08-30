// https://atcoder.jp/contests/tessoku-book/tasks/math_and_algorithm_o

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

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a,b;
    cin >> a >> b;
    print(gcd(a,b));

    return 0;
}
