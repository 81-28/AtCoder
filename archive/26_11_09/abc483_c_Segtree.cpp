// https://atcoder.jp/contests/abc483/tasks/abc483_c

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

template<typename T>
using v=vector<T>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


// {票数,番号}
struct S{
    int c,i;
    S(int x,int y) {c=x,i=y;}
    S(){c=-1,i=-1;}
};
S op(S a,S b) {
    if (a.c==b.c) return a.i<b.i?a:b;
    return a.c>b.c?a:b;
}
S ad(S a,int x) {
    a.c+=x;
    return a;
}
S e(){return S();}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    v<S> init(n);
    rep(i,n) init[i]={0,i};
    // g[i][j]:1希望がiで2希望がjの票数
    v<unordered_map<int,int>> g(n);
    while (m--) {
        int a,b;
        cin >> a >> b;
        ++g[--a][--b];
        ++init[a].c;
    }
    segtree<S,op,e> t(init);
    rep(i,n) {
        S tmp=t.get(i);
        t.set(i,{0,i});
        for (auto[j,cnt]:g[i]) t.set(j,ad(t.get(j),cnt));
        print(t.all_prod().i+1);
        for (auto[j,cnt]:g[i]) t.set(j,ad(t.get(j),-cnt));
        t.set(i,tmp);
    }

    return 0;
}
