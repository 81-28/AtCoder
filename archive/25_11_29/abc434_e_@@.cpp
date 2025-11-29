// https://atcoder.jp/contests/abc434/tasks/abc434_e

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


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    // mp[i]:座標iに行きうるウサギの数
    unordered_map<int,int> mp;
    // g[i]:座標iに来れるウサギのidx
    unordered_map<int,vi> g;
    // {x,r,i}
    v<tuple<int,int,int>> p(n);
    rep(i,n) {
        auto&[x,r,j]=p[i];
        cin >> x >> r;
        j=i;
        ++mp[x+r];
        ++mp[x-r];
        g[x+r].pb(i);
        g[x-r].pb(i);
    }
    // そのウサギしか行けない座標があるのなら、それを採用
    int ans=0;
    // どっちも複数のウサギがいける座標
    // 複数のウサギのループだけを集めれば、
    // その座標って、全部コンプリート可能では？
    v<bool> done(n,0);
    queue<int> q;
    rep(i,n) {
        auto[x,r,j]=p[i];
        if (mp[x+r]==1 || mp[x-r]==1) {
            ++ans;
            done[i]=1;
            --mp[x+r];
            --mp[x-r];
            if (mp[x+r]==1) {
                for (int nxt:g[x+r]) {
                    if (!done[nxt]) q.push(nxt);
                }
            }
            if (mp[x-r]==1) {
                for (int nxt:g[x-r]) {
                    if (!done[nxt]) q.push(nxt);
                }
            }
        }
    }
    while (!q.empty()) {
        int pos=q.front();
        q.pop();
        auto[x,r,j]=p[pos];
        if (mp[x+r]==1 || mp[x-r]==1) {
            ++ans;
            done[pos]=1;
            --mp[x+r];
            --mp[x-r];
            if (mp[x+r]==1) {
                for (int nxt:g[x+r]) {
                    if (!done[nxt]) q.push(nxt);
                }
            }
            if (mp[x-r]==1) {
                for (int nxt:g[x-r]) {
                    if (!done[nxt]) q.push(nxt);
                }
            }
        }
    }
    unordered_map<int,int> cnt;
    rep(i,n) {
        if (!done[i]) {
            auto[x,r,j]=p[i];
            ++cnt[x+r];
            ++cnt[x-r];
        }
    }
    print(ans+cnt.size());

    return 0;
}
