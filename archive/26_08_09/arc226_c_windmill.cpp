// https://atcoder.jp/contests/arc226/tasks/arc226_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


v<tuple<int,int,int>> ans;
void solve(int h,int w,int x,int y) {
    if (h<2 && w<2) return;
    if (h!=w) {
        if (h>w) {
            for (int i=w+1; i<=h; i+=2) {
                rep(j,w/2) ans.pb({i,j*2+1,1});
            }
        } else {
            for (int j=h+1; j<=w; j+=2) {
                rep(i,h/2) ans.pb({i*2+1,j,1});
            }
        }
    }
    int n=min(h,w);
    ans.pb({x+1,y+1,n-1});
    for (int j=2; j<n-1; j+=2) ans.pb({x+1,y+j,1});
    for (int i=2; i<n-1; i+=2) ans.pb({x+i,y+n-1,1});
    for (int j=n-2; j>1; j-=2) ans.pb({x+n-1,y+j,1});
    for (int i=n-2; i>1; i-=2) ans.pb({x+i,y+1,1});
    solve(n-4,n-4,x+2,y+2);
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int h,w;
        cin >> h >> w;
        if (h&1 && w&1) {
            ans.clear();
            solve(h,w,0,0);
            print(ans.size());
            for (auto[r,c,s]:ans) print(r,c,s);
        } else {
            h/=2,w/=2;
            print(h*w);
            rep(i,h)rep(j,w) print(i*2+1,j*2+1,1);
        }
    }

    return 0;
}
