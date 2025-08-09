// https://atcoder.jp/contests/abc418/tasks/abc418_f

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

using ll=long long;
#define int ll
using ull=unsigned long long;
using ld=long double;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
const pii dir[4]={{-1,0},{0,-1},{1,0},{0,1}};
// const pii dir[8]={{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
// using mint=modint1000000007;
using mint=modint998244353;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define uniq(v) v.erase(unique(v.begin(),v.end()),v.end()); // sort後に使用する
#define substring(s,l,r) s.substr(l,r-l)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}
#define YesNo(x) puts(x?"Yes":"No")

#define f first
#define s second
// // pairの足し算
// template<typename F,typename S>
// pair<F,S> operator+(const pair<F,S>& a,const pair<F,S>& b){return{a.f+b.f,a.s+b.s};}
// // pairのデクリメント
// template<typename F,typename S>
// pair<F,S>& operator--(pair<F,S>& p){--p.f;--p.s;return p;}
// // pairと定数の掛け算
// template<typename F,typename S,typename T>
// pair<F,S> operator*(const pair<F,S>& p,const T& a){return{p.f*a,p.s*a};}
// // 定数とpairの掛け算
// template<typename F,typename S,typename T>
// pair<F,S> operator*(const T& a,const pair<F,S>& p){return{a*p.f,a*p.s};}

// AtCoderでは、inもoutもvector,pair,tuple組み合わせて使えない
template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename F,typename S>
ostream &operator<<(ostream &os,const pair<F,S> &p){os<<p.first<<' '<<p.second;return os;}
template<typename... Args>
istream &operator>>(istream &is,tuple<Args...> &t){apply([&is](auto&... args){((is>>args),...);},t);return is;}
template<typename... Args>
ostream &operator<<(ostream &os,const tuple<Args...> &t){apply([&os](const auto&... args){int i=0;((os<<(i++?" ":"")<<args),...);},t);return os;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

// セグ木使おう
template<typename T>
auto sum(const v<T>& v){return accumulate(v.begin(),v.end(),T{});}
template<typename T>
T max(const v<T>& v){return *max_element(v.begin(),v.end());}
template<typename T>
T min(const v<T>& v){return *min_element(v.begin(),v.end());}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    // dp[i][j]:jで終わるi+1個のまとまりで、(どの隣り合う2つのティーポットについても、少なくとも片方には紅茶を入れる)パターン数
    v<v<mint>> dp(n,v<mint>(2,0));
    rep(i,n) {
        if (i) {
            dp[i][1]=dp[i-1][1]+dp[i-1][0];
            dp[i][0]=dp[i-1][1];
        } else {
            dp[i]={1,1};
        }
    }
    // mint ans=dp[n-1][1]+dp[n-1][0];
    vi a(n+1,-1);
    set<int> st;
    map<int,mint> mp;
    while (q--) {
        pii p;
        cin >> p;
        if (a[p.f]==p.s) continue;

        // 左右に(a_i!=-1)が存在するかどうかを見る
        // 左右と辻褄を合わせて、組み合わせの個数を更新する
        auto itl=st.lower_bound(p.f);
        bool exl=(itl!=st.begin());
        if (exl) --itl;
        auto itr=st.upper_bound(p.f);
        bool exr=(itr!=st.end());

        if (p.s==-1) {
            if (exl) {
                if (exr) {
                } else {
                }
            } else {
                if (exr) {
                } else {
                }
            }
        } else {
            if (exl) {
                if (exr) {
                } else {
                }
            } else {
                if (exr) {
                } else {
                }
            }
        }
    }


    return 0;
}
