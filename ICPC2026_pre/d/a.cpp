// 

// Ctrl + Shift + B                => Build
// Terminal : "./a.out"            => Run
// Terminal : "./a.out < ./in.txt" => Run

#include<bits/stdc++.h>
using namespace std;
// #include<atcoder/all>
// using namespace atcoder;

using ll=long long;
// #define int ll
// #define int short
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
# pragma GCC target("avx2")
# pragma GCC optimize("O3")
# pragma GCC optimize("unroll-loops")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    for(;;) {
        int n;
        cin >> n;
        if (!n) return 0;
        vector a(n,v<short>(6));
        cin >> a;

        int ans=0;
        vector d(1,v<v<short>>(0));

        rep(pos,n) {
            int l=d.size();
            rep(k,l) {
                auto vec=d[k];
                rep(i,6) {
                    v<short> now(4);
                    now[0]=a[pos][i];
                    now[2]=a[pos][(i/2)*4+1-i];
                    rep(j,6) {
                        // if (!vec.size() && (j&1)) continue;
                        if (i/2==j/2) continue;
                        now[1]=a[pos][j];
                        now[3]=a[pos][(j/2)*4+1-j];
                        vec.pb(now);
                        d.pb(vec);
                        vec.pop_back();
                    }
                }
            }
        }

        for (auto vec:d) {
            v<short> mx(4,0),mi(4,n*7);
            for (auto ve:vec) {
                rep(i,4) {
                    chmax(mx[i],ve[i]);
                    chmin(mi[i],ve[i]);
                }
            }
            v<pii> p(4);
            rep(i,4) p[i]={mi[i],mx[i]};
            sort(all(p));
            bool ok=1;
            rep(i,3) {
                if (p[i].s>=p[i+1].f) {
                    ok=0;
                    break;
                }
            }
            if (ok) chmax(ans,(int)vec.size());
            // print(ok,vec.size());
            // rep(i,4) print(p[i]);
            // print();
        }
        print(ans);
        // print();
    }


    return 0;
}
