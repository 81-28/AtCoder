// https://atcoder.jp/contests/abc446/tasks/abc446_f

#include<bits/stdc++.h>
using namespace std;
// #include<atcoder/all>
// using namespace atcoder;

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

template<typename T>
auto sum(const v<T>& v){return accumulate(v.begin(),v.end(),T{});}
template<typename T>
T max(const v<T>& v){return *max_element(v.begin(),v.end());}
template<typename T>
T min(const v<T>& v){return *min_element(v.begin(),v.end());}

// 区間のクエリが必要ならセグ木使う
// 値の範囲が大きい→座標圧縮で解けないかを考える


class UnionFind {
public:
    // par: 親, siz: サイズ
    vector<int> par,siz;
    // n頂点のUnion-Find
    UnionFind(const int& n) {
        par = vector<int>(n,-1);
        siz = vector<int>(n,1);
        // 1-indexedならこの部分だけ変更でよい
        // par = vector<int>(n+1,-1);
        // siz = vector<int>(n+1,1);
    }

    // 頂点xの根を返す関数
    int root(const int& x) {
        if (par[x] == -1) return x; // 親が無いとき、それが根
        else return par[x] = root(par[x]); // 経路圧縮して親に移動
    }

    // 頂点uとvを繋げる関数(sizが大きい方に根を統合)
    // 返り値はsameと同じ
    bool unite(const int& u, const int& v) {
        int rootU = root(u);
        int rootV = root(v);
        if (rootU == rootV) return 1;
        if (siz[rootU] < siz[rootV]) {
            par[rootU] = rootV;
            siz[rootV] += siz[rootU];
        } else {
            par[rootV] = rootU;
            siz[rootU] += siz[rootV];
        }
        return 0;
    }

    // 頂点uとvが同じグループにあるか(同じ根を持つか)を返す関数
    bool same(const int& u, const int& v) {
        return root(u) == root(v);
    }

    // 頂点xが含まれる連結成分の大きさ
    int size(const int& x) {
        return siz[root(x)];
    }
};


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    // UnionFind uf(n);
    v<pii> p(m);
    // {子の頂点,本数}
    v<map<int,int>> chi(n);
    // {親の頂点,本数}
    v<map<int,int>> par(n);
    for (auto&[a,b]:p) {
        cin >> a >> b;
        --a,--b;
        // uf.unite(a,b);
        if (a==b) continue;
        ++chi[a][b];
        ++par[b][a];
    }
    UnionFind uf2(n);
    set<int> st;
    set<int> ng;
    rep(i,n) {
        for (auto[num,cnt]:par[i]) {
            if (num>i) continue;
            if (uf2.same(0,num)) uf2.unite(i,num);
        }
        bool ok=1;
        if (!uf2.same(0,i)) {
            ok=0;
        }
        for (auto[num,cnt]:chi[i]) {
            if (num>i) continue;
            uf2.unite(i,num);
        }
        for (auto it=ng.begin(); it!=ng.end();) {
            if (uf2.same(0,*it)) {
                it=ng.erase(it);
            } else ++it;
        }
        if (!ok) ng.insert(i);
        for (auto[num,cnt]:chi[i]) {
            if (num<i) continue;
            st.insert(num);
        }
        if (st.find(i)!=st.end()) st.erase(i);
        if (ng.size()) {
            print(-1);
        } else print(st.size());
    }


    return 0;
}
