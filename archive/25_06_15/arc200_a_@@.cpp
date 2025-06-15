// https://atcoder.jp/contests/arc200/tasks/arc200_a

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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi a(n),b(n);
        cin >> a >> b;
        // {差,i}
        set<pair<ld,int>> sa,sb;
        rep(i,n) {
            // int dif=a[i]-b[i];
            ld bi=(ld)a[i]/b[i];
            if (bi>1) sa.insert({bi,i});
            if (bi<1) sb.insert({1/bi,i});
        }
        int an=sa.size(),bn=sb.size();
        vi x(n,0);
        if ((an<1 && bn<2) || (an<2 && bn<1)) {
            print("No");
        } else {
            if (an>0 && bn>0) {
                auto ita=sa.rbegin(),itb=sb.rbegin();
                auto da=(*ita).f,db=(*itb).f;
                if (da==db) {
                    while (ita!=sa.rend() && da==(*ita).f) ++ita;
                    while (itb!=sb.rend() && db==(*itb).f) ++itb;
                }
                if (ita==sa.rend() && itb==sb.rend()) {
                    print("No");
                } else {
                    if (ita==sa.rend()) {
                        ita=sa.rbegin();
                    } else {
                        itb=sb.rbegin();
                    }
                    x[(*ita).s]=a[(*itb).s];
                    x[(*itb).s]=-b[(*ita).s];
                    print("Yes");
                    print(x);
                }
            } else {
                if (an==0) {
                    auto itb=sb.rbegin(),itb2=sb.rbegin();
                    while (itb2!=sb.rend() && (*itb).f==(*itb2).f) ++itb2;
                    if (itb2==sb.rend()) {
                        print("No");
                    } else {
                        int e8=1e8;
                        int bi1=e8/a[(*itb).s],bi2=e8/a[(*itb2).s];
                        int bi=min(bi1,bi2)-1;
                        x[(*itb).s]=-a[(*itb2).s]*bi;
                        x[(*itb2).s]=a[(*itb).s]*bi+1;
                        print("Yes");
                        print(x);
                    }
                } else {
                    auto ita=sa.rbegin(),ita2=sa.rbegin();
                    while (ita2!=sa.rend() && (*ita).f==(*ita2).f) ++ita2;
                    if (ita2==sa.rend()) {
                        print("No");
                    } else {
                        int e8=1e8;
                        int bi1=e8/b[(*ita).s],bi2=e8/b[(*ita2).s];
                        int bi=min(bi1,bi2)-1;
                        x[(*ita).s]=b[(*ita2).s]*bi;
                        x[(*ita2).s]=-b[(*ita).s]*bi+1;
                        print("Yes");
                        print(x);
                    }
                }
            }
        }
    }

    return 0;
}
