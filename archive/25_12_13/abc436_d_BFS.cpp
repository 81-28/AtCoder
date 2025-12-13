// https://atcoder.jp/contests/abc436/tasks/abc436_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
const pii dir[4]={{-1,0},{0,-1},{1,0},{0,1}};
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
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w;
    cin >> h >> w;
    v<string> st(h);
    cin >> st;
    v<v<pii>> c(26);
    v<bool> cc(26,0);
    rep(i,h)rep(j,w) {
        if ('a'<=st[i][j] && st[i][j]<='z') c[st[i][j]-'a'].pb({i,j});
    }
    vvi d(h,vi(w,INT_MAX));
    queue<pii> q;
    d[0][0]=0;
    q.push({0,0});
    while (!q.empty()) {
        pii pos=q.front();
        q.pop();
        auto[i,j]=pos;
        int dist=d[pos.f][pos.s];
        rep(k,4) {
            auto[x,y]=pos+dir[k];
            if (x<0||h<=x || y<0||w<=y) continue;
            if (st[x][y]=='#') continue;
            if (chmin(d[x][y],dist+1)) q.push({x,y});
        }
        if ('a'<=st[i][j] && st[i][j]<='z') {
            if (cc[st[i][j]-'a']) continue;
            for (auto[x,y]:c[st[i][j]-'a']) {
                if (chmin(d[x][y],dist+1)) q.push({x,y});
            }
            cc[st[i][j]-'a']=1;
        }
    }
    print(d[h-1][w-1]==INT_MAX?-1:d[h-1][w-1]);

    return 0;
}
