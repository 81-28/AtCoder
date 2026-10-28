// https://atcoder.jp/contests/abc151/tasks/abc151_d

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
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

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

    int h,w;
    cin >> h >> w;
    v<string> t(h);
    cin >> t;
    int ans=0;
    rep(i,h)rep(j,w) {
        if (t[i][j]=='#') continue;
        vvi d(h,vi(w,-1));
        queue<pii> q;
        d[i][j]=0;
        q.push({i,j});
        while (!q.empty()) {
            pii p=q.front();
            q.pop();
            auto[x,y]=p;
            rep(k,4) {
                pii nxt=p+dir[k];
                if (OutOfGrid(nxt,{h,w})) continue;
                auto[nx,ny]=nxt;
                if (t[nx][ny]=='#') continue;
                if (d[nx][ny]!=-1) continue;
                chmax(ans,d[nx][ny]=d[x][y]+1);
                q.push(nxt);
            }
        }
    }
    print(ans);

    return 0;
}
