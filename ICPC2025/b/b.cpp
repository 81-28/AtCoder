// 

// Ctrl + Shift + B                => Build
// Terminal : "./a.out"            => Run
// Terminal : "./a.out < ./in.txt" => Run

#include<bits/stdc++.h>
using namespace std;
// #include<atcoder/all>
// using namespace atcoder;

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
// #define f first
// #define s second

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

    while (1) {
        int n;
        cin >> n;
        if (n==0) return 0;
        string s;
        cin >> s;
        // i文字重なる
        for (int i=n-1; i>=0; --i) {
            bool ok=1;
            rep(j,i) {
                if (s[j]!=s[n-i+j]) {
                    ok=0;
                    break;
                }
            }
            if (ok) {
                cout<<s;
                for (int j=i; j<n; ++j) {
                    cout<<s[j];
                }
                cout<<endl;
                break;
            }
        }
    }

    return 0;
}
