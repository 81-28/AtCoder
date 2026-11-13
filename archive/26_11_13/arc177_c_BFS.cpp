// https://atcoder.jp/contests/arc177/tasks/arc177_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
const pii dir[4]={{-1,0},{0,-1},{1,0},{0,1}};
inline bool OutOfGrid(const pii& p,const pii& rng){return p.first<0||rng.first<=p.first||p.second<0||rng.second<=p.second;}
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

#define f first
#define s second
// pairの足し算
template<typename F,typename S>
pair<F,S> operator+(const pair<F,S>& a,const pair<F,S>& b){return{a.f+b.f,a.s+b.s};}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<string> t(n);
    cin >> t;
    v<pii> st={{0,0},{0,n-1}};
    string str="RB";
    int ans=0;
    rep(i,2) {
        vvi d(n,vi(n,n*2));
        deque<pii> q;
        d[st[i].f][st[i].s]=0;
        q.pb(st[i]);
        while (!q.empty()) {
            pii p=q.front();
            q.pop_front();
            int dist=d[p.f][p.s];
            rep(k,4) {
                auto[x,y]=p+dir[k];
                if (OutOfGrid({x,y},{n,n})) continue;
                if (t[x][y]==str[i]) {
                    if (chmin(d[x][y],dist)) q.push_front({x,y});
                } else {
                    if (chmin(d[x][y],dist+1)) q.pb({x,y});
                }
            }
        }
        ans+=d[n-1-st[i].f][n-1-st[i].s];
    }
    print(ans);

    return 0;
}
