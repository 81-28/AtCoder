// https://atcoder.jp/contests/abc392/tasks/abc392_f

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n+1);i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define substring(s,l,r) s.substr(l,r-l)
// #define f first
// #define s second
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

    int n;
    cin >> n;
    vi p(n);
    cin >> p;
    // vi q(n+1);
    // q[1] = 1;
    // for (int i=1; i<n; i++) {
    //     q[i+1] = p[i];
    //     for (int j=0; j<i; j++) {
    //         if (q[j+1] >= p[i]) {
    //             q[j+1]++;
    //         }
    //     }
    // }
    vi ans(n,0);
    // rep1(i,n) ans[q[i]-1] = i;
    // print(ans);
    set<int> s;
    rep(i,n) s.insert(i);
    auto it=s.begin();
    for (int i=n-1; i>=0; i--) {
        it = next(s.begin(),p[i]-1);
        // advance(it,p[i]-1);
        ans[*it] = i+1;
        s.erase(it);
        // ans[s[p[i]-1]] = i+1;
        // s.erase(s.begin() + (p[i]-1));
    }
    print(ans);


    return 0;
}
