// https://atcoder.jp/contests/abc394/tasks/abc394_f

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back
#define rall(v) v.rbegin(),v.rend()
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

#define f first
#define s second

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


vvi g;
// a:全体で訪問済みか,b:現在訪問済みか
v<bool> a,b;
// {nから最も遠い(最大頂点となる部分木に含まれる)頂点,
// 次数4以上の頂点で構成された木において、葉nを含む最大頂点数}
pii dfs(const int& n) {
    a[n]=b[n]=1;
    if (g[n].size()<4) return {n,-1};
    int e=n,dist=0;
    vi d;
    for (int nxt:g[n]) {
        if (b[nxt]) continue;
        pii p=dfs(nxt);
        if (chmax(dist,p.s)) e=p.f;
        d.pb(p.s);
    }
    sort(rall(d));
    int m=d.size();
    int l=min(3,m);
    int sm=1;
    for (int i=0; i<l && d[i]!=-1; ++i) sm+=d[i];
    return {e,sm};
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    g=vvi(n+1);
    rep1(i,n-1) {
        pii p;
        cin >> p;
        g[p.f].pb(p.s);
        g[p.s].pb(p.f);
    }
    a=v<bool>(n+1,0),b=a;
    int ans=-1;
    // 次数4以上の頂点で構成された部分木において、五叉路以上を含まない部分木の最大頂点数
    // 頂点の子に次数4以上の頂点が5つ以上あっても、4つまでしか採用できない
    // 次数4以上を安易につなげるだけでは最大は求まらない
    rep1(i,n) {
        if (a[i]) continue;
        pii p=dfs(i);
        b=v<bool>(n+1,0);
        pii q=dfs(p.f);
        chmax(ans,q.s);
    }
    print(ans*3+2);

    return 0;
}
