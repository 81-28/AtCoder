// https://atcoder.jp/contests/abc365/tasks/abc365_d

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


char winHand(const char& h) {
    switch (h)
    {
    case 'R':
        return 'P';
    case 'P':
        return 'S';
    case 'S':
        return 'R';
    default:
        return 'P';
    }
}
char loseHand(const char& h) {
    switch (h)
    {
    case 'R':
        return 'S';
    case 'P':
        return 'R';
    case 'S':
        return 'P';
    default:
        return 'P';
    }
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    string t = "";
    rep(i,n) {
        t.push_back(winHand(s[i]));
    }
    int ans = n;
    for (int i = 1; i < n; i++)
    {
        if (t[i-1] == t[i])
        {
            string tl = t,tr = t;
            tl[i-1] = s[i-1];
            tr[i] = s[i];
            int right = 0,left = 0;
            for (int j = i-1; j > 0; j--)
            {
                if (t[j] != t[j-1])
                {
                    break;
                } else {
                    tl[j-1] = s[j-1];
                    left++;
                }
            }
            for (int j = i; j < n-1; j++)
            {
                if (t[j] != t[j+1])
                {
                    break;
                } else {
                    tr[j-1] = s[j-1];
                    right++;
                }
            }
            if (left <= right)
            {
                t = tl;
                ans -= left;
            } else {
                t = tr;
                ans -= right;
            }
        }
    }
    print(ans);

    return 0;
}
