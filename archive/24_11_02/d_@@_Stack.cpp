// https://atcoder.jp/contests/abc378/tasks/abc378_d

// Ctrl + Shift + B                => Build
// Terminal : "./a.out"            => Run
// Terminal : "./a.out < ./in.txt" => Run

#include<bits/stdc++.h>
using namespace std;
// #define int long long
// #include <atcoder/all>
// using namespace atcoder;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n+1);i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define substring(s,l,r) s.substr(l,r-l)
#define YesNo(x) cout<<(x?"Yes\n":"No\n")
using ll=long long;
using ull=unsigned long long;
using ld=long double;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using vll=v<ll>;
using vvll=v<vll>;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
// using mint=modint1000000007;
// using mint=modint998244353;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){for(int i=0;i<(int)v.size();i++)os<<(i?" ":"")<<v[i];return os;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

template<typename T>
auto sum(const vector<T>& v){return accumulate(v.begin(),v.end(),T{});}

template<typename T>
T max(const vector<T>& v){return *max_element(v.begin(),v.end());}
template<typename T>
T min(const vector<T>& v){return *min_element(v.begin(),v.end());}
#define max(...) (*max_element({__VA_ARGS__}))
#define min(...) (*min_element({__VA_ARGS__}))


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w,k;
    cin >> h >> w >> k;
    v<string> s(h);
    rep(i,h) cin >> s[i];
    v<v<v<int>>> g(h,vvi(w));
    rep(i,h) rep(j,w) {
        if (j+1 < w && s[i][j+1] == '.') g[i][j].pb(0);
        if (i+1 < h && s[i+1][j] == '.') g[i][j].pb(1);
        if (0 <= j-1 && s[i][j-1] == '.') g[i][j].pb(2);
        if (0 <= i-1 && s[i-1][j] == '.') g[i][j].pb(3);
    }

    ll ans = 0;
    rep(i,h) rep(j,w) {
        stack<pii> s;
        stack<int> sn;
        s.push({i,j});
        sn.push(0);
        v<pii> p;
        p[0] = {i,j};
        while (!s.empty()) {
            pii pos = s.top();
            s.pop();
            int now = sn.top();
            sn.pop();
            if (now >= k) break;
            v<pii> pn(p.begin(),p.begin()+now+1);
            set<pii> ps(all(pn));
            vi nexG = g[pos.first][pos.second];
            pii next;
            for (int val : nexG) {
                if (val == 0) {
                    next = {pos.first,pos.second+1};
                    if (ps.find(next) == ps.end()) {
                        s.push(next);
                        p[now] = next;
                    }
                }
                if (val == 1) {
                    next = {pos.first+1,pos.second};
                    if (ps.find(next) == ps.end()) {
                        s.push(next);
                        p[now] = next;
                    }
                }
                if (val == 2) {
                    next = {pos.first,pos.second-1};
                    if (ps.find(next) == ps.end()) {
                        s.push(next);
                        p[now] = next;
                    }
                }
                if (val == 3) {
                    next = {pos.first-1,pos.second};
                    if (ps.find(next) == ps.end()) {
                        s.push(next);
                        p[now] = next;
                    }
                }
            }
        }
        
    }
    print(ans);

    return 0;
}
