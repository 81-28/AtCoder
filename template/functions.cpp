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


// ################################################################


// 合計する関数
template<typename T>
int sum(const vector<T>& v) { return accumulate(v.begin(),v.end(),0); }
template<typename T>
ll sumLL(const vector<T>& v) { return accumulate(v.begin(),v.end(),0LL); }
// int sum(const set<int>& set) {
//     vector<int> vec(all(set));
//     return accumulate(all(vec),0);
// }
// ll sumLL(const set<int>& set) {
//     vector<int> vec(all(set));
//     return accumulate(all(vec),0LL);
// }


// 最大,最小値を求める関数
template<typename T>
T max(const vector<T>& v) { return *max_element(v.begin(),v.end()); }
template<typename T>
T min(const vector<T>& v) { return *min_element(v.begin(),v.end()); }
template<typename T, typename... Args>
T max(const T& a, const T& b, const Args&... args) { return max(a,max(b,args...)); }
template<typename T, typename... Args>
T min(const T& a, const T& b, const Args&... args) { return min(a,min(b,args...)); }


// 階乗する関数
int factorial(const int& k) {
    int result = 1;
    rep1(i,k) result *= i;
    return result;
}
ll factorialLL(const int& n) {
    ll result = 1;
    rep1(i,n) result *= i;
    return result;
}


// ユークリッドの互除法を用いて最大公約数を求める関数
ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
// 最小公倍数を求める関数
ll lcm(const ll& a, const ll& b) {
    return abs(a * b) / gcd(a, b);
}

// 素数判定する関数
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
    } else {
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


// 二分探索をして、値のindexを返す関数
int binSearch(const vector<int>& a, const int& x) {
    int l = 0,r = a.size()-1;
    while (l <= r) {
        int m = (l+r)/2;
        if (x < a[m]) r = m-1;
        if (x == a[m]) return m;
        if (x > a[m]) l = m+1;
    }
    return -1;
}


// 文字列を逆さまにする関数
string reverseString(const string& s) {
    string str = s;
    reverse(all(str));
    return str;
}


// 文字列が回文かどうか判定する関数
bool isPalindrome(const string& s) {
    int left = 0;
    int right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}


// 全ての並べ替えの配列を生成する関数　重複なし
vector<string> generatePermutations(const string& s) {
    string str = s;
    sort(all(str));
    vector<string> permutations;
    do {
        permutations.push_back(str);
    } while (next_permutation(all(str)));
    return permutations;
}
template<typename T>
vector<vector<T>> generatePermutations(const vector<T>& v) {
    vector<T> vec = v;
    sort(all(vec));
    vector<vector<T>> permutations;
    do {
        permutations.push_back(vec);
    } while (next_permutation(all(vec)));
    return permutations;
}
// 全ての順列を生成する関数?
// template<typename T>
// vector<vector<T>> generatePermutations(const vector<T>& v, int r) {
//     vector<vector<T>> permutations;
//     vector<bool> select(v.size(), false);

//     // 最初の r 個を true に設定する
//     fill(select.begin(), select.begin() + r, true);

//     do {
//         vector<T> combination;
//         for (int i = 0; i < v.size(); ++i) {
//             if (select[i]) {
//                 combination.push_back(v[i]);
//             }
//         }

//         // r個選んだ要素に対して全ての順列を生成する
//         sort(combination.begin(), combination.end());
//         do {
//             permutations.push_back(combination);
//         } while (next_permutation(combination.begin(), combination.end()));

//     } while (prev_permutation(select.begin(), select.end()));

//     return permutations;
// }


// ################################################################


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    vector<vector<int>> perms(generatePermutations(a));
    for (auto perm : perms) print(perm);

    return 0;
}