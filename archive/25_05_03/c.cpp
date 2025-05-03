// https://atcoder.jp/contests/abc404/tasks/abc404_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define YesNo(x) puts(x?"Yes":"No")
#define f first
#define s second
template<typename T>
using v=vector<T>;
using pii=pair<int,int>;

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    if (n!=m) {
        YesNo(0);
        return 0;
    }

    v<unordered_set<int>> g(n);
    pii p;
    rep(i,m) {
        cin >> p;
        p.f--,p.s--;
        g[p.f].insert(p.s);
        g[p.s].insert(p.f);
    }
    int pos=0,next;
    if (g[0].size()==0) {
        YesNo(0);
        return 0;
    }

    g[0].erase(g[0].begin());
    rep(i,n-1) {
        if (g[pos].size()==0) {
            YesNo(0);
            return 0;
        }
        next=*g[pos].begin();
        if (g[next].size()!=2) {
            YesNo(0);
            return 0;
        }
        g[next].erase(pos);
        pos=next;
    }
    YesNo(g[pos].size()&&*g[pos].begin()==0);

    return 0;
}
