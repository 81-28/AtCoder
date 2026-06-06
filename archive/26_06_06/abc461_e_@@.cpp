// https://atcoder.jp/contests/abc461/tasks/abc461_e

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


using S=int;
S op(S a,S b){return S(a+b);}
S e(){return S();}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;

    vi mx(2,n);
    vvi pos(2,vi(n));
    vector mp(2,map<int,int>());
    rep(i,n) {
        pos[0][i]=pos[1][i]=i;
        mp[0][i]=mp[1][i]=i;
    }
    vvi cnt(2,vi(n,0));

    v<S> init(n*2,0);
    rep(i,n) init[i]=1;
    vector t(2,segtree<S,op,e>(init));

    int ans=0;
    while (q--) {
        int m,x;
        cin >> m >> x;
        --m,--x;

        if (m) {
            ans-=cnt[m][x];
            cnt[m][x]=0;
        } else {
            ans+=n-cnt[m][x];
            cnt[m][x]=n;
        }

        // [l,r)
        int l=0,r=n*2+1;
        while (l+1<r) {
            int mid=(l+r)/2;
            int res=t[m].prod(0,mid);
            if (res>x) r=mid;
            else l=mid;
        }
    }


    return 0;
}
