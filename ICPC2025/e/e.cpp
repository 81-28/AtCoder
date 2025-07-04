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

// グラフ
v<map<int,bool>> g;
// 辺の制限時間
v<map<int,int>> t;
vi d;
// {制限時間,ルート}
priority_queue<pair<int,vi>,v<pair<int,vi>>,greater<>> q;
void dfs(const int& n,vi vec) {
    for (auto [nxt,b]:g[n]) {
        if (d[nxt]==-1) {
            vi vecc=vec;
            vecc.pb(nxt);
            d[nxt]=vecc.size();
            q.push({t[n][nxt],vecc});
            dfs(nxt,vecc);
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    while (1) {
        int n;
        cin >> n;
        if (n==0) return 0;
        g=v<map<int,bool>>(n+1,map<int,bool>());
        t=v<map<int,int>>(n+1,map<int,int>());
        for (int i=2; i<=n; ++i) {
            int p,e;
            cin >> p >> e;
            g[i][p]=1;
            g[p][i]=1;
            t[i][p]=e;
            t[p][i]=e;
        }
        d=vi(n+1,-1);
        d[1]=0;
        v<bool> visited(n+1,0);
        visited[1]=1;
        q=priority_queue<pair<int,vi>,v<pair<int,vi>>,greater<>>();
        dfs(1,{});
        
        // while (!q.empty()) {
        //     auto a=q.top();
        //     q.pop();
        //     print(a.f,"",a.s);
        // }
        
        
        bool ok=1;
        vi ans;
        int time=0;
        while (!q.empty()) {
            auto [limit,vec]=q.top();
            q.pop();
            int to=*vec.rbegin();
            if (visited[to]) continue;
            int last=1;
            for (int nxt:vec) {
                if (!visited[nxt]) {
                    if (time > t[last][nxt]) {
                        ok=0;
                        break;
                    }
                    ++time;
                    visited[nxt]=1;
                    ans.pb(nxt);
                }
                last=nxt;
            }
            if (!ok) break;
        }
        if (ok) {
            print("yes");
            print(ans);
        } else {
            print("no");
        }
        
    }
    

    return 0;
}
