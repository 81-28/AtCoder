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
int sum(const vector<int>& v) { return accumulate(all(v),0); }
ll sumLL(const vector<int>& v) { return accumulate(all(v),0LL); }
int sum(const set<int>& set) {
    vector<int> vec(all(set));
    return accumulate(all(vec),0);
}
ll sumLL(const set<int>& set) {
    vector<int> vec(all(set));
    return accumulate(all(vec),0LL);
}


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


// 二分探索をして、値のindexを返す関数
int binSearch(vector<int> a, int x) {
    int l = 0,r = a.size()-1;
    while (l <= r)
    {
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