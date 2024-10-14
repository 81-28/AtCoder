// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cs

#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define rep1(i,n) for (int i=1; i<(int)(n+1); i++)
#define rep2(i,s,n) for (int i=(int)(s); i<(int)(n); i++)
#define pb(a) push_back(a)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define substring(s,l,r) s.substr(l,r-l)
#define YesNo(x) cout<<(x ? "Yes\n":"No\n")
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template<typename T>
using v = vector<T>;
using vi = v<int>;
using vvi = v<vi>;
using pii = pair<int,int>;

#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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


int main() {
    fastio();

    string s,t;
    cin >> s >> t;
    int sn = s.size(),tn = t.size();
    // dp[i][j] : sのi文字目,tのj文字目までで最大の部分列の長さ
    vvi dp(sn+1,vi(tn+1,0));
    // dpn[i][j] : dp[i][j]がs,tの何文字目を拾っているか
    v<v<v<pii>>> dpn(sn+1,v<v<pii>>(tn+1));
    rep1(i,sn) rep1(j,tn) {
        // dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        if (dp[i-1][j] > dp[i][j-1]) {
            dp[i][j] = dp[i-1][j];
            dpn[i][j] = dpn[i-1][j];
        } else {
            dp[i][j] = dp[i][j-1];
            dpn[i][j] = dpn[i][j-1];
        }
        // if (s[i-1] == t[j-1]) dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
        if (s[i-1] == t[j-1] && dp[i-1][j-1]+1 > dp[i][j]) {
            dp[i][j] = dp[i-1][j-1]+1;
            dpn[i][j] = dpn[i-1][j-1];
            dpn[i][j].push_back({i,j});
        }
    }
    // rep(i,sn+1) print(dp[i]);
    int lcsn = dp[sn][tn];
    rep(k,lcsn) print(dpn[sn][tn][k].first,dpn[sn][tn][k].second);

    // string lcs = dps[sn][tn];
    // vi interval_S(lcsn+1,0),interval_T(lcsn+1,0);
    // int l = 0;
    // rep(i,sn) {
    //     if (s[i] == lcs[l]) l++;
    //     else interval_S[l]++;
    // }
    // l = 0;
    // rep(j,tn) {
    //     if (t[j] == lcs[l]) l++;
    //     else interval_T[l]++;
    // }
    int ans = 0;
    // rep(k,lcsn+1) ans += max(interval_S[k],interval_T[k]);
    v<pii> lcsp = dpn[sn][tn];
    int i = 0,j = 0;
    rep(k,lcsn) {
        ans += max(lcsp[k].first-i-1,lcsp[k].second-j-1);
        i = lcsp[k].first;
        j = lcsp[k].second;
    }
    ans += max(sn-i,tn-j);
    print(ans);

    return 0;
}
