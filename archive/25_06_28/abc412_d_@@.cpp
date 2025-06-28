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
    v<map<int,bool>> g(n);
    map<pii,bool> mp;
    vi c(n,0);
    rep(i,m) {
        pii p;
        cin >> p;
        --p;
        g[p.f][p.s]=1;
        g[p.s][p.f]=1;
        ++c[p.f],++c[p.s];
        pii pp={p.s,p.f};
        if (p.f<p.s) mp[p]=1;
        else mp[pp]=1;
    }
    int ans=0;
    int mx=max(c);
    while (mx>2) {
        int pos=0;
        rep(i,n) {
            if (c[i]==mx) {
                pos=i;
                break;
            }
        }
        // {c,i}
        v<pii> nxt;
        for (auto p:g[pos]) {
            if (p.s)  nxt.pb({c[p.f],p.f});
        }
        sort(rall(nxt));
        rep(i,mx-2) {
            ++ans;
            pii p1={nxt[i].s,pos},p2={pos,nxt[i].s};
            pii p=(nxt[i].s<pos)?p1:p2;
            g[p.f][p.s]=0;
            g[p.s][p.f]=0;
            --c[p.f],--c[p.s];
            mp[p]=0;
        }
        // int pos=0;
        // int mmx=-1;
        // rep(i,n) {
        //     if (chmax(mmx,c[i])) pos=i;
        // }
        // pii e;
        // int cnt=0;
        // for (auto [p,b]:mp) {
        //     if (b && (p.f==pos||p.s==pos)) {
        //         if (chmax(cnt,c[p.f+p.s-pos])) {
        //             e=p;
        //         }
        //     }
        // }
        // ++ans;
        // g[e.f][e.s]=0;
        // g[e.s][e.f]=0;
        // --c[e.f],--c[e.s];
        // mp[e]=0;
        mx=max(c);
    }
    // set<pii> cnt;
    // rep(i,n) {
    //     cnt.insert({c[i],i});
    // }
    // auto it=cnt.begin();
    // while ((*it).f<2) {
    //     ++ans;
    //     auto it2=cnt.begin();
    //     ++it2;
    //     if ((*it2).f>=2) {
    //         ans+=2;
    //         pii p={(*it).f+2,(*it).s};
    //         cnt.erase(it);
    //         cnt.insert(p);
    //     } else {
    //         pii p1={(*it).f+1,(*it).s},p2={(*it2).f+1,(*it2).s};
    //         cnt.erase(it),cnt.erase(it2);
    //         cnt.insert(p1),cnt.insert(p2);
    //     }
    //     it=cnt.begin();
    // }
    vi cnt(3,0);
    rep(i,n) ++cnt[c[i]];
    ans+=(cnt[1])/2;
    if (cnt[0] && cnt[0]<3) ans+=cnt[0]+2;
    else ans+=cnt[0];

    print(ans);

    return 0;
}
