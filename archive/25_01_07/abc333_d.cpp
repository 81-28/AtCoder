// https://atcoder.jp/contests/abc333/tasks/abc333_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


vvi g;

int cost(const int& n, const int& root) {
    int s=0;
    for(int i:g[n]) {
        if(i!=root) s += cost(i,n);
    }
    return s+1;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    g = vvi(n);
    int u,v;
    rep(i,n-1) {
        cin >> u >> v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    if(g[0].size()==1) print(1);
    else {
        int c,s=0,m=0;
        for(int i:g[0]) {
            c = cost(i,0);
            s += c;
            m = max(m,c);
        }
        print(s-m+1);
    }

    return 0;
}
