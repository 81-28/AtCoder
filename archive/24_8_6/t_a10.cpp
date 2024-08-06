// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_j

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
    int n,d;
    cin >> n;
    vector<int> a(n);
    cin >> a >> d;
    map<int,vector<int>> hn;
    rep(i,n) {
        hn[a[i]].push_back(i+1);
    }
    set<int> aset(all(a));
    vector<int> b(rall(aset));
    rep(i,d) {
        int l,r;
        cin >> l >> r;
        int ans = 0;
        for (int num : b)
        {
            bool ok = false;
            vector<int> nowa = hn[num];
            for (int value : nowa)
            {
                if (value < l || r < value)
                {
                    ok = true;
                    break;
                }
            }
            if (ok)
            {
                ans = num;
                break;
            }
        }
        print(ans);
    }

    return 0;
}
