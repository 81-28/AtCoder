// https://atcoder.jp/contests/abc386/tasks/abc386_d

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
// #define max(...) (*max_element({__VA_ARGS__}))
// #define min(...) (*min_element({__VA_ARGS__}))


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    v<pii> b,w;
    int x,y;
    char c;
    rep(i,m) {
        cin >> x >> y >> c;
        if (c=='B') {
            b.pb({x,y});
        } else {
            w.pb({x,y});
        }
    }
    sort(all(b));
    sort(all(w));
    for(pii p:b) {
        for(pii q:w) {
            if (q.f>p.f) break;
            if (q.f<=p.f && q.s<=p.s) {
                YesNo(0);
                return 0;
            }
        }
    }
    // for(pii q:w) {
    //     // auto it=lower_bound(all(b),q);
    //     // if (it != b.end()) {
    //     //     YesNo(0);
    //     //     return 0;
    //     // }
    //     for(auto it=lower_bound(all(b),q); it!=b.end(); it++) {
    //         if (q.s<=(*it).s) {
    //             YesNo(0);
    //             return 0;
    //         }
    //     }
    // }
    YesNo(1);

    return 0;
}
