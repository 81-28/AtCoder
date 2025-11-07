// https://atcoder.jp/contests/abc311/tasks/abc311_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
const pii dir[4]={{-1,0},{0,-1},{1,0},{0,1}};
#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define f first
#define s second
// pairの足し算
template<typename F,typename S>
pair<F,S> operator+(const pair<F,S>& a,const pair<F,S>& b){return{a.f+b.f,a.s+b.s};}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


bool can(const v<bool> vec) {
    for (bool b:vec) {
        if (b) return 1;
    }
    return 0;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    v<string> st(n);
    cin >> st;
    // b[i][j][k]:位置i,jで方向kで存在できるか
    v<v<v<bool>>> b(n,v<v<bool>>(m,v<bool>(5,0)));
    // {x,y,方向}
    // 方向:上,左,下,右,停止
    queue<tuple<int,int,int>> q;
    q.push({1,1,4});
    while (!q.empty()) {
        auto[x,y,d]=q.front();
        q.pop();
        if (b[x][y][d]) continue;
        b[x][y][d]=1;

        pii pos={x,y};
        if (d==4) {
            rep(k,4) {
                auto[i,j]=pos+dir[k];
                if (st[i][j]!='#') q.push({i,j,k});
            }
        } else {
            auto[i,j]=pos+dir[d];
            if (st[i][j]=='#') q.push({x,y,4});
            else q.push({i,j,d});
        }
    }
    int ans=0;
    rep(i,n)rep(j,m) ans+=can(b[i][j]);
    print(ans);

    return 0;
}
