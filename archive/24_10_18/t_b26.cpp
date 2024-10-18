// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cy
#include <bits/stdc++.h>
using namespace std;
bool isPrime(const int& n) {
    if (n <= 1) return false;
    else if (n <= 3) return true;
    else if (!(n%2&&n%3)) return false;
    for (int i=5;i*i<=n;i+=6) if (!(n%i&&n%(i+2))) return false;
    return true;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i=2;i<=n;i++) if (isPrime(i)) cout<<i<<'\n';
    return 0;
}