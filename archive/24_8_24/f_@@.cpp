// 

// Ctrl + Shift + B                => Build
// Terminal : "./a.out"            => Run
// Terminal : "./a.out < ./in.txt" => Run

#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define substring(s,l,r) s.substr(l,r-l)
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
// using mint = modint1000000007;
// using mint = modint998244353;

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
    int s = n;
    int countP = 0,countC = 0;
    rep(i,n) {
        vector<int> f = primeFactors(a[i]);
        s += f.size()%2;
        if (f.size() == 1) countP++;
        else countC++;
    }
    if (countC==1) {
        print("Anna");
    } else {
        if (s%2 == 0) {
            print("Bruno");
        } else {
            print("Anna");
        }
    }

    return 0;
}
