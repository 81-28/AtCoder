// https://atcoder.jp/contests/abc466/tasks/abc466_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n,m;
    cin >> n >> m;
    vi r(n,-1),c(n,-1);
    int ans=0;
    rep(i,m) {
        int x,y;
        cin >> x >> y;
        --x,--y;
        if (r[x]!=-1) {
            c[r[x]]=-1;
            --ans;
        }
        r[x]=y;
        if (c[y]!=-1) {
            r[c[y]]=-1;
            --ans;
        }
        c[y]=x;
        ++ans;
    }
    print(ans);

    return 0;
}
