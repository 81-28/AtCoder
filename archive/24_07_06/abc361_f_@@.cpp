// https://atcoder.jp/contests/abc361/tasks/abc361_f

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



int main() {
    ll n;
    cin >> n;
    unordered_set<ll> ans;
    ans.insert(1);
    // int maxB = log2(n);
    // for (int b = 2; b <= maxB; b++)
    // {
    //     ll a = 2;
    //     ll p = pow(2,b);
    //     while (p <= n) {
    //         ans.insert(p);
    //         a++;
    //         p = pow(a,b);
    //         while(ans.find(a) != ans.end()) {
    //             a++;
    //             p = pow(a,b);
    //         }
    //     }
    // }
    ll maxA = sqrt(n);
    ll a = 2;
    while (a < maxA)
    {
        int b = 2;
        ll p = pow(a,2);
        while (p <= n) {
            ans.insert(p);
            b++;
            p = pow(a,b);
        }
        a++;
        while(ans.find(a) != ans.end()) {
            a++;
        }
    }

    print(ans.size());


    return 0;
}
