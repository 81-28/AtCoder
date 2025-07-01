// https://atcoder.jp/contests/abc363/tasks/abc363_c

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
ostream &operator<<(ostream &os, const vector<T> &v) {
    for(int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != (int) v.size() ? " " : "");
    }
    return os;
}
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

int factorial(int k) {
    int result = 1;
    rep1(i,k) {
        result *= i;
    }
    return result;
}


int main() {
    int ans = 0;
    int n,k;
    string s;
    cin >> n >> k >> s;
    int k2 = k/2;
    map<char,int> num;
    rep(i,n) {
        num[s[i]]++;
    }
    map<char,int> num2 = num;
    for (const auto &pair : num2) {
        num2[pair.first] /= 2;
    }
    int sum2 = 0;
    set<char> del;
    for (const auto &pair : num2) {
        if (pair.second == 0)
        {
            del.insert(pair.first);
        } else {
            sum2 += pair.second;
        }
    }
    for (const auto element : del) {
        num2.erase(element);
    }

    ans = factorial(n);   
    for (const auto &pair : num) {
        ans /= pair.second;
    }
    if (sum2 < k2) {
        print(ans);
    } else {
        int includes = factorial(sum2);
        for (const auto &pair : num2) {
            includes /= pair.second;
        }
        print(ans - (n+1-k)*includes);
    }
    // kが奇数の時、中央の文字列を考慮できなくてこの方法諦めた
    

    return 0;
}
