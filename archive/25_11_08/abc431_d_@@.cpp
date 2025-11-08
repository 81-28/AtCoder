// https://atcoder.jp/contests/abc431/tasks/abc431_d

#include<bits/stdc++.h>
using namespace std;

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
// using mint=modint998244353;
// using mint=modint1000000007;
// using mint=modint;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define uniq(v) v.erase(unique(v.begin(),v.end()),v.end()) // sort後に使用する
#define substring(s,l,r) s.substr(l,r-l)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

// `double pow()`では大きい数の時に誤差が発生する オーバーフローに注意 剰余のときは`modint.pow()`で良い
int int_pow(int a,int b) {
    int r=1;
    while(b){if(b&1)r*=a;a*=a;b>>=1;}
    return r;
}
// log(0)=-1
int int_log2(int n) {
    int i=-1;
    for(;n>0;n>>=1)++i;
    return i;
}
// `double log10()`も同様に誤差が発生するので、`to_string(n).size()`が良い

// #define f first
// #define s second
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
void print(){cout<<endl;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")

// セグ木使おう
template<typename T>
auto sum(const v<T>& v){return accumulate(v.begin(),v.end(),T{});}
template<typename T>
T max(const v<T>& v){return *max_element(v.begin(),v.end());}
template<typename T>
T min(const v<T>& v){return *min_element(v.begin(),v.end());}


template<typename K,typename V>
class d_map:public map<K,V>{
public:
    V d_val;
    d_map(const V& default_value):d_val(default_value){}
    V& operator[](const K& key) {
        auto it=this->find(key);
        if (it==this->end()) {
            it=this->emplace(key,d_val).first;
        }
        return it->second;
    }
};

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<tuple<int,int,int>> t(n);
    int x=0,sm=0,mx=0;
    v<tuple<int,int,int>> a;
    rep(i,n) {
        auto&[w,h,b]=t[i];
        cin >> w >> h >> b;
        if (h<=b) {
            x+=w;
            sm+=b;
        } else {
            x-=w;
            sm+=h;
            a.pb(t[i]);
            mx+=w*2;
        }
    }
    int m=a.size();
    // dp[i][j];iまでで重さの差がj(体-頭)(非負だとok)の時の最大嬉しさ
    // v<map<int,int>> dp(m+1);

    // コストh-bを払って、2wを加算できる
    // xが0を超える時の最小コストは？
    // v<d_map<int,int>> dp(m+1,d_map<int,int>(LLONG_MAX));

    vvi dp(m+1,vi(mx+1,LLONG_MAX));
    dp[0][0]=0;
    rep(i,m) {
        auto[w,h,b]=a[i];
        rep(j,mx+1) {
            if (j>=x) {
                chmin(dp[i+1][j],dp[i][j]);
            } else {
                chmin(dp[i+1][min(j+w*2,x)],dp[i][j]+h-b);
                chmin(dp[i+1][j],dp[i][j]);
            }
        }
    }
    int ans=LLONG_MAX;
    for (int i=x; i<=mx; ++i) {
        chmin(ans,dp[m][i]);
    }
    print(sm-ans);

    return 0;
}
