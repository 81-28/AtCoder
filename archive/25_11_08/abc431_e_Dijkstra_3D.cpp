// https://atcoder.jp/contests/abc431/tasks/abc431_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
const pii dir[4]={{-1,0},{0,-1},{1,0},{0,1}};
#define rep(i,n) for(int i=0;i<(int)(n);++i)
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


bool in(const pii& pos,const pii& grid) {
    if (pos.f<0 || grid.f<=pos.f || pos.s<0 || grid.s<=pos.s) return 0;
    return 1;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int h,w;
        cin >> h >> w;
        v<string> st(h);
        cin >> st;
        // d[i][j][k]:位置i,j方向k(上左下右)でいるのに最小の操作回数
        v<vvi> d(h,vvi(w,vi(4,h*w)));
        // {距離,{i,j},方向}
        priority_queue<tuple<int,pii,int>,v<tuple<int,pii,int>>,greater<>> q;
        // d[0][0][0]=(st[0][0]!='C');
        // q.push({d[0][0][0],{0,0},0});
        // d[0][0][2]=(st[0][0]!='B');
        // q.push({d[0][0][2],{0,0},2});
        // d[0][0][3]=(st[0][0]!='A');
        // q.push({d[0][0][3],{0,0},3});
        q.push({0,{0,-1},3});
        while (!q.empty()) {
            auto[dist,pos,di]=q.top();
            q.pop();
            auto[x,y]=pos+dir[di];
            if (!in({x,y},{h,w})) continue;
            if (pos.s!=-1 && dist>d[pos.f][pos.s][di]) continue;
            if (chmin(d[x][y][di],dist+(st[x][y]!='A'))) q.push({d[x][y][di],{x,y},di});
            if (di%2) {
                // 左右
                if (chmin(d[x][y][(di+3)%4],dist+(st[x][y]!='B'))) q.push({d[x][y][(di+3)%4],{x,y},(di+3)%4});
                if (chmin(d[x][y][(di+1)%4],dist+(st[x][y]!='C'))) q.push({d[x][y][(di+1)%4],{x,y},(di+1)%4});
            } else {
                // 上下
                if (chmin(d[x][y][(di+1)%4],dist+(st[x][y]!='B'))) q.push({d[x][y][(di+1)%4],{x,y},(di+1)%4});
                if (chmin(d[x][y][(di+3)%4],dist+(st[x][y]!='C'))) q.push({d[x][y][(di+3)%4],{x,y},(di+3)%4});
            }
        }
        print(d[h-1][w-1][3]);
    }

    return 0;
}
