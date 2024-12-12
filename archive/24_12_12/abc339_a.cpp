// https://atcoder.jp/contests/abc339/tasks/abc339_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define f first
#define s second
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w,n;
    cin >> h >> w >> n;
    vvi g(h,vi(w,0));
    pii u={-1,0},d={1,0},l={0,-1},r={0,1};
    pii dir = u;
    pii p = {0,0};
    rep(k,n) {
        if(g[p.f][p.s]) {
            if(dir==u) dir=l;
            else if(dir==l) dir=d;
            else if(dir==d) dir=r;
            else if(dir==r) dir=u;
        } else {
            if(dir==u) dir=r;
            else if(dir==r) dir=d;
            else if(dir==d) dir=l;
            else if(dir==l) dir=u;
        }
        g[p.f][p.s]^=1;
        p.f+=dir.f,p.s+=dir.s;
        p.f+=h,p.f%=h,p.s+=w,p.s%=w;
    }
    rep(i,h) {
        rep(j,w) {
            if(g[i][j]) cout<<'#';
            else cout<<'.';
        }
        cout<<'\n';
    }

    return 0;
}
