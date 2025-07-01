// https://atcoder.jp/contests/abc385/tasks/abc385_d

#include<bits/stdc++.h>
using namespace std;

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
#define max(...) (*max_element({__VA_ARGS__}))
#define min(...) (*min_element({__VA_ARGS__}))


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n,m,sx,sy;
    cin >> n >> m >> sx >> sy;
    unordered_map<ll,unordered_set<ll>> mm,mt;
    ll x,y;
    rep(i,n) {
        cin >> x >> y;
        mm[x].insert(y);
        mt[y].insert(x);
    }
    // for(auto p:mm) {
    //     sort(all(mm[p.first]));
    // }
    // for(auto p:mt) {
    //     sort(all(mt[p.first]));
    // }
    char d;
    ll c;
    unordered_map<ll,unordered_set<ll>> s;
    unordered_set<ll> h;
    x = sx,y = sy;
    rep(i,m) {
        cin >> d >> c;
        if (d == 'U') {
            y += c;
            h = mm[x];
            for (auto val:h) {
                if (sy < val && val <= y) {
                    s[x].insert(val);
                }
            }
            // for (auto it=upper_bound(all(h),sy); *it <= y; it++) {
            //     s[x].insert(*it);
            // }
        }
        if (d == 'D') {
            y -= c;
            h = mm[x];
            for (auto val:h) {
                if (y <= val && val < sy) {
                    s[x].insert(val);
                }
            }
            // auto it=lower_bound(all(h),sy);
            // it--;
            // for (; *it >= y; it--) {
            //     s[x].insert(*it);
            // }
        }
        if (d == 'L') {
            x -= c;
            h = mt[y];
            for (auto val:h) {
                if (x <= val && val < sx) {
                    s[val].insert(y);
                }
            }
            // auto it=lower_bound(all(h),sx);
            // it--;
            // for (; *it >= x; it--) {
            //     s[*it].insert(y);
            // }
        }
        if (d == 'R') {
            x += c;
            h = mt[y];
            for (auto val:h) {
                if (sx < val && val <= x) {
                    s[val].insert(y);
                }
            }
            // for (auto it=upper_bound(all(h),sx); *it <= x; it++) {
            //     s[*it].insert(y);
            // }
        }
        sx = x,sy = y;
    }
    ll ans = 0;
    for(auto p:s) {
        ans += p.second.size();
    }
    print(x,y,ans);

    return 0;
}
