// https://atcoder.jp/contests/abc410/tasks/abc410_e

#include<bits/stdc++.h>
using namespace std;
#define int ll

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define substring(s,l,r) s.substr(l,r-l)
template<class T> constexpr bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> constexpr bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
#define YesNo(x) puts(x?"Yes":"No")
#define f first
#define s second
using ll=long long;
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
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

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

// セグ木使おう
template<typename T>
auto sum(const v<T>& v){return accumulate(v.begin(),v.end(),T{});}
template<typename T>
T max(const v<T>& v){return *max_element(v.begin(),v.end());}
template<typename T>
T min(const v<T>& v){return *min_element(v.begin(),v.end());}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,h,m;
    cin >> n >> h >> m;
    // dp[i][j][k]:i体目で{h,m}={j,k}が可能かどうか
    // v<v<v<bool>>> dp(n+1,v<v<bool>>(h+1,v<bool>(m+1,0)));
    v<map<pii,bool>> dp(n+1);
    dp[0][{h,m}]=1;
    rep1(i,n) {
        pii p;
        cin >> p;
        bool ok=0;
        // rep(j,h+1)rep(k,m+1) {
        //     if (j+p.f<=h && dp[i-1][j+p.f][k]) {
        //         dp[i][j][k]=1;
        //         ok=1;
        //     }
        //     if (k+p.s<=m && dp[i-1][j][k+p.s]) {
        //         dp[i][j][k]=1;
        //         ok=1;
        //     }
        // }
        for (auto it=dp[i-1].rbegin();it!=dp[i-1].rend();++it) {
            auto pp=*it;
            int j,k;
            j=pp.f.f-p.f,k=pp.f.s;
            if (j>=0) {
                dp[i][{j,k}]=1;
                ok=1;
            }
            j=pp.f.f,k=pp.f.s-p.s;
            if (k>=0) {
                dp[i][{j,k}]=1;
                ok=1;
            }
        }
        if (!ok) {
            print(i-1);
            return 0;
        }
    }
    print(n);

    return 0;
}
