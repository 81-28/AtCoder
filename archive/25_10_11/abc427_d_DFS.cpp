// https://atcoder.jp/contests/abc427/tasks/abc427_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


string st;
vvi g;
// 保存
map<tuple<int,int,bool>,bool> mp;
// 位置posで残りn手でbが勝てるかどうか
// b: 0:先手,1:後手
bool dfs(const int& pos,const int& n,const bool& b) {
    if (mp.find({pos,n,b})!=mp.end()) return mp[{pos,n,b}];
    if (!n) return mp[{pos,n,b}]=(st[pos]==(!b?'A':'B'));
    bool ok=0;
    for (int nxt:g[pos]) {
        if (!dfs(nxt,n-1,!b)) {
            ok=1;
            break;
        }
    }
    return mp[{pos,n,b}]=ok;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n,m,k;
        cin >> n >> m >> k >> st;
        g=vvi(n);
        rep(i,m) {
            int a,b;
            cin >> a >> b;
            --a,--b;
            g[a].pb(b);
        }
        mp=map<tuple<int,int,bool>,bool>();
        print(dfs(0,k*2,0)?"Alice":"Bob");
    }

    return 0;
}
