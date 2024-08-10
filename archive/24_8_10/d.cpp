// https://atcoder.jp/contests/abc366/tasks/abc366_d

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


int main() {
    int n,q;
    cin >> n;
    vector<vector<vector<int>>> a(n,vector<vector<int>>(n,vector<int>(n)));
    rep(i,n) {
        rep(j,n) {
            rep(k,n) {
                cin >> a[i][j][k];
            }
        }
    }

    vector<vector<vector<int>>> s(n+1,vector<vector<int>>(n+1,vector<int>(n+1,0)));
    rep1(i,n) {
        rep1(j,n) {
            rep1(k,n) {
                s[i][j][k] = a[i-1][j-1][k-1] + s[i-1][j][k] + s[i][j-1][k] + s[i][j][k-1] - (s[i][j-1][k-1] + s[i-1][j][k-1] + s[i-1][j-1][k]) + s[i-1][j-1][k-1];
            }
        }
    }
    cin >> q;
    rep(i,q) {
        int lx,rx,ly,ry,lz,rz;
        cin >> lx >> rx >> ly >> ry >> lz >> rz;
        print(s[rx][ry][rz] - (s[lx-1][ry][rz] + s[rx][ly-1][rz] + s[rx][ry][lz-1]) + s[rx][ly-1][lz-1] + s[lx-1][ry][lz-1] + s[lx-1][ly-1][rz] - s[lx-1][ly-1][lz-1]);
    }

    return 0;
}
