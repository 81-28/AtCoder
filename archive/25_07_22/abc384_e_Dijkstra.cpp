// https://atcoder.jp/contests/abc384/tasks/abc384_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
const pii dir[4]={{-1,0},{0,-1},{1,0},{0,1}};
#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define f first
#define s second
// pairの足し算
template<typename F,typename S>
pair<F,S> operator+(const pair<F,S>& a,const pair<F,S>& b){return{a.f+b.f,a.s+b.s};}
// pairのデクリメント
template<typename F,typename S>
pair<F,S>& operator--(pair<F,S>& p){--p.f;--p.s;return p;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w,r;
    pii p;
    cin >> h >> w >> r >> p;
    --p;
    vvi a(h,vi(w));
    cin >> a;
    v<v<bool>> b(h,v<bool>(w,0));
    // {強さ,位置}
    priority_queue<tuple<int,pii>,v<tuple<int,pii>>,greater<>> q;
    q.push({0,p});
    int ans=a[p.f][p.s];
    while (!q.empty()) {
        auto[sz,pp]=q.top();
        q.pop();
        auto[x,y]=pp;
        if (b[x][y]==1) continue;
        if (sz>=(ans+r-1)/r) break;
        b[x][y]=1;
        ans+=sz;
        rep(k,4) {
            pii nxt=pp+dir[k];
            auto[i,j]=nxt;
            if (0<=i&&i<h&&0<=j&&j<w) q.push({a[i][j],nxt});
        }
    }
    print(ans);

    return 0;
}
