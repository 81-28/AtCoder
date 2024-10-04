// https://atcoder.jp/contests/abc371/tasks/abc371_a

#include <bits/stdc++.h>
using namespace std;

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

    char ab,ac,bc;
    cin >> ab >> ac >> bc;
    if ((ab == '<' && ac == '>') || (ab == '>' && ac == '<')) print('A');
    else if ((ab == '<' && bc == '<') || (ab == '>' && bc == '>')) print('B');
    else if ((ac == '<' && bc == '>') || (ac == '>' && bc == '<')) print('C');
    

    return 0;
}
