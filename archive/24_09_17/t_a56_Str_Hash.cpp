// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bd

#include <bits/stdc++.h>
using namespace std;

#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
using ll = long long;
template<typename T>
using v = vector<T>;
using vll = v<ll>;

#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

ll mod = 2147483647;
vll t,h,pow100;

// S[l, r] のハッシュ値を返す関数
ll hashValue(const int& l, const int& r) {
    long long val = h[r] - (h[l-1] * pow100[r-l+1] % mod);
    if (val < 0) val += mod;
    return val;
}

int main() {
    fastio();

    int n,q;
    string s;
    cin >> n >> q >> s;

    t.resize(n+1);
    rep1(i,n) t[i] = (s[i-1]-'a')+1;

    pow100.resize(n+1);
    pow100[0] = 1;
    rep1(i,n) pow100[i] = pow100[i-1] * 100LL % mod;

    h.resize(n+1);
    h[0] = 0;
    rep1(i,n) h[i] = (h[i-1] * 100LL + t[i]) % mod;

    ll a,b,c,d;
    rep1(i,q) {
        cin >> a >> b >> c >> d;
        YesNo(hashValue(a,b) == hashValue(c,d));
    }

    return 0;
}
