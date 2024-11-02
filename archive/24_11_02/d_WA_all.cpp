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

    ll ans = 0;
    rep(i,h) {
        rep(j,w) {
            rep(l,1<<(2*k)) {
                if (s[i][j] == '#') continue;
                pii pos = {i,j};
                v<v<bool>> d(h,v<bool>(w,0));
                d[i][j] = 1;
                rep(m,k) {
                    int next = (l>>(m*2))%4;
                    if (next == 0) pos.second++;
                    if (next == 1) pos.first++;
                    if (next == 2) pos.second--;
                    if (next == 3) pos.first--;
                    if (0 <= pos.first && pos.first < h && 0 <= pos.second && pos.second < w && s[pos.first][pos.second] == '.' && !d[pos.first][pos.second]) {
                        if (m == k-1) {
                            ans++;
                        }
                    } else {
                        break;
                    }
                }
            }
        }
    }
    print(ans);

    return 0;
}
