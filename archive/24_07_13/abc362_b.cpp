// https://atcoder.jp/contests/abc362/tasks/abc362_b

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


int dot(vector<int> v1, vector<int> v2) {
    return v1[0]*v2[0] + v1[1]*v2[1];
}

int main() {
    vector<int> a(2),b(2),c(2);
    cin >> a >> b >> c;
    
    vector<int> vab = {b[0]-a[0],b[1]-a[1]},vac = {c[0]-a[0],c[1]-a[1]};
    if (dot(vab,vac) == 0)
    {
        YesNo(true);
        return 0;
    }
    vector<int> vba = {a[0]-b[0],a[1]-b[1]},vbc = {c[0]-b[0],c[1]-b[1]};
    if (dot(vba,vbc) == 0)
    {
        YesNo(true);
        return 0;
    }
    vector<int> vca = {a[0]-c[0],a[1]-c[1]},vcb = {b[0]-c[0],b[1]-c[1]};
    if (dot(vca,vcb) == 0)
    {
        YesNo(true);
        return 0;
    }
    YesNo(false);


    return 0;
}
