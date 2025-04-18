// https://atcoder.jp/contests/abc399/tasks/abc399_e

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define substring(s,l,r) s.substr(l,r-l)
#define YesNo(x) puts(x?"Yes":"No")
// #define f first
// #define s second
using ll=long long;
using ull=unsigned long long;
using ld=long double;
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using vll=v<ll>;
using vvll=v<vll>;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
// using mint=modint1000000007;
// using mint=modint998244353;

// inもoutもAtCoderではvectorとpair組み合わせて使えない
template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){for(int i=0;i<(int)v.size();i++)os<<(i?" ":"")<<v[i];return os;}
template<typename F,typename S>
ostream &operator<<(ostream &os,const pair<F,S> &p){os<<p.first<<" "<<p.second;return os;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

template<typename T>
auto sum(const vector<T>& v){return accumulate(v.begin(),v.end(),T{});}

template<typename T>
T max(const vector<T>& v){return *max_element(v.begin(),v.end());}
template<typename T>
T min(const vector<T>& v){return *min_element(v.begin(),v.end());}


vi c;

// 自分の変換先が存在するか確かめる(ループがあるか探す)
int f(const int& n, const int& m) {
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n;
    string s,t;
    cin >> n >> s >> t;
    v<unordered_set<int>> set(26);
    int a,b;
    rep(i,n) {
        a = s[i]-'a';
        b = t[i]-'a';
        if (!(set[a].size()==0 || (set[a].size()==1 && set[a].find(b)!=set[a].end()))) {
            print(-1);
            return 0;
        }
        set[a].insert(b);
    }
    // c[i]:iがどの文字へと変わるか
    // vi c(26,-1);
    c = vi(26,-1);
    // ループに関わっているか
    vi r(26,0);
    int ans=0;
    rep(i,26) {
        if (set[i].size()==1) {
            c[i]=*set[i].begin();
        }
    }
    if (sum(r)==26) print(-1);
    else print(ans);

    return 0;
}
