// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ei

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;

template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){for(int i=(int)v.size()-1;i>=0;i--)os<<v[i]<<(i?" ":"");return os;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


vvi g;
v<bool> vis;
vi root;

void dfs(const int& pos) {
    vis[pos]=1;
    rep(i,g[pos].size()) {
        int next=g[pos][i];
        if (!vis[next]) {
            dfs(next);
            root[next] = pos;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    g=vvi(n+1);
    int a,b;
    rep(i,m) {
        cin >> a >>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    vis=v<bool>(n+1,0);
    root=vi(n+1);
    dfs(1);

    vi ans;
    for (int p=n;p!=1;p=root[p]) ans.pb(p);
    ans.pb(1);
    print(ans);

    return 0;
}
