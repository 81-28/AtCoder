// https://codeforces.com/gym/105633/problem/K

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n+1);i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define substring(s,l,r) s.substr(l,r-l)
#define f first
#define s second
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
template<typename F,typename S>
ostream &operator<<(ostream &os,const pair<F,S> &p){os<<p.first<<" "<<p.second;return os;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

template<typename T>
auto sum(const vector<T>& v){return accumulate(v.begin(),v.end(),T{});}

template<typename T>
T max(const vector<T>& v){return *max_element(v.begin(),v.end());}
template<typename T>
T min(const vector<T>& v){return *min_element(v.begin(),v.end());}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    v<string> a(n);
    cin >> a;
    // dp[i][j] : 最初のi枚まで(のうち何枚か選んで)で状態jを作るのに必要な最小枚数
    vvi dp(n+1,vi((1<<m),INT_MAX));
    dp[0][0] = 0;
    // v<v<pii>> p(n+1,v<pii>((1<<m)));
    unordered_map<int,unordered_map<int,pii>> p;
    p[0][0] = {0,0};
    // vvi c(n+1,vi((1<<m)));
    unordered_map<int,unordered_map<int,int>> c;
    bool ok = false;
    v<pair<int,pii>> ans;
    rep(i,n) {
        rep(j,(1<<m)) {
            if (dp[i][j] != INT_MAX) {
                // dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
                if (dp[i][j] <= dp[i+1][j]) {
                    dp[i+1][j] = dp[i][j];
                    p[i+1][j] = p[i][j];
                }

                int newJ = 0;
                int sum = 0;
                rep(k,m) {
                    if ((j>>k)%2 || a[i][k] == 'Y') newJ += (1<<k);
                    sum += (a[i][k] == 'Y')?1:0;
                }
                // dp[i+1][newJ] = min(dp[i+1][newJ],dp[i][j]+1);
                if (dp[i][j]+1 <= dp[i+1][newJ]) {
                    dp[i+1][newJ] = dp[i][j]+1;
                    p[i+1][newJ] = {i,j};
                    if (newJ == (1<<m)-1 && dp[i+1][newJ] == 2) {
                        ans.pb({-(sum+c[i][j]),{p[i][j].f+1,i+1}});
                        ok = true;
                    } else if(dp[i+1][newJ] == 1) {
                        c[i+1][newJ] = sum;
                    }
                }
            }
        }
    }
    if (ok) {
        sort(all(ans));
        print(ans[0].s);
    } else YesNo(0);

    return 0;
}
