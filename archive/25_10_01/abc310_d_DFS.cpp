// https://atcoder.jp/contests/abc310/tasks/abc310_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


int n,t;
// チーム数
int tms=1;
// b[i][j](i<j):人iと人jを一緒にしてはいけないかどうか
// t[i][j]:チームiに人jがいるかどうか
v<v<bool>> b,team;
// n番の人をどこかのチームに追加
int dfs(const int& now) {
    if (now==n) return tms==t;
    int res=0;
    rep(i,tms) {
        bool ok=1;
        rep(j,now) {
            if (team[i][j]&&b[j][now]) {
                ok=0;
                break;
            }
        }
        if (!ok) continue;
        team[i][now]=1;
        res+=dfs(now+1);
        team[i][now]=0;
    }
    if (tms<t) {
        team[tms][now]=1;
        ++tms;
        res+=dfs(now+1);
        --tms;
        team[tms][now]=0;
    }
    return res;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int m;
    cin >> n >> t >> m;
    b=v<v<bool>>(n,v<bool>(n,0));
    rep(i,m) {
        int x,y;
        cin >> x >> y;
        --x,--y;
        b[x][y]=1;
    }
    team=v<v<bool>>(t,v<bool>(n,0));
    // 0番は固定
    team[0][0]=1;
    print(dfs(1));

    return 0;
}
