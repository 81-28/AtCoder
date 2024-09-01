// https://atcoder.jp/contests/abc368/tasks/abc368_f

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

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

bool isPrime(const int& n) {
    if (n <= 1) {
        return false;
    } else if (n <= 3) {
        return true;
    } else if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    int i = 5;
    while (i * i <= n) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
        i += 6;
    }
    return true;
}
// 素因数分解する関数
vector<int> primeFactors(int n) {
    vector<int> factors;
    if (n < 2 || isPrime(n)) {
        factors.push_back(n);
    }else{
        int divisor = 2;
        while (n >= 2) {
            if (n % divisor == 0) {
                factors.push_back(divisor);
                n /= divisor;
            } else {
                divisor++;
            }
        }
    }
    return factors;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    int s = 0;
    rep(i,n) {
        vector<int> f = primeFactors(a[i]);
        s ^= f.size();
    }
    if (s == 0) print("Bruno");
    else print("Anna");

    return 0;
}
