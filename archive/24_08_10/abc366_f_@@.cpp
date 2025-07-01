// https://atcoder.jp/contests/abc366/tasks/abc366_f

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

template<typename T>
vector<vector<T>> generatePermutations(const vector<T>& v, int r) {
    vector<vector<T>> permutations;
    vector<bool> select(v.size(), false);
    fill(select.begin(), select.begin() + r, true);
    do {
        vector<T> combination;
        for (int i = 0; i < v.size(); ++i) {
            if (select[i]) {
                combination.push_back(v[i]);
            }
        }
        sort(combination.begin(), combination.end());
        do {
            permutations.push_back(combination);
        } while (next_permutation(combination.begin(), combination.end()));

    } while (prev_permutation(select.begin(), select.end()));

    return permutations;
}


int main() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n),b(n);
    rep(i,n) {
        cin >> a[i] >> b[i];
    }
    vector<int> p;
    rep1(i,n) {
        p.push_back(i);
    }
    ll ans = 0;
    vector<vector<int>> pp = generatePermutations(p,k);
    rep(i,pp.size()) {
        ll nans = 1;
        rep(j,pp[i].size()) {
            int np = pp[i][j];
            nans = a[np]*nans + b[np];
        }
        ans = max(ans,nans);
    }

    return 0;
}
