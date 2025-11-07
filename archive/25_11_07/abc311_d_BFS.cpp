// https://atcoder.jp/contests/abc311/tasks/abc311_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    v<string> s(n);
    cin >> s;
    vvi row(n),col(m);
    rep(i,n)rep(j,m) {
        if (s[i][j]=='#') row[i].pb(j);
    }
    rep(j,m)rep(i,n) {
        if (s[i][j]=='#') col[j].pb(i);
    }

    vvi b(n,vi(m,0));
    queue<pii> q;
    pii start={1,1};
    q.push(start);
    while (!q.empty()) {
        auto[x,y]=q.front();
        q.pop();
        if (b[x][y]==2) continue;
        b[x][y]=2;

        auto itr=upper_bound(all(row[x]),y);
        int r=*itr-1;
        for (int j=y+1; j<r; ++j) chmax(b[x][j],1);
        q.push({x,r});

        auto itl=lower_bound(all(row[x]),y);
        --itl;
        int l=*itl+1;
        for (int j=y-1; j>l; --j) chmax(b[x][j],1);
        q.push({x,l});

        auto itd=upper_bound(all(col[y]),x);
        int d=*itd-1;
        for (int i=x+1; i<d; ++i) chmax(b[i][y],1);
        q.push({d,y});

        auto itu=lower_bound(all(col[y]),x);
        --itu;
        int u=*itu+1;
        for (int i=x-1; i>u; --i) chmax(b[i][y],1);
        q.push({u,y});
    }
    int ans=0;
    rep(i,n)rep(j,m) ans+=(b[i][j]>0);
    print(ans);

    return 0;
}
