// https://atcoder.jp/contests/abc387/tasks/abc387_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n+1);i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define substring(s,l,r) s.substr(l,r-l)
#define f first
#define s second
#define YesNo(x) cout<<(x?"Yes\n":"No\n")
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

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
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
// #define max(...) (*max_element({__VA_ARGS__}))
// #define min(...) (*min_element({__VA_ARGS__}))


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w;
    cin >> h >> w;
    v<string> t(h);
    cin >> t;
    pii st,go;
    vvi d(h,vi(w,0));
    vvi dist(h,vi(w,-1));
    rep(i,h) rep(j,w) {
        if (t[i][j]=='S') st = {i,j};
        if (t[i][j]=='G') go = {i,j};
        if (t[i][j]=='#') d[i][j] = 1;
    }
    queue<pii> q;
    q.push(st);
    d[st.f][st.s] = 1;
    dist[st.f][st.s] = 0;
    while (!q.empty()) {
        pii p = q.front();
        q.pop();
        if (p==go) {
            print(dist[p.f][p.s]);
            return 0;
        }
        
        int nowdist = dist[p.f][p.s];
        if (p.f-1 >= 0 && !d[p.f-1][p.s]) {
            dist[p.f-1][p.s] = nowdist+1;
            d[p.f-1][p.s] = 1;
            q.push({p.f-1,p.s});
        }
        if (p.f+1 <h && !d[p.f+1][p.s]) {
            dist[p.f+1][p.s] = nowdist+1;
            d[p.f+1][p.s] = 1;
            q.push({p.f+1,p.s});
        }
        if (p.s-1 >= 0 && !d[p.f][p.s-1]) {
            dist[p.f][p.s-1] = nowdist+1;
            d[p.f][p.s-1] = 1;
            q.push({p.f,p.s-1});
        }
        if (p.s+1 < w && !d[p.f][p.s+1]) {
            dist[p.f][p.s+1] = nowdist+1;
            d[p.f][p.s+1] = 1;
            q.push({p.f,p.s+1});
        }
    }
    print(-1);


    return 0;
}
