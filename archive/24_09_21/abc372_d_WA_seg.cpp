// https://atcoder.jp/contests/abc372/tasks/abc372_d

// Ctrl + Shift + B                => Build
// Terminal : "./a.out"            => Run
// Terminal : "./a.out < ./in.txt" => Run

#include <bits/stdc++.h>
using namespace std;
// #define int long long
// #include <atcoder/all>
// using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
#define pb(a) push_back(a)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define substring(s,l,r) s.substr(l,r-l)
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template<typename T>
using v = vector<T>;
using vi = v<int>;
using vvi = v<vi>;
using vll = v<ll>;
using vvll = v<vll>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
// using mint = modint1000000007;
// using mint = modint998244353;

#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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

template<typename T>
int sum(const vector<T>& v) { return accumulate(v.begin(),v.end(),0); }
template<typename T>
ll sumLL(const vector<T>& v) { return accumulate(v.begin(),v.end(),0LL); }

template<typename T>
T max(const vector<T>& v) { return *max_element(v.begin(),v.end()); }
template<typename T>
T min(const vector<T>& v) { return *min_element(v.begin(),v.end()); }
template<typename T, typename... Args>
T max(const T& a, const T& b, const T& c, const Args&... args) { return max({a,b,c,args...}); }
template<typename T, typename... Args>
T min(const T& a, const T& b, const T& c, const Args&... args) { return min({a,b,c,args...}); }


class SegmentTree {
public:
    vector<int> vec;
    int size = 1;
    SegmentTree(const int& n) {
        while (size < n) size *= 2;
        // 木構造(三角形)なので要素数はsize*2-1([0]は使わない)
        vec = vector<int>(size*2,0);
    }

    void update(int pos, const int& x) {
        // 最も子の要素を更新
        pos = pos + (size-1);
        vec[pos] = x;
        // 親の要素を更新
        while (pos > 1) {
            pos /= 2;
            vec[pos] = max(vec[pos*2],vec[pos*2+1]);
        }
    }

    // [l,r): 求める対象の区間, [a,b): 現在の区間, pos: 現在地の番号
    int query(const int& l, const int& r, const int& a, const int& b, const int& pos) {
        if (r <= a || b <= l) return INT_MIN; // 一切重ならない場合
        if (l <= a && b <= r) return vec[pos]; // 完全に含まれる場合
        // 現在の区間内に境目(l||r)が存在する場合、子の最大値を求める
        int m = (a+b)/2;
        int ql = query(l,r,a,m,pos*2);
        int qr = query(l,r,m,b,pos*2+1);
        return max(ql,qr);
    }
};

int main() {
    fastio();

    int n;
    cin >> n;
    SegmentTree t(n);
    vi h(n);
    rep1(i,n) {
        cin >> h[i-1];
        t.update(i,h[i-1]);
    }
    vi anss(n,1);
    anss[n-1] = 0;
    for (int j = n; j >= 3; j--) {
        for (int i = j-2; i >= 1; i--) {
            if (t.query(i+1,j,1,t.size+1,1) < h[j-1]) anss[i-1]++;
            else break;
        }
    }
    print(anss);

    return 0;
}
