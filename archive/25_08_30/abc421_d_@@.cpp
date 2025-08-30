// https://atcoder.jp/contests/abc421/tasks/abc421_d

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
// #define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define uniq(v) v.erase(unique(v.begin(),v.end()),v.end()); // sort後に使用する
#define substring(s,l,r) s.substr(l,r-l)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

// `double pow()`では大きい数の時に誤差が発生する オーバーフローに注意 剰余のときは`modint.pow()`で良い
int int_pow(int a,int b) {
    int res=1;
    while(b){if(b&1)res*=a;a*=a;b>>=1;}
    return res;
}
// `double log()`も同様に誤差が発生するので、`to_string(n).size()`が良い

#define f first
#define s second
// // pairの足し算
// template<typename F,typename S>
// pair<F,S> operator+(const pair<F,S>& a,const pair<F,S>& b){return{a.f+b.f,a.s+b.s};}
// pair同士の引き算
template<typename F,typename S> pair<F,S> operator-(const pair<F,S>& a,const pair<F,S>& b){return{a.f-b.f,a.s-b.s};}
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


void progress(pii& p,char c,int n) {
    if (c=='U') p.f-=n;
    if (c=='D') p.f+=n;
    if (c=='L') p.s-=n;
    if (c=='R') p.s+=n;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    pii a,b;
    int n,m,l;
    cin >> a >> b >> n >> m >> l;
    queue<pair<char,int>> qa,qb;
    rep(i,m) {
        pair<char,int> p;
        cin >> p;
        qa.push(p);
    }
    rep(i,l) {
        pair<char,int> p;
        cin >> p;
        qb.push(p);
    }
    int ans=0;
    // if (a==b) ++ans;
    while (!qa.empty() && !qb.empty()) {
        auto[c,i]=qa.front();
        auto[t,j]=qb.front();
        pii na=a,nb=b;
        int d;
        if (i==j) {
            qa.pop(),qb.pop();
            d=i;
            progress(na,c,d);
            progress(nb,t,d);
        }
        if (i>j) {
            qb.pop();
            qa.front()={c,i-j};
            d=j;
            progress(na,c,d);
            progress(nb,t,d);
        }
        if (i<j) {
            qa.pop();
            qb.front()={t,j-i};
            d=i;
            progress(na,c,d);
            progress(nb,t,d);
        }
        if (a==b) {
            if (c==t) ans+=d;
        } else {
            if (c!=t) {
                if (c=='U' && t=='D') {
                    if (a.s==b.s && a.f>b.f) {
                        int dif=a.f-b.f;
                        if (dif%2==0) ++ans;
                    }
                } else if (c=='D' && t=='U') {
                    if (a.s==b.s && a.f<b.f) {
                        int dif=b.f-a.f;
                        if (dif%2==0) ++ans;
                    }
                } else if (c=='L' && t=='R') {
                    if (a.f==b.f && a.s>b.s) {
                        int dif=a.s-b.s;
                        if (dif%2==0) ++ans;
                    }
                } else if (c=='R' && t=='L') {
                    if (a.f==b.f && a.s<b.s) {
                        int dif=b.s-a.s;
                        if (dif%2==0) ++ans;
                    }
                } else {
                    pii mid;
                    if (a.f==na.f && b.s==nb.s) mid={a.f,b.s};
                    if (a.s==na.s && b.f==nb.f) mid={b.f,a.s};
                    pii ma=mid-a;
                    pii mb=mid-b;
                    int da=abs(ma.f)+abs(ma.s);
                    int db=abs(mb.f)+abs(mb.s);
                    pii pa=na-a;
                    pii pb=nb-b;
                    if (da==db && da<=d) {
                        if (((ma.f>=0 && pa.f>=0) || (ma.f<=0 && pa.f<=0)) && ((ma.s>=0 && pa.s>=0) || (ma.s<=0 && pa.s<=0))) {
                            if (((mb.f>=0 && pb.f>=0) || (mb.f<=0 && pb.f<=0)) && ((mb.s>=0 && pb.s>=0) || (mb.s<=0 && pb.s<=0))) ++ans;
                        }
                    }
                }
            }
        }
        a=na,b=nb;
    }
    print(ans);

    return 0;
}
