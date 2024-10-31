// 

// Ctrl + Shift + B                => Build
// Terminal : "./a.out"            => Run
// Terminal : "./a.out < ./in.txt" => Run

#include<bits/stdc++.h>
using namespace std;
// #define int long long
// #include <atcoder/all>
// using namespace atcoder;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n+1);i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
// substring : { s.begin()+l, s.begin()+r }
#define substring(s,l,r) s.substr(l,r-l)
#define YesNo(x) cout<<(x?"Yes\n":"No\n")
using ll=long long;
using ull=unsigned long long;
using ld=long double;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using vll=v<ll>;
using vvll=v<vll>;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
// using mint=modint1000000007;
// using mint=modint998244353;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){for(int i=0;i<(int)v.size();i++)os<<(i?" ":"")<<v[i];return os;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


// ################################################################


// 合計する関数
template<typename T>
auto sum(const vector<T>& v){return accumulate(v.begin(),v.end(),T{});}
// template<typename T>
// int sum(const vector<T>& v) { return accumulate(v.begin(),v.end(),0); }
// template<typename T>
// ll sumLL(const vector<T>& v) { return accumulate(v.begin(),v.end(),0LL); }
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
T max(const vector<T>& v){return *max_element(v.begin(),v.end());}
template<typename T>
T min(const vector<T>& v){return *min_element(v.begin(),v.end());}
#define max(...) (*max_element({__VA_ARGS__}))
#define min(...) (*min_element({__VA_ARGS__}))
// template<typename T, typename... Args>
// T max(const T& a, const T& b, const T& c, const Args&... args) { return max({a,b,c,args...}); }
// template<typename T, typename... Args>
// T min(const T& a, const T& b, const T& c, const Args&... args) { return min({a,b,c,args...}); }


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
    if (n <= 1) return false;
    else if (n <= 3) return true;
    else if (!(n%2&&n%3)) return false;
    for (int i=5;i*i<=n;i+=6) if (!(n%i&&n%(i+2))) return false;
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


// 素数 p に対する a^b の計算を行い、m で割った余りを返す関数
ll ModPower(ll a, ll b, ll m) {
    ll result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % m;
        }
        a = (a * a) % m;
        b /= 2;
    }
    return result;
}

// a ÷ b を m で割った余りを返す関数
ll Division(ll a, ll b, ll m) {
    return (a * ModPower(b, m - 2, m)) % m;
}

// nCr を計算する関数
ll nCr(ll n, ll r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n - r) r = n - r;

    ll result = 1;
    for (int i = 1; i <= r; i++) {
        result = result * (n - i + 1) / i;
    }
    return result;
}
// nCr を m で割った余りを計算する関数
ll nCrModM(ll n, ll r, ll m) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n - r) r = n - r;

    ll numerator = 1, denominator = 1;
    for (int i = 1; i <= n; i++) {
        numerator = (numerator * i) % m;
        if (i == r || i == n - r) denominator = (denominator * numerator) % m;
    }
    ll result = 1, power = m - 2;
    while (power > 0) {
        if (power % 2 == 1) result = (result * denominator) % m;
        denominator = (denominator * denominator) % m;
        power /= 2;
    }
    return (numerator * result) % m;
}
// nCr を m で割った余りを計算する関数（m = 0 の場合は割らない）
ll nCrModM(ll n, ll r, ll m) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;

    ll numerator = 1, denominator = 1;
    for (int i = 1; i <= n; i++) {
        numerator *= i;
        if (i == r || i == n - r) denominator *= numerator;
        if (m != 0) {
            numerator %= m;
            denominator %= m;
        }
    }
    if (m == 0) {
        return numerator / denominator;
    } else {
        ll result = 1, power = m - 2;
        while (power > 0) {
            if (power % 2 == 1) result = (result * denominator) % m;
            denominator = (denominator * denominator) % m;
            power /= 2;
        }
        return (numerator * result) % m;
    }
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
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    cin >> a;

    int ans = 0;
    print(ans);

    vi anss(n,0);
    print(anss);

    vvi ansss(n,vi(n,0));
    rep(i,n) print(ansss[i]);

    return 0;
}