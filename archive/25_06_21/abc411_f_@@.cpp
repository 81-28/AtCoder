// https://atcoder.jp/contests/abc411/tasks/abc411_f

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
// using mint=modint1000000007;
// using mint=modint998244353;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define substring(s,l,r) s.substr(l,r-l)
template<class T>constexpr bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T>constexpr bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
#define YesNo(x) puts(x?"Yes":"No")
#define f first
#define s second

// inもoutもAtCoderではvectorとpair組み合わせて使えない
template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename T>
ostream &operator<<(ostream &os,const v<T> &v){for(int i=0;i<(int)v.size();++i)os<<(i?" ":"")<<v[i];return os;}
template<typename F,typename S>
ostream &operator<<(ostream &os,const pair<F,S> &p){os<<p.first<<' '<<p.second;return os;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

// // pairの足し算
// template<typename F,typename S>
// pair<F,S> operator+(const pair<F,S>& a,const pair<F,S>& b){return{a.f+b.f,a.s+b.s};}
// pairのデクリメント
template<typename F,typename S>
pair<F,S>& operator--(pair<F,S>& p){--p.f;--p.s;return p;}
// // pairと定数の掛け算
// template<typename F,typename S,typename T>
// pair<F,S> operator*(const pair<F,S>& p,const T& a){return{p.f*a,p.s*a};}
// // 定数とpairの掛け算
// template<typename F,typename S,typename T>
// pair<F,S> operator*(const T& a,const pair<F,S>& p){return{a*p.f,a*p.s};}

// セグ木使おう
template<typename T>
auto sum(const v<T>& v){return accumulate(v.begin(),v.end(),T{});}
template<typename T>
T max(const v<T>& v){return *max_element(v.begin(),v.end());}
template<typename T>
T min(const v<T>& v){return *min_element(v.begin(),v.end());}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vi pos(n+1);
    rep1(i,n) pos[i]=i;
    v<set<int>> g(n+1);
    v<pii> p(m);
    rep(i,m) {
        cin >> p[i];
        g[p[i].f].insert(p[i].s);
        g[p[i].s].insert(p[i].f);
    }
    int ans=m;
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        --x;
        if (pos[p[x].f]!=pos[p[x].s]) {
            for (int val:g[pos[p[x].s]]) {
                auto it=g[pos[p[x].f]].find(val);
                if (it!=g[pos[p[x].f]].end()) --ans;
                else g[pos[p[x].f]].insert(val);
                it=g[val].find(pos[p[x].s]);
                if (it!=g[val].end()) g[val].erase(it);
            }
            auto it=g[pos[p[x].f]].find(pos[p[x].f]);
            if (it!=g[pos[p[x].f]].end()) {
                g[pos[p[x].f]].erase(it);
            }
            it=g[pos[p[x].f]].find(pos[p[x].s]);
            if (it!=g[pos[p[x].f]].end()) {
                g[pos[p[x].f]].erase(it);
            }
            --ans;
            pos[p[x].s]=pos[p[x].f];
        }
        print(ans);
    }

    return 0;
}
