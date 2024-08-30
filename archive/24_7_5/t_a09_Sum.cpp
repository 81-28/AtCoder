// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_i

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
    int h,w,n;
    cin >> h >> w >> n;
    Graph s(h+2,vector<int>(w+2,0));
    rep(i,n) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        s[a][b]++;
        s[c+1][d+1]++;
        s[c+1][b]--;
        s[a][d+1]--;
    }
    rep1(i,h) {
        rep1(j,w) {
            s[i][j] += s[i][j-1] + s[i-1][j] - s[i-1][j-1];
        }
    }

    rep1(i,h) {
        rep1(j,w) {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}
