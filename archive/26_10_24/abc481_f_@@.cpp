// https://atcoder.jp/contests/abc481/tasks/abc481_f

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

using ll=long long;
#define int ll
using ull=unsigned long long;
using ld=long double;
constexpr int INF=numeric_limits<int>::max()/4;
const ld PI=acos(-1);
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using vb=v<bool>;
using vvb=v<vb>;
using pii=pair<int,int>;
const pii dir[4]={{-1,0},{0,-1},{1,0},{0,1}};
// const pii dir[8]={{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
inline bool OutOfGrid(const pii& p,const pii& rng){return p.first<0||rng.first<=p.first||p.second<0||rng.second<=p.second;}
inline int ManhattanDist(const pii& a,const pii& b){return abs(a.first-b.first)+abs(a.second-b.second);}
using mint=modint998244353;
// using mint=modint1000000007;
// using mint=modint;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n-1);i>=0;--i)
#define rrep1(i,n) for(int i=(int)(n);i>0;--i)
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
#define endl '\n' // flushしたい場合は無効化
void print(){cout<<endl;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")

template<typename T>
auto sum(const v<T>& v){return accumulate(v.begin(),v.end(),T{});}
template<typename T>
T max(const v<T>& v){return *max_element(v.begin(),v.end());}
template<typename T>
T min(const v<T>& v){return *min_element(v.begin(),v.end());}

// 区間のクエリが必要ならセグ木使う
// 値の範囲が大きい→座標圧縮で解けないかを考える

void solve() {
}

v<v<pii>> gg;
v<mint> ans;
vb bb;
// void dfs(int pos) {
//     sort(all(gg[pos]));
//     for (auto[c,nxt]:gg[pos]) {
//         if (bb[nxt]) continue;
//         bb[nxt]=1;
//         ans[nxt]=ans[pos]*10+c;
//         dfs(nxt);
//     }
// }

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    v<tuple<int,int,int>> t(m);
    v<v<pii>> g(n);
    // 距離が違うなら、近い方が、桁が小さくなる
    // 距離が同じ場合、そこまでで最小を採用
    for (auto&[a,b,c]:t) {
        cin >> a >> b >> c;
        g[--a].pb({--b,c});
    }

    // 距離が同じなら、最後の追加する数が小さい方を優先すれば、そっちが先に到着するのでは？
    // 分岐から近い、数が違うポイントでの大小が優先される
    // 最初に最短距離のみのグラフを作って、後から数優先のDFS?
    // 違ったら、小さい方を最後まで掘るけど、
    // 同じなら同時に掘らなきゃダメ
    // 分岐していても、そこまでが同じなら、同時に掘らなくてはいけない

    vi d(n,INF);
    priority_queue<pii,v<pii>,greater<>> q;
    d[0]=0;
    q.push({d[0],0});
    while (!q.empty()) {
        auto[dist,pos]=q.top();
        q.pop();
        if (d[pos]<dist) continue;
        for (auto[nxt,c]:g[pos]) {
            if (chmin(d[nxt],dist+1)) q.push({d[nxt],nxt});
        }
    }

    gg=v<v<pii>>(n);
    vvi depth(n);
    for (auto[a,b,c]:t) {
        if (d[a]+1!=d[b]) continue;
        gg[a].pb({c,b});
    }
    ans=v<mint>(n);
    ans[0]=0;
    bb=vb(n,0);
    // dfs(0);
    stack<tuple<int,int,int>> qq;
    // priority_queue<tuple<int,int,int>,v<tuple<int,int,int>>,greater<>> qq;
    qq.push({0,0,0});
    while (!qq.empty()) {
        auto[cc,pos,par]=qq.top();
        qq.pop();
        if (bb[pos]) continue;
        bb[pos]=1;
        ans[pos]=ans[par]*10+cc;
        sort(rall(gg[pos]));
        for (auto[c,nxt]:gg[pos]) {
            // print(pos,c,nxt);
            qq.push({c,nxt,pos});
        }
    }
    rep1(i,n-1) print(ans[i].val());

    return 0;
}
