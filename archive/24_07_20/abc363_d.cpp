// https://atcoder.jp/contests/abc363/tasks/abc363_d

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


string reverseString(const string& str) {
    string reversedStr = str;
    reverse(reversedStr.begin(), reversedStr.end());
    return reversedStr;
}

int main() {
    ll n;
    cin >> n;
    set<ll> ans,ans1;

    rep(i,10) ans1.insert(i);

    set<ll> pNum;
    for (int i = 2; i <= 30; i++)
    {
        if(ans.size() >= n) {
            break;
        }
        if (i&2)
        {
            for (int k = 0; k < 10; k++)
            {
                ll de = pow(10,i/2);
                for (int j = 0; j < de; j++)
                {
                    ans.insert(j*de*10+k*de+stoll(reverseString(to_string(j))));
                }
            }
            
        } else {
            ll de = pow(10,i/2);
            for (int j = 0; j < de; j++)
            {
                ans.insert(j*de+stoll(reverseString(to_string(j))));
            }
        }
    }

    auto it = ans.begin();
    advance(it, n - 1);
    print(*it);

    return 0;
}
